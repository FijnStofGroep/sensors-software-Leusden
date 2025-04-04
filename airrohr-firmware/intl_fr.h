/*
 *	airRohr firmware
 *	Copyright (C) 2016-2020 Code for Stuttgart a.o.
 *
 *  French translations
 *
 *	Texts should be as short as possible
 */

#include "./airrohr-logo-common.h"

#define INTL_LANG "FR"
#define INTL_PM_SENSOR "Détecteur de particules fines"
const char INTL_CONFIGURATION[] PROGMEM = "Configuration";
#define INTL_WIFI_SETTINGS "Paramètres wifi"
#define INTL_WIFI_NETWORKS "Chargement des réseaux wifi ..."
#define INTL_LANGUAGE "Langage"
const char INTL_NO_NETWORKS[] PROGMEM =  "Pas de réseau wifi";
const char INTL_NETWORKS_FOUND[] PROGMEM = "Réseaux détectés: ";
const char INTL_AB_HIER_NUR_ANDERN[] PROGMEM = "Paramètres avancés (seulement si vous savez ce que vous faites)";
const char INTL_SAVE[] PROGMEM = "Enregistrer";
const char INTL_SENSORS[] PROGMEM = "Capteurs";
const char INTL_MORE_SENSORS[] PROGMEM = "Autres capteurs";
const char INTL_SDS011[] PROGMEM = "SDS011 ({pm})";
const char INTL_PMS[] PROGMEM = "Plantower PMS(1,3,5,6,7)003 ({pm})";
const char INTL_HPM[] PROGMEM = "Honeywell détecteur de particules fines";
const char INTL_NPM[] PROGMEM = "Tera Sensor Next PM ({pm})";
const char INTL_NPM_FULLTIME[] PROGMEM = "Next PM permanent";
const char INTL_IPS[] PROGMEM = "Piera Systems IPS-7100 ({pm})";
const char INTL_SEN5X[] PROGMEM = "Sensirion I2C SEN5X ({pm}, {t}, {h}, {voc}, {nox})";
const char INTL_SPS30[] PROGMEM = "Sensirion SPS30 ({pm})";
const char INTL_PPD42NS[] PROGMEM = "PPD42NS ({pm})";
const char INTL_DHT22[] PROGMEM = "DHT22 ({t}, {h})";
const char INTL_HTU21D[] PROGMEM = "HTU21D ({t}, {h})";
const char INTL_BMP180[] PROGMEM = "BMP180 ({t}, {p})";
const char INTL_BMX280[] PROGMEM = "BME280 ({t}, {h}, {p}), BMP280 ({t}, {p})";
const char INTL_SHT3X[] PROGMEM = "SHT3X ({t}, {h})";
const char INTL_SCD30[] PROGMEM = "SCD30 ({t}, {h}, CO₂)";
const char INTL_DS18B20[] PROGMEM = "DS18B20 ({t})";
const char INTL_DNMS[] PROGMEM = "DNMS ({l_a}) Son";
const char INTL_DNMS_CORRECTION[] PROGMEM = "Valeur corrigée en dB(A)";
const char INTL_TEMP_CORRECTION[] PROGMEM = "Valeur corrigée en °C";
const char INTL_HEIGHT_ABOVE_SEALEVEL[] PROGMEM = "Altitude en m";
const char INTL_PRESSURE_AT_SEALEVEL[] PROGMEM = "Press. atm. au niveau de la mer en hPa";
const char INTL_NEO6M[] PROGMEM = "GPS (NEO 6M)";
const char INTL_BASICAUTH[] PROGMEM = "Activer BasicAuth";
#define INTL_REPORT_ISSUE "Signaler un problème"

