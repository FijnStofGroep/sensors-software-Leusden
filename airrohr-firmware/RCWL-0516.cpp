/*
 * @file RCWL-0516.cpp
 *
 * Written by R.Dieperink, Rolenco Leusden
 * Date: 2023-11-13
 * 
 * RCWL-0516 Microwave Radar Motion Sensor.
 *
*/

#include "RCWL-0516.h"
#include "./utils.h"

RCWL_0516 RCWL0516; // Create RCWL_0516 instance on Stack.

/*
 *
 * MotionSensorChangeEvent() => ISRs should be as short and fast as possible as they block normal program execution.
 *
 */
ICACHE_RAM_ATTR void MotionSensorChangeEvent()
{
  int motionValue = digitalRead(RCWL0516.MotionSensorID); // read Radar sensor value.

  RCWL0516.m_queue->Enqueue(motionValue);

#if VS_DEBUG
  debug_outln_info(F("MotionSensorChangeEvent()::Radar Motion/Sensor value: "), String(motionValue));
#endif
}

//**********************************************************************************************************************************
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

/*
    Init RCWL_0516 Instance.

    Wait_max_time in sec.
*/
bool RCWL_0516::init(unsigned Wait_max_time, int motionSensorID)
{
  MotionSensorID = motionSensorID;

  // send motion value only if this time has pased.
  // start on high signal and end on low signal.
  m_Wait_until_max_time_provided = Wait_max_time * 1000;

   pinMode(MotionSensorID, INPUT);
  // Radar Motion Sensor signal mode INPUT_PULLUP => is more stabale signal.
  //pinMode(MotionSensorID, INPUT_PULLUP);

  // Create a Queue[] array of 10 radar events could be stored on the heap.
  m_queue = new Queue(10);

#if VS_DEBUG
  debug_outln_info(F("init()::Radar Motion/Sensor, Wait Time: "), String(Wait_max_time));
#endif

  return true;
}

/******************************************************************
 *                                                                *
 ******************************************************************/
bool RCWL_0516::begin(const char *serverHost, uint port)
{
  strcpy(m_serverHost, serverHost); // m_serverHost = serverHost;
  m_port = port;
  m_Active = true;

  // Check connection to Server.
  //WiFiClient client;

  // if (!client.connect(m_serverHost, m_port))
  // {
  //   lastTrigger = millis() - m_timeSeconds;
  //   m_Active = false;
  // }

  // client.stop();

  /*
      Set MotionSensor pin as interrupt, assign interrupt function and set "CHANGE" mode
      only one interrupt event could be set.
      first => detachInterrupt(digitalPinToInterrupt(MotionSensorID));
      then attachInterrupt(digitalPinToInterrupt, Mode)

   * Mode – defines when the interrupt should be triggered. Five constants are predefined as valid values:
      LOW     Triggers the interrupt whenever the pin is LOW
      HIGH    Triggers the interrupt whenever the pin is HIGH
      CHANGE  Triggers the interrupt whenever the pin changes value, from HIGH to LOW or LOW to HIGH
      FALLING Triggers the interrupt when the pin goes from HIGH to LOW
      RISING  Triggers the interrupt when the pin goes from LOW to HIGH
   *
   */

  attachInterrupt(digitalPinToInterrupt(MotionSensorID), MotionSensorChangeEvent, CHANGE);

  // digitalWrite(led, LEDLOW);

  
#if VS_DEBUG
  debug_outln_info(F("begin()::Radar Motion/Sensor, serverHost: "), String(serverHost));
#endif

  return m_Active;
}

/*
 *
 *
*/
bool RCWL_0516::setMQTTClient(PubSubClient& mqttclient, String _header, String _lwt_header)
{
  this->mqtt_client = &mqttclient;

		// ++ Set-Up Topic header for MQTT Broker
		if( _header.length() <= LEN_MQTT_LARGE_HEADER)
		{
			strcpy(mqtt_header, _header.c_str());
		}

    if( _lwt_header.length() <= LEN_MQTT_LARGE_HEADER)
		{
			strcpy(mqtt_lwt_header, _lwt_header.c_str());
		}

  return true;
}


