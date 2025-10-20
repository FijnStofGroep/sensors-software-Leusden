#!/usr/bin/env python3

configshape_in = """

String		current_lang
String		wlanssid
Password	wlanpwd
String		wlanssid_2
Password	wlanpwd_2
String		wlanssid_3
Password	wlanpwd_3
String		www_username
Password	www_password
String		fs_ssid
Password	fs_pwd
Bool		www_basicauth_enabled
Bool		dht_read
Bool		htu21d_read
Bool		ppd_read
Bool		sds_read
Bool		pms_read
Bool		hpm_read
Bool		npm_read
Bool        npm_fulltime
UInt        npm_heater_mode
Bool		ips_read
Bool		sen5x_read
Bool		sen5x_on
String		sen5x_sym_pm
String		sen5x_sym_th
Bool		sen5x_pin16
Bool		sps30_read
Bool		bmp_read
Bool		bmx280_read
Bool		sht3x_read
Bool		scd30_read
Bool		ds18b20_read
Bool		dnms_read
String		dnms_correction
String		temp_correction
String		height_above_sealevel
Bool		gps_read
Bool		send2dusti
Bool		ssl_dusti
Bool		send2madavi
Bool		ssl_madavi
Bool		send2sensemap
Bool		send2fsapp
Bool		send2aircms
Bool		send2csv
Bool		auto_update
Bool		use_beta
Bool		has_display
Bool		has_sh1106
Bool		has_flipped_display
Bool		has_lcd1602
Bool		has_lcd1602_27
Bool		has_lcd2004
Bool		has_lcd2004_27
Bool		display_wifi_info
Bool		display_device_info
String		static_ip
String		static_subnet
String		static_gateway
String		static_dns
UInt		debug
Time		sending_intervall_ms
Time		time_for_wifi_config
Bool		powersave
String		senseboxid
Bool		send2custom
String		host_custom
String		url_custom
UInt		port_custom
String		user_custom
Password	pwd_custom
Bool		ssl_custom
Bool		send2influx
String		host_influx
String		url_influx
UInt		port_influx
String		user_influx
Password	pwd_influx
Bool		send2mqtt
String		mqtt_server
UInt		mqtt_port
String		mqtt_user
Password	mqtt_pwd
String		mqtt_topic
String		measurement_name_influx
Bool		ssl_influx
Bool		has_fix_ip
String		scd30_co2_correction
String		scd30_temp_correction
String		host_radar
UInt		port_radar
UInt		motion_wait_time
String		user_radar
Password	pwd_radar
Bool        has_radarmotion
Bool        has_morewifi

"""

with open("airrohr-cfg.h", "w") as h:
    print("""

// This file is generated, please do not edit.
// Change airrohr-cfg.h.py instead.
// update: 29 juli 2023
// add Bool Fix IP
// update: 28 December 2023
// add more settings
//
// run python airrohr-cfg.h.py
//

#ifndef __airrohr_cfg_h
#define __airrohr_cfg_h
          
enum ConfigEntryType : unsigned short {
	Config_Type_Bool,
	Config_Type_UInt,
	Config_Type_Time,
	Config_Type_String,
	Config_Type_Password
};

struct ConfigShapeEntry {
	enum ConfigEntryType cfg_type;
	unsigned short cfg_len;
	const char* _cfg_key;
          
	union {
		void* as_void;
		bool* as_bool;
		unsigned int* as_uint;
		char* as_str;
	} cfg_val;
          
	const __FlashStringHelper* cfg_key() const { return FPSTR(_cfg_key); }
};

enum ConfigShapeId {""", file=h )

    for cfgentry in configshape_in.strip().split('\n'):
        if(len(cfgentry) > 2):      # checking if string is empty line (only LF/CR char.)
            print("\tConfig_", cfgentry.split()[1], ",", sep='', file=h )
    
    print("};\n", file=h)

    for cfgentry in configshape_in.strip().split('\n'):
        if(len(cfgentry) > 2):
            _, cfgkey = cfgentry.split()
            print("static constexpr char CFG_KEY_", cfgkey.upper(),
                "[] PROGMEM = \"", cfgkey, "\";", sep='', file=h)

    print("\nstatic constexpr ConfigShapeEntry configShape[] PROGMEM = {", file=h )
    
    for cfgentry in configshape_in.strip().split('\n'):
        if(len(cfgentry) > 2):
            cfgtype, cfgkey = cfgentry.split()
            print("\t{ Config_Type_", cfgtype,
                ", sizeof(cfg::" + cfgkey + ")-1" if cfgtype in ('String', 'Password') else ", 0",
                ", CFG_KEY_", cfgkey.upper(),
                ", ", "" if cfgtype in ('String', 'Password') else "&",
                "cfg::", cfgkey, " },", sep='', file=h)
        
    print("};", file=h)

    print("\n#endif\n", file=h)