const char INTL_FS_WIFI_DESCRIPTION[] PROGMEM = "Nom du capteur wifi en mode de configuration";
const char INTL_FS_WIFI_NAME[] PROGMEM = "Nom";
const char INTL_FS_WIFI_NAME_2[] PROGMEM = "Nom 2";
const char INTL_FS_WIFI_NAME_3[] PROGMEM = "Nom 3";
const char INTL_MORE_SETTINGS[] PROGMEM = "Autres paramètres";
const char INTL_AUTO_UPDATE[] PROGMEM = "Mise a jour automatique";
const char INTL_USE_BETA[] PROGMEM = "Télécharger la version bêta";
const char INTL_DISPLAY[] PROGMEM = "OLED SSD1306";
const char INTL_SH1106[] PROGMEM = "OLED SH1106";
const char INTL_FLIP_DISPLAY[] PROGMEM = "Faire pivoter l'affichage OLED de 180°";
const char INTL_LCD1602_27[] PROGMEM = "LCD 1602 (I2C: 0x27)";
const char INTL_LCD1602_3F[] PROGMEM = "LCD 1602 (I2C: 0x3F)";
const char INTL_LCD2004_27[] PROGMEM = "LCD 2004 (I2C: 0x27)";
const char INTL_LCD2004_3F[] PROGMEM = "LCD 2004 (I2C: 0x3F)";
const char INTL_DISPLAY_WIFI_INFO[] PROGMEM = "Afficher les informations wifi";
const char INTL_DISPLAY_DEVICE_INFO[] PROGMEM = "Afficher les informations de l'appareil";

#define INTL_STATIC_IP_TEXT "Configuration de l'adresse IP statique (tous les champs doivent être remplis)"
const char INTL_STATIC_IP[] PROGMEM = "Adresse IP";
const char INTL_STATIC_SUBNET[] PROGMEM = "Subnet";
const char INTL_STATIC_GATEWAY[] PROGMEM = "Gateway";
const char INTL_STATIC_DNS[] PROGMEM = "Serveur DNS";

// MQTT
const char INTL_SEND_TO_MQTT[] PROGMEM = "Envoyer à  MQTT";
const char INTL_TOPIC[] PROGMEM = "Topic";
const char INTL_ONLINE[] PROGMEM = "En ligne";
const char INTL_OFFLINE[] PROGMEM = "Hors ligne";
const char INTL_MQTT_STAT[] PROGMEM = "Statut";

const char INTL_SCD30_CO2_CORRECTION[] PROGMEM = "Valeur corrigée en  CO₂";

