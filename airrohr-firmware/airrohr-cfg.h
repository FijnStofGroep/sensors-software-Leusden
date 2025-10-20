

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

enum ConfigShapeId {
	Config_current_lang,
	Config_wlanssid,
	Config_wlanpwd,
	Config_wlanssid_2,
	Config_wlanpwd_2,
	Config_wlanssid_3,
	Config_wlanpwd_3,
	Config_www_username,
	Config_www_password,
	Config_fs_ssid,
	Config_fs_pwd,
	Config_www_basicauth_enabled,
	Config_dht_read,
	Config_htu21d_read,
	Config_ppd_read,
	Config_sds_read,
	Config_pms_read,
	Config_hpm_read,
	Config_npm_read,
	Config_npm_fulltime,
	Config_npm_heater_mode,
	Config_ips_read,
	Config_sen5x_read,
	Config_sen5x_on,
	Config_sen5x_sym_pm,
	Config_sen5x_sym_th,
	Config_sen5x_pin16,
	Config_sps30_read,
	Config_bmp_read,
	Config_bmx280_read,
	Config_sht3x_read,
	Config_scd30_read,
	Config_ds18b20_read,
	Config_dnms_read,
	Config_dnms_correction,
	Config_temp_correction,
	Config_height_above_sealevel,
	Config_gps_read,
	Config_send2dusti,
	Config_ssl_dusti,
	Config_send2madavi,
	Config_ssl_madavi,
	Config_send2sensemap,
	Config_send2fsapp,
	Config_send2aircms,
	Config_send2csv,
	Config_auto_update,
	Config_use_beta,
	Config_has_display,
	Config_has_sh1106,
	Config_has_flipped_display,
	Config_has_lcd1602,
	Config_has_lcd1602_27,
	Config_has_lcd2004,
	Config_has_lcd2004_27,
	Config_display_wifi_info,
	Config_display_device_info,
	Config_static_ip,
	Config_static_subnet,
	Config_static_gateway,
	Config_static_dns,
	Config_debug,
	Config_sending_intervall_ms,
	Config_time_for_wifi_config,
	Config_powersave,
	Config_senseboxid,
	Config_send2custom,
	Config_host_custom,
	Config_url_custom,
	Config_port_custom,
	Config_user_custom,
	Config_pwd_custom,
	Config_ssl_custom,
	Config_send2influx,
	Config_host_influx,
	Config_url_influx,
	Config_port_influx,
	Config_user_influx,
	Config_pwd_influx,
	Config_send2mqtt,
	Config_mqtt_server,
	Config_mqtt_port,
	Config_mqtt_user,
	Config_mqtt_pwd,
	Config_mqtt_topic,
	Config_measurement_name_influx,
	Config_ssl_influx,
	Config_has_fix_ip,
	Config_scd30_co2_correction,
	Config_scd30_temp_correction,
	Config_host_radar,
	Config_port_radar,
	Config_motion_wait_time,
	Config_user_radar,
	Config_pwd_radar,
	Config_has_radarmotion,
	Config_has_morewifi,
};

