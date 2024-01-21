#include <FileData.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h>
#include <SimplePortal.h>
#include <GyverPortal.h>
#include <ESP8266WebServer.h>
#include <GyverNTP.h>
#include <ArduinoJson.h>
#include <GyverNTP.h>
#include <ArduinoOTA.h>






 //пин датчика движения (GPIO 5 == D1)
#define LOG_SIZE 50
#define LOG_LEN 100

ESP8266WebServer server(80);

GyverNTP ntp(3);
GyverPortal ui;
//инициализация файловой системы и созданние файла под настройки сети
struct Cfg
{
  char SSID[20];
  char PASS[20];
  char LogRow[LOG_SIZE][LOG_LEN];
  IPAddress LastIP;
  int DetType2PSel[5];
  int DetType3PSel[5];
  bool DetSw[10];
  char DetName[10][32];  
};
Cfg Configuration;
FileData Cfg(&LittleFS, "/Configuration.dat", 'A', &Configuration, sizeof(Configuration));

void setup() {
  Serial.begin(9600);
  delay(3000);
  Serial.println();
  logWrite("Startup");
  LittleFS.begin();
  FDstat_t stat =Cfg.read();
  
  trySTA();
  Serial.println("Data read:");
  Serial.println(Configuration.SSID);
  Serial.println(Configuration.PASS);
  starupOTA();

  Serial.println("HTTP server started");
  logWrite("HTTP server started");
  ntp.begin();
  ui.attachBuild(auth); //строим веб морду
  ui.start();   // запускаем портал
  ui.attach(action);
  ui.enableOTA(); //привязываем действия кнопок к веб морде
  
}

void loop() 
{
  //DetState2P();
  ntp.tick();
  ui.tick();
  ArduinoOTA.handle();
}