const char INTL_DEBUG_LEVEL[] PROGMEM = "Niveau&nbsp;de&nbsp;débogage";
const char INTL_MEASUREMENT_INTERVAL[] PROGMEM = "Intervalle de mesure";
const char INTL_DURATION_ROUTER_MODE[] PROGMEM = "Durée mode routeur";
const char INTL_POWERSAVE[] PROGMEM = "Sauvegarde énergie";
const char INTL_MORE_APIS[] PROGMEM = "Autres API";
const char INTL_SEND_TO_OWN_API[] PROGMEM = "Envoyer les données vers l'API personnelle";
const char INTL_SERVER[] PROGMEM = "Serveur";
const char INTL_PATH[] PROGMEM = "Chemin";
const char INTL_PORT[] PROGMEM = "Port";
const char INTL_USER[] PROGMEM = "Utilisateur";
const char INTL_PASSWORD[] PROGMEM = "Mot de passe";
const char INTL_MOTION_WAIT_TIME[] PROGMEM = "Motion wait time";
const char INTL_MEASUREMENT[] PROGMEM = "Mesure";
const char INTL_SEND_TO[] PROGMEM = "Envoyer à {v}";
const char INTL_READ_FROM[] PROGMEM = "Lire {v}";
const char INTL_SENSOR_IS_REBOOTING[] PROGMEM = "Le détecteur est en train de redémarrer.";
const char INTL_RESTART_DEVICE[] PROGMEM = "Redémarrer l'appareil";
const char INTL_DELETE_CONFIG[] PROGMEM = "Effacer le fichier config.json";
const char INTL_RESTART_SENSOR[] PROGMEM = "Redémarrer le capteur";
#define INTL_HOME "Aperçu"
#define INTL_BACK_TO_HOME "Page d'accueil"
const char INTL_CURRENT_DATA[] PROGMEM = "Données actuelles";
const char INTL_DEVICE_STATUS[] PROGMEM = "Etat de l'appareil";
#define INTL_ACTIVE_SENSORS_MAP "Carte des capteurs actifs (lien externe)"
#define INTL_CONFIGURATION_DELETE "Effacer la configuration"
#define INTL_CONFIGURATION_REALLY_DELETE "Voulez-vous vraiment effacer la configuration?"
#define INTL_DELETE "Effacer"
#define INTL_CANCEL "Annuler"
#define INTL_REALLY_RESTART_SENSOR "Voulez-vous vraiment redémarrer le capteur?"
#define INTL_RESTART "Redémarrer"
const char INTL_SAVE_AND_RESTART[] PROGMEM = "Sauvegarder et redémarrer";
#define INTL_FIRMWARE "Firmware"
const char INTL_DEBUG_SETTING_TO[] PROGMEM = "Paramètres de débogage";
#define INTL_NONE "aucun"
#define INTL_ERROR "erreur"
#define INTL_WARNING "avertissement"
#define INTL_MIN_INFO "min. info"
#define INTL_MED_INFO "mid. info"
#define INTL_MAX_INFO "max. info"
#define INTL_CONFIG_DELETED "Le fichier config.json a été effacé."
#define INTL_CONFIG_CAN_NOT_BE_DELETED "Le fichier config.json n\'a pas pu être effacé."
#define INTL_CONFIG_NOT_FOUND "Le fichier config.json est introuvable."
const char INTL_TIME_TO_FIRST_MEASUREMENT[] PROGMEM = "Encore {v} secondes avant la première mesure.";
const char INTL_TIME_SINCE_LAST_MEASUREMENT[] PROGMEM = " secondes écoulées depuis la dernière mesure.";
const char INTL_PARTICLES_PER_LITER[] PROGMEM = "particules/litre";
const char INTL_PARTICULATE_MATTER[] PROGMEM = "particules fines";
const char INTL_TEMPERATURE[] PROGMEM = "Température";
const char INTL_HUMIDITY[] PROGMEM = "Humidité relative";
const char INTL_PRESSURE[] PROGMEM = "Pression atmosphérique";
const char INTL_VOC[] PROGMEM = "Composés organiques volatiles";
const char INTL_VOC_LABLE[] PROGMEM = "(index)";
const char INTL_NOX[] PROGMEM = "Oxydes d'azote";
const char INTL_NOX_LABLE[] PROGMEM = "ppm";
const char INTL_DEW_POINT[] PROGMEM = "Point de rosée";
const char INTL_CO2_PPM[] PROGMEM = "CO₂";
const char INTL_LEQ_A[] PROGMEM = "LAeq";
const char INTL_LA_MIN[] PROGMEM = "LA min";
const char INTL_LA_MAX[] PROGMEM = "LA max";
const char INTL_LATITUDE[] PROGMEM = "Latitude";
const char INTL_LONGITUDE[] PROGMEM = "Longitude";
const char INTL_ALTITUDE[] PROGMEM = "Altitude";
const char INTL_TIME_UTC[] PROGMEM = "Heure (UTC)";
const char INTL_SIGNAL_STRENGTH[] PROGMEM = "Force du signal";
const char INTL_SIGNAL_QUALITY[] PROGMEM = "Qualité du signal";
#define INTL_NUMBER_OF_MEASUREMENTS "Nombre de mesures"
#define INTL_NUMBER_OF_RADARMOTION "Nombre radar motions"
#define INTL_TIME_SENDING_MS "Durée de la transmission des mesures"
#define INTL_SENSOR "Capteur"
#define INTL_PARAMETER "Paramètres"
#define INTL_VALUE "Valeur"


#define INTL_ENABLE_S7000 "Enable S7000 LTE"

const char INTL_SIM7000_CONFIGURATION[] PROGMEM = "Sim7000 LTE";
const char INTL_SIM7000[] PROGMEM = "Sim7000 LTE";
const char INTL_SIM7000_DIS[] PROGMEM = "Disable";

const char INTL_SIM_APN[] PROGMEM = "APN";
const char INTL_SIM_ID[] PROGMEM = "ID";
const char INTL_SIM_GPS[] PROGMEM = "GPS";
const char INTL_SIM_TYPE[] PROGMEM = "Type";
const char INTL_SIM_MODE[] PROGMEM = "Mode";

#define INTL_ENABLE_RCWL_0516 "Enable Radar Motion (after enable reboot and insert server credentials)"

#define INTL_MODE "Mode"