static constexpr char CFG_KEY_CURRENT_LANG[] PROGMEM = "current_lang";
static constexpr char CFG_KEY_WLANSSID[] PROGMEM = "wlanssid";
static constexpr char CFG_KEY_WLANPWD[] PROGMEM = "wlanpwd";
static constexpr char CFG_KEY_WLANSSID_2[] PROGMEM = "wlanssid_2";
static constexpr char CFG_KEY_WLANPWD_2[] PROGMEM = "wlanpwd_2";
static constexpr char CFG_KEY_WLANSSID_3[] PROGMEM = "wlanssid_3";
static constexpr char CFG_KEY_WLANPWD_3[] PROGMEM = "wlanpwd_3";
static constexpr char CFG_KEY_WWW_USERNAME[] PROGMEM = "www_username";
static constexpr char CFG_KEY_WWW_PASSWORD[] PROGMEM = "www_password";
static constexpr char CFG_KEY_FS_SSID[] PROGMEM = "fs_ssid";
static constexpr char CFG_KEY_FS_PWD[] PROGMEM = "fs_pwd";
static constexpr char CFG_KEY_WWW_BASICAUTH_ENABLED[] PROGMEM = "www_basicauth_enabled";
static constexpr char CFG_KEY_DHT_READ[] PROGMEM = "dht_read";
static constexpr char CFG_KEY_HTU21D_READ[] PROGMEM = "htu21d_read";
static constexpr char CFG_KEY_PPD_READ[] PROGMEM = "ppd_read";
static constexpr char CFG_KEY_SDS_READ[] PROGMEM = "sds_read";
static constexpr char CFG_KEY_PMS_READ[] PROGMEM = "pms_read";
static constexpr char CFG_KEY_HPM_READ[] PROGMEM = "hpm_read";
static constexpr char CFG_KEY_NPM_READ[] PROGMEM = "npm_read";
static constexpr char CFG_KEY_NPM_FULLTIME[] PROGMEM = "npm_fulltime";
static constexpr char CFG_KEY_NPM_HEATER_MODE[] PROGMEM = "npm_heater_mode";
static constexpr char CFG_KEY_IPS_READ[] PROGMEM = "ips_read";
static constexpr char CFG_KEY_SEN5X_READ[] PROGMEM = "sen5x_read";
static constexpr char CFG_KEY_SEN5X_ON[] PROGMEM = "sen5x_on";
static constexpr char CFG_KEY_SEN5X_SYM_PM[] PROGMEM = "sen5x_sym_pm";
static constexpr char CFG_KEY_SEN5X_SYM_TH[] PROGMEM = "sen5x_sym_th";
static constexpr char CFG_KEY_SEN5X_PIN16[] PROGMEM = "sen5x_pin16";
static constexpr char CFG_KEY_SPS30_READ[] PROGMEM = "sps30_read";
static constexpr char CFG_KEY_BMP_READ[] PROGMEM = "bmp_read";
static constexpr char CFG_KEY_BMX280_READ[] PROGMEM = "bmx280_read";
static constexpr char CFG_KEY_SHT3X_READ[] PROGMEM = "sht3x_read";
static constexpr char CFG_KEY_SCD30_READ[] PROGMEM = "scd30_read";
static constexpr char CFG_KEY_DS18B20_READ[] PROGMEM = "ds18b20_read";
static constexpr char CFG_KEY_DNMS_READ[] PROGMEM = "dnms_read";
static constexpr char CFG_KEY_DNMS_CORRECTION[] PROGMEM = "dnms_correction";
static constexpr char CFG_KEY_TEMP_CORRECTION[] PROGMEM = "temp_correction";
static constexpr char CFG_KEY_HEIGHT_ABOVE_SEALEVEL[] PROGMEM = "height_above_sealevel";
static constexpr char CFG_KEY_GPS_READ[] PROGMEM = "gps_read";
static constexpr char CFG_KEY_SEND2DUSTI[] PROGMEM = "send2dusti";
static constexpr char CFG_KEY_SSL_DUSTI[] PROGMEM = "ssl_dusti";
static constexpr char CFG_KEY_SEND2MADAVI[] PROGMEM = "send2madavi";
static constexpr char CFG_KEY_SSL_MADAVI[] PROGMEM = "ssl_madavi";
static constexpr char CFG_KEY_SEND2SENSEMAP[] PROGMEM = "send2sensemap";
static constexpr char CFG_KEY_SEND2FSAPP[] PROGMEM = "send2fsapp";
static constexpr char CFG_KEY_SEND2AIRCMS[] PROGMEM = "send2aircms";
static constexpr char CFG_KEY_SEND2CSV[] PROGMEM = "send2csv";
static constexpr char CFG_KEY_AUTO_UPDATE[] PROGMEM = "auto_update";
static constexpr char CFG_KEY_USE_BETA[] PROGMEM = "use_beta";
static constexpr char CFG_KEY_HAS_DISPLAY[] PROGMEM = "has_display";
static constexpr char CFG_KEY_HAS_SH1106[] PROGMEM = "has_sh1106";
static constexpr char CFG_KEY_HAS_FLIPPED_DISPLAY[] PROGMEM = "has_flipped_display";
static constexpr char CFG_KEY_HAS_LCD1602[] PROGMEM = "has_lcd1602";
static constexpr char CFG_KEY_HAS_LCD1602_27[] PROGMEM = "has_lcd1602_27";
static constexpr char CFG_KEY_HAS_LCD2004[] PROGMEM = "has_lcd2004";
static constexpr char CFG_KEY_HAS_LCD2004_27[] PROGMEM = "has_lcd2004_27";
static constexpr char CFG_KEY_DISPLAY_WIFI_INFO[] PROGMEM = "display_wifi_info";
static constexpr char CFG_KEY_DISPLAY_DEVICE_INFO[] PROGMEM = "display_device_info";
static constexpr char CFG_KEY_STATIC_IP[] PROGMEM = "static_ip";
static constexpr char CFG_KEY_STATIC_SUBNET[] PROGMEM = "static_subnet";
static constexpr char CFG_KEY_STATIC_GATEWAY[] PROGMEM = "static_gateway";
static constexpr char CFG_KEY_STATIC_DNS[] PROGMEM = "static_dns";
static constexpr char CFG_KEY_DEBUG[] PROGMEM = "debug";
static constexpr char CFG_KEY_SENDING_INTERVALL_MS[] PROGMEM = "sending_intervall_ms";
static constexpr char CFG_KEY_TIME_FOR_WIFI_CONFIG[] PROGMEM = "time_for_wifi_config";
static constexpr char CFG_KEY_POWERSAVE[] PROGMEM = "powersave";
static constexpr char CFG_KEY_SENSEBOXID[] PROGMEM = "senseboxid";
static constexpr char CFG_KEY_SEND2CUSTOM[] PROGMEM = "send2custom";
static constexpr char CFG_KEY_HOST_CUSTOM[] PROGMEM = "host_custom";
static constexpr char CFG_KEY_URL_CUSTOM[] PROGMEM = "url_custom";
static constexpr char CFG_KEY_PORT_CUSTOM[] PROGMEM = "port_custom";
static constexpr char CFG_KEY_USER_CUSTOM[] PROGMEM = "user_custom";
static constexpr char CFG_KEY_PWD_CUSTOM[] PROGMEM = "pwd_custom";
static constexpr char CFG_KEY_SSL_CUSTOM[] PROGMEM = "ssl_custom";
static constexpr char CFG_KEY_SEND2INFLUX[] PROGMEM = "send2influx";
static constexpr char CFG_KEY_HOST_INFLUX[] PROGMEM = "host_influx";
static constexpr char CFG_KEY_URL_INFLUX[] PROGMEM = "url_influx";
static constexpr char CFG_KEY_PORT_INFLUX[] PROGMEM = "port_influx";
static constexpr char CFG_KEY_USER_INFLUX[] PROGMEM = "user_influx";
static constexpr char CFG_KEY_PWD_INFLUX[] PROGMEM = "pwd_influx";
static constexpr char CFG_KEY_SEND2MQTT[] PROGMEM = "send2mqtt";
static constexpr char CFG_KEY_MQTT_SERVER[] PROGMEM = "mqtt_server";
static constexpr char CFG_KEY_MQTT_PORT[] PROGMEM = "mqtt_port";
static constexpr char CFG_KEY_MQTT_USER[] PROGMEM = "mqtt_user";
static constexpr char CFG_KEY_MQTT_PWD[] PROGMEM = "mqtt_pwd";
static constexpr char CFG_KEY_MQTT_TOPIC[] PROGMEM = "mqtt_topic";
static constexpr char CFG_KEY_MEASUREMENT_NAME_INFLUX[] PROGMEM = "measurement_name_influx";
static constexpr char CFG_KEY_SSL_INFLUX[] PROGMEM = "ssl_influx";
static constexpr char CFG_KEY_HAS_FIX_IP[] PROGMEM = "has_fix_ip";
static constexpr char CFG_KEY_SCD30_CO2_CORRECTION[] PROGMEM = "scd30_co2_correction";
static constexpr char CFG_KEY_SCD30_TEMP_CORRECTION[] PROGMEM = "scd30_temp_correction";
static constexpr char CFG_KEY_HOST_RADAR[] PROGMEM = "host_radar";
static constexpr char CFG_KEY_PORT_RADAR[] PROGMEM = "port_radar";
static constexpr char CFG_KEY_MOTION_WAIT_TIME[] PROGMEM = "motion_wait_time";
static constexpr char CFG_KEY_USER_RADAR[] PROGMEM = "user_radar";
static constexpr char CFG_KEY_PWD_RADAR[] PROGMEM = "pwd_radar";
static constexpr char CFG_KEY_HAS_RADARMOTION[] PROGMEM = "has_radarmotion";
static constexpr char CFG_KEY_HAS_MOREWIFI[] PROGMEM = "has_morewifi";