#pragma GCC diagnostic pop

/*
 * Radar Motion - Message loop()
 *  - Called every 100 msec.
 */
void RCWL_0516::loop()
{
  if (RCWL0516.m_queue != NULL && !RCWL0516.m_queue->IsEmpty())
  {
    int motionValue = RCWL0516.m_queue->Dequeue();

#if VS_DEBUG
    debug_outln_info(F("loop()::Radar Motion-Sensor value: "), String(motionValue));
#endif

    if (m_Wait_until_max_time_provided == 0)
    { // send all motion value to a external device.
      if (motionValue == HIGH)
      { // update variable state to HIGH.
          m_motionState++;
          m_startTriggerEvent = millis();         // set start time value.
          m_currentwaitTime = 0;
      }
      else if (m_motionState == LOW)
      {
        return;
      }
      else
      { // update variable state to LOW.
        m_motionState--;
        m_currentwaitTime = millis() - m_startTriggerEvent;
      }

      sendMotionValue(motionValue);
    }
    else
    {
      if (motionValue == HIGH)
      { // sensor is HIGH => radar motion detected it.
        if (m_motionState == LOW)
        {
          m_startTriggerEvent = millis();         // set start time value.
          m_motionState = HIGH;                   // update variable state to HIGH

          debug_outln_verbose( F("Set wait time = "), String( (m_startTriggerEvent / 1000) % 60) + F(" sec."));
         }
      }
      else
      {// sensor is LOW => radar motion detection ended.
        if (m_motionState == HIGH)
        {
          m_currentwaitTime = millis() - m_startTriggerEvent;

          if (m_currentwaitTime >= m_Wait_until_max_time_provided)
          { // Inform external application there is active motion detected.
            sendMotionValue( 2 );
            m_motionState = LOW; // update variable state to LOW.
            m_startTriggerEvent = 0;

            debug_outln_verbose( F("End, wait time = "), String( m_currentwaitTime / 1000) + F(" sec."));
          }
          else
          {// to short time window => restart.
            m_motionState = LOW; // update variable state to LOW.
            m_startTriggerEvent = 0;

            debug_outln_verbose( F("No action, to short wait time = "), String( m_currentwaitTime / 1000) + F(" sec."));
          }
        }
      }
    }
  }
}

/*
    Stop Radar motion detection Event process.
*/
void RCWL_0516::end(void)
{
  detachInterrupt(digitalPinToInterrupt(MotionSensorID));
}

/*
  Get MotionCount
*/
unsigned long RCWL_0516::GetMotionCount()
{
  return count_RadarMotion;
}

//*************************************************************************************************************************************
/*
 * Send Radar motion to outside world.
 *  Input:
 *         motionValue: 0 => signal down.(end detect motion)
 *                      1 => signal up.  (begin detect motion)
 *                      2 => one motion cycle.
 *
*/
void RCWL_0516::sendMotionValue(int motionValue)
{
      time_t motionTimeStamp = time(nullptr);       // Get time stamp.

      // Send Radar value to Server.
      SendToServer(motionValue, motionTimeStamp);

      // Send Radar value to MQTT broker.
      sendMQTT(motionValue, motionTimeStamp);

      count_RadarMotion++;
}

