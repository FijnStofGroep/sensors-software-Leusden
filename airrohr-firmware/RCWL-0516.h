/*!
 * @file RCWL-0516.h
 *
 * Written by Roel, Rolenco Leusden
 *
 * BSD license, all text here must be included in any redistribution.
 * See the LICENSE file for details.
 *
 */


#ifndef __RCWL_0516_H__
#define __RCWL_0516_H__

// VS: Convert Arduino file to C++ manually.
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "./Queue.h"

class RCWL_0516
{

public:
  // Set GPIO no. Radar Motion Sensor.
  //                        // comment: pinNo D8 => MCU DON'T start-UP.
  int MotionSensorID = D7;  // Radar data out. => the pin D7 = 13 that the sensor is attached to.

  // Auxiliary variables
  int m_motionState;          // by default, no motion detected

  Queue* m_queue = NULL;

  /*
    constructor
  */
  RCWL_0516()
  {
    m_motionState = LOW;
    this->mqtt_client = nullptr;
    mqtt_header[0] = 0x00;
    lastTriggerEvent = millis();
  };

  /*
    destructor => Clean-up all resource.
  */
  ~RCWL_0516()
  {
    if( m_queue != NULL)
    {
      delete m_queue;         // destructor will get called here, after which it's memory is freed => remove m_queue from heap memory.
      m_queue = NULL;
    }
  };

  //public function methods
  bool init(unsigned int m_Wait_max_time, int motionSensorID = D7);             // default: pin D7(13) that the radar sensor is attached to.
  bool begin(const char *serverHost, uint port);
  bool setMQTTClient(PubSubClient& mqttclient, String _header, String _lwt_header);
  
  void loop(void);
  void end(void);                                 // end/stop motion Event process.
  unsigned long GetMotionCount();

private:
  const int LEDHIGH = LOW;
  const int LEDLOW = HIGH;
  unsigned long m_timeSeconds = 30 * 1000;        // WaitTime in seconds. Every 30 sec. retry to connect to Server.

 // Set GPIO no. for LED indicator.
  int MotionLedID = LED_BUILTIN;                    // blue LED on board

// Timer: Auxiliary variables
  unsigned long currentTrigger = 0;
  unsigned long lastTriggerEvent = 0;
  unsigned long count_RadarMotion = 0;

  unsigned long m_currentwaitTime = 0;
  unsigned long m_startTriggerEvent = 0;
  unsigned long m_Wait_until_max_time_provided = 0; // Wait until max time provided. (in sec.)

  bool m_Active = false;
  char m_serverHost[25] = "192.168.2.105";          // server has static IPAdres.
  uint m_port = 0;                                  // -1 = No communcation, 8080 default port nr.

  #define LEN_MQTT_LARGE_HEADER 90
  char mqtt_header[LEN_MQTT_LARGE_HEADER];
  char mqtt_lwt_header[LEN_MQTT_LARGE_HEADER];
  PubSubClient *mqtt_client;

  // private function methods
  void sendMotionValue(int motionValue);
  void SendToServer(int motionValue, time_t motionTimeStamp);
  void sendMQTT(int motionValue, time_t motionTimeStamp);

};

// external declaration of RCWL0516 instances.
const char INTL_LWT_ONLINE[] PROGMEM = "Online";

extern RCWL_0516 RCWL0516;

#endif