static constexpr ConfigShapeEntry configShape[] PROGMEM = {
	{ Config_Type_String, sizeof(cfg::current_lang)-1, CFG_KEY_CURRENT_LANG, cfg::current_lang },
	{ Config_Type_String, sizeof(cfg::wlanssid)-1, CFG_KEY_WLANSSID, cfg::wlanssid },
	{ Config_Type_Password, sizeof(cfg::wlanpwd)-1, CFG_KEY_WLANPWD, cfg::wlanpwd },
	{ Config_Type_String, sizeof(cfg::wlanssid_2)-1, CFG_KEY_WLANSSID_2, cfg::wlanssid_2 },
	{ Config_Type_Password, sizeof(cfg::wlanpwd_2)-1, CFG_KEY_WLANPWD_2, cfg::wlanpwd_2 },
	{ Config_Type_String, sizeof(cfg::wlanssid_3)-1, CFG_KEY_WLANSSID_3, cfg::wlanssid_3 },
	{ Config_Type_Password, sizeof(cfg::wlanpwd_3)-1, CFG_KEY_WLANPWD_3, cfg::wlanpwd_3 },
	{ Config_Type_String, sizeof(cfg::www_username)-1, CFG_KEY_WWW_USERNAME, cfg::www_username },
	{ Config_Type_Password, sizeof(cfg::www_password)-1, CFG_KEY_WWW_PASSWORD, cfg::www_password },
	{ Config_Type_String, sizeof(cfg::fs_ssid)-1, CFG_KEY_FS_SSID, cfg::fs_ssid },
	{ Config_Type_Password, sizeof(cfg::fs_pwd)-1, CFG_KEY_FS_PWD, cfg::fs_pwd },
	{ Config_Type_Bool, 0, CFG_KEY_WWW_BASICAUTH_ENABLED, &cfg::www_basicauth_enabled },
	{ Config_Type_Bool, 0, CFG_KEY_DHT_READ, &cfg::dht_read },
	{ Config_Type_Bool, 0, CFG_KEY_HTU21D_READ, &cfg::htu21d_read },
	{ Config_Type_Bool, 0, CFG_KEY_PPD_READ, &cfg::ppd_read },
	{ Config_Type_Bool, 0, CFG_KEY_SDS_READ, &cfg::sds_read },
	{ Config_Type_Bool, 0, CFG_KEY_PMS_READ, &cfg::pms_read },
	{ Config_Type_Bool, 0, CFG_KEY_HPM_READ, &cfg::hpm_read },
	{ Config_Type_Bool, 0, CFG_KEY_NPM_READ, &cfg::npm_read },
	{ Config_Type_Bool, 0, CFG_KEY_NPM_FULLTIME, &cfg::npm_fulltime },
	{ Config_Type_UInt, 0, CFG_KEY_NPM_HEATER_MODE, &cfg::npm_heater_mode },
	{ Config_Type_Bool, 0, CFG_KEY_IPS_READ, &cfg::ips_read },
	{ Config_Type_Bool, 0, CFG_KEY_SEN5X_READ, &cfg::sen5x_read },
	{ Config_Type_Bool, 0, CFG_KEY_SEN5X_ON, &cfg::sen5x_on },
	{ Config_Type_String, sizeof(cfg::sen5x_sym_pm)-1, CFG_KEY_SEN5X_SYM_PM, cfg::sen5x_sym_pm },
	{ Config_Type_String, sizeof(cfg::sen5x_sym_th)-1, CFG_KEY_SEN5X_SYM_TH, cfg::sen5x_sym_th },
	{ Config_Type_Bool, 0, CFG_KEY_SEN5X_PIN16, &cfg::sen5x_pin16 },
	{ Config_Type_Bool, 0, CFG_KEY_SPS30_READ, &cfg::sps30_read },
	{ Config_Type_Bool, 0, CFG_KEY_BMP_READ, &cfg::bmp_read },
	{ Config_Type_Bool, 0, CFG_KEY_BMX280_READ, &cfg::bmx280_read },
	{ Config_Type_Bool, 0, CFG_KEY_SHT3X_READ, &cfg::sht3x_read },
	{ Config_Type_Bool, 0, CFG_KEY_SCD30_READ, &cfg::scd30_read },
	{ Config_Type_Bool, 0, CFG_KEY_DS18B20_READ, &cfg::ds18b20_read },
	{ Config_Type_Bool, 0, CFG_KEY_DNMS_READ, &cfg::dnms_read },
	{ Config_Type_String, sizeof(cfg::dnms_correction)-1, CFG_KEY_DNMS_CORRECTION, cfg::dnms_correction },
	{ Config_Type_String, sizeof(cfg::temp_correction)-1, CFG_KEY_TEMP_CORRECTION, cfg::temp_correction },
	{ Config_Type_String, sizeof(cfg::height_above_sealevel)-1, CFG_KEY_HEIGHT_ABOVE_SEALEVEL, cfg::height_above_sealevel },
	{ Config_Type_Bool, 0, CFG_KEY_GPS_READ, &cfg::gps_read },
	{ Config_Type_Bool, 0, CFG_KEY_SEND2DUSTI, &cfg::send2dusti },
	{ Config_Type_Bool, 0, CFG_KEY_SSL_DUSTI, &cfg::ssl_dusti },
	{ Config_Type_Bool, 0, CFG_KEY_SEND2MADAVI, &cfg::send2madavi },
	{ Config_Type_Bool, 0, CFG_KEY_SSL_MADAVI, &cfg::ssl_madavi },
	{ Config_Type_Bool, 0, CFG_KEY_SEND2SENSEMAP, &cfg::send2sensemap },
	{ Config_Type_Bool, 0, CFG_KEY_SEND2FSAPP, &cfg::send2fsapp },
	{ Config_Type_Bool, 0, CFG_KEY_SEND2AIRCMS, &cfg::send2aircms },
	{ Config_Type_Bool, 0, CFG_KEY_SEND2CSV, &cfg::send2csv },
	{ Config_Type_Bool, 0, CFG_KEY_AUTO_UPDATE, &cfg::auto_update },
	{ Config_Type_Bool, 0, CFG_KEY_USE_BETA, &cfg::use_beta },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_DISPLAY, &cfg::has_display },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_SH1106, &cfg::has_sh1106 },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_FLIPPED_DISPLAY, &cfg::has_flipped_display },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_LCD1602, &cfg::has_lcd1602 },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_LCD1602_27, &cfg::has_lcd1602_27 },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_LCD2004, &cfg::has_lcd2004 },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_LCD2004_27, &cfg::has_lcd2004_27 },
	{ Config_Type_Bool, 0, CFG_KEY_DISPLAY_WIFI_INFO, &cfg::display_wifi_info },
	{ Config_Type_Bool, 0, CFG_KEY_DISPLAY_DEVICE_INFO, &cfg::display_device_info },
	{ Config_Type_String, sizeof(cfg::static_ip)-1, CFG_KEY_STATIC_IP, cfg::static_ip },
	{ Config_Type_String, sizeof(cfg::static_subnet)-1, CFG_KEY_STATIC_SUBNET, cfg::static_subnet },
	{ Config_Type_String, sizeof(cfg::static_gateway)-1, CFG_KEY_STATIC_GATEWAY, cfg::static_gateway },
	{ Config_Type_String, sizeof(cfg::static_dns)-1, CFG_KEY_STATIC_DNS, cfg::static_dns },
	{ Config_Type_UInt, 0, CFG_KEY_DEBUG, &cfg::debug },
	{ Config_Type_Time, 0, CFG_KEY_SENDING_INTERVALL_MS, &cfg::sending_intervall_ms },
	{ Config_Type_Time, 0, CFG_KEY_TIME_FOR_WIFI_CONFIG, &cfg::time_for_wifi_config },
	{ Config_Type_Bool, 0, CFG_KEY_POWERSAVE, &cfg::powersave },
	{ Config_Type_String, sizeof(cfg::senseboxid)-1, CFG_KEY_SENSEBOXID, cfg::senseboxid },
	{ Config_Type_Bool, 0, CFG_KEY_SEND2CUSTOM, &cfg::send2custom },
	{ Config_Type_String, sizeof(cfg::host_custom)-1, CFG_KEY_HOST_CUSTOM, cfg::host_custom },
	{ Config_Type_String, sizeof(cfg::url_custom)-1, CFG_KEY_URL_CUSTOM, cfg::url_custom },
	{ Config_Type_UInt, 0, CFG_KEY_PORT_CUSTOM, &cfg::port_custom },
	{ Config_Type_String, sizeof(cfg::user_custom)-1, CFG_KEY_USER_CUSTOM, cfg::user_custom },
	{ Config_Type_Password, sizeof(cfg::pwd_custom)-1, CFG_KEY_PWD_CUSTOM, cfg::pwd_custom },
	{ Config_Type_Bool, 0, CFG_KEY_SSL_CUSTOM, &cfg::ssl_custom },
	{ Config_Type_Bool, 0, CFG_KEY_SEND2INFLUX, &cfg::send2influx },
	{ Config_Type_String, sizeof(cfg::host_influx)-1, CFG_KEY_HOST_INFLUX, cfg::host_influx },
	{ Config_Type_String, sizeof(cfg::url_influx)-1, CFG_KEY_URL_INFLUX, cfg::url_influx },
	{ Config_Type_UInt, 0, CFG_KEY_PORT_INFLUX, &cfg::port_influx },
	{ Config_Type_String, sizeof(cfg::user_influx)-1, CFG_KEY_USER_INFLUX, cfg::user_influx },
	{ Config_Type_Password, sizeof(cfg::pwd_influx)-1, CFG_KEY_PWD_INFLUX, cfg::pwd_influx },
	{ Config_Type_Bool, 0, CFG_KEY_SEND2MQTT, &cfg::send2mqtt },
	{ Config_Type_String, sizeof(cfg::mqtt_server)-1, CFG_KEY_MQTT_SERVER, cfg::mqtt_server },
	{ Config_Type_UInt, 0, CFG_KEY_MQTT_PORT, &cfg::mqtt_port },
	{ Config_Type_String, sizeof(cfg::mqtt_user)-1, CFG_KEY_MQTT_USER, cfg::mqtt_user },
	{ Config_Type_Password, sizeof(cfg::mqtt_pwd)-1, CFG_KEY_MQTT_PWD, cfg::mqtt_pwd },
	{ Config_Type_String, sizeof(cfg::mqtt_topic)-1, CFG_KEY_MQTT_TOPIC, cfg::mqtt_topic },
	{ Config_Type_String, sizeof(cfg::measurement_name_influx)-1, CFG_KEY_MEASUREMENT_NAME_INFLUX, cfg::measurement_name_influx },
	{ Config_Type_Bool, 0, CFG_KEY_SSL_INFLUX, &cfg::ssl_influx },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_FIX_IP, &cfg::has_fix_ip },
	{ Config_Type_String, sizeof(cfg::scd30_co2_correction)-1, CFG_KEY_SCD30_CO2_CORRECTION, cfg::scd30_co2_correction },
	{ Config_Type_String, sizeof(cfg::scd30_temp_correction)-1, CFG_KEY_SCD30_TEMP_CORRECTION, cfg::scd30_temp_correction },
	{ Config_Type_String, sizeof(cfg::host_radar)-1, CFG_KEY_HOST_RADAR, cfg::host_radar },
	{ Config_Type_UInt, 0, CFG_KEY_PORT_RADAR, &cfg::port_radar },
	{ Config_Type_UInt, 0, CFG_KEY_MOTION_WAIT_TIME, &cfg::motion_wait_time },
	{ Config_Type_String, sizeof(cfg::user_radar)-1, CFG_KEY_USER_RADAR, cfg::user_radar },
	{ Config_Type_Password, sizeof(cfg::pwd_radar)-1, CFG_KEY_PWD_RADAR, cfg::pwd_radar },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_RADARMOTION, &cfg::has_radarmotion },
	{ Config_Type_Bool, 0, CFG_KEY_HAS_MOREWIFI, &cfg::has_morewifi },
};

#endif