/// @brief 
///
///  Send Radar motion value To a web-Server.
///
/// @param val 
/// @param now => current time value.
void RCWL_0516::SendToServer(int motionValue, time_t motionTimeStamp)
{
  if(m_port == 0)
  {// No communication with a external Server.
    return;
  }

  char time_buffer[10] = {0};
  struct tm *timeinfo;
  timeinfo = localtime(&motionTimeStamp);

  strftime(time_buffer, 10, "%H:%M:%S", timeinfo);
  String message = String(F("Time:")) + String(time_buffer) +  F(",Attention Time:") + String(m_currentwaitTime / 1000) + String(F(",Radar Motion value:")) + String(motionValue);
  debug_outln_verbose(F("SendToServer(), "), message);

  if (!m_Active)
  {
    // Current time.
    currentTrigger = millis();

    if ((currentTrigger - lastTriggerEvent) < m_timeSeconds)
    {
      debug_outln_verbose(F("Wait for retry connect to Server = "), String((currentTrigger - lastTriggerEvent) / 1000) + F(" sec."));
      return;
    }

    m_Active = true;
  }

  WiFiClient client;

  debug_outln_verbose(F("connecting to "), String(m_serverHost) + F(":") + String(m_port));

  if (!client.connect(m_serverHost, m_port))
  {
    // Serial.println("connection failed");
    debug_outln_verbose(F("Connection failed to Server = "), String(m_serverHost));

    lastTriggerEvent = millis();
    m_Active = false;
    return;
  }

  if (client.connected())
  {
    // debug_outln_verbose(F("[Sending a request] => Radar Motion Value: "), String(val));
 
    // Send rader value to external Server.
    //String message = String(F("Date:")) + String(time_buffer) + String(F(",Radar Value:")) + String(val);
    client.print( message);
    client.stop();                      // clean-up client resouces.

    // debug_outln_verbose(F("[Sending a request] => ENDED: "));
  }
  else
  {
    debug_outln_verbose(F("Could Not connect to Server = "), String(m_serverHost));
  }
}

/*****************************************************************
* send radar motion value to mqtt api                            *
*                                                                *
*****************************************************************/
void RCWL_0516::sendMQTT(int motionValue, time_t motionTimeStamp)
{
	if ( this->mqtt_client != nullptr && this->mqtt_client->connected() )
	{
      char time_buffer[10] = {0};
      char date_buffer[13] = {0};
      struct tm *timeinfo;
      timeinfo = localtime(&motionTimeStamp);
      strftime(time_buffer, 10, "%H:%M:%S", timeinfo);
      strftime(date_buffer, 12, "%Y-%m-%d", timeinfo);

      String status_header, payload_messages;
      status_header = mqtt_header;
			status_header += "/radar";

      debug_outln_verbose(F("- Radar topic = "), status_header);

			payload_messages = "{\"";
      payload_messages += F("Date");
			payload_messages += "\":\"";
      payload_messages += String(date_buffer);
			payload_messages += "\",\"";                          // field seperator char.
      payload_messages += F("Time");
			payload_messages += "\":\"";
      payload_messages += String(time_buffer);
			payload_messages += "\",\"";                          // field seperator char.
      payload_messages += F("Attention Time");
			payload_messages += "\":\"";
      payload_messages += String(m_currentwaitTime / 1000);
			payload_messages += "\",\"";                          // field seperator char.
			payload_messages += F("Value");
			payload_messages += "\":\"";
			payload_messages += String(motionValue);             // String( val == 2 ? 1 : motionValue);
      payload_messages += "\"}";

			if( this->mqtt_client->publish( status_header.c_str(), payload_messages.c_str()))
			{
			  debug_outln_verbose(F("- LWT topic = "), mqtt_lwt_header);
			  String payload_mess_on = INTL_LWT_ONLINE;
			  this->mqtt_client->publish(mqtt_lwt_header, payload_mess_on.c_str());

        this->mqtt_client->loop();

        //this->mqtt_client->flush();
        debug_outln_verbose(F("- Radar payload = "), payload_messages);
				debug_outln_verbose(F("Radar send ok..."));
			}
			else
			{
        debug_outln_verbose(F("Radar send failed, rc= "), String(mqtt_client->state()));
			}
	}
  else
  {
    if( this->mqtt_client == nullptr )
    {
      debug_outln_verbose(F("** No MQTT instance created **"));
    }
    else
    {
      debug_outln_verbose(F("** MQTT Broker NOT connected **"));
    }
  }

  return;
}
