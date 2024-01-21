GyverPortal webFace;


void trySTA()
{
  //пытаемся подключиться к сети по записаным настройкам
  WiFi.mode(WIFI_STA);
  WiFi.begin(Configuration.SSID, Configuration.PASS);
  while ((WiFi.status() != WL_CONNECTED)&&(millis()<=20000))
  
    {
      Serial.println("trying 2 connect");
      delay(500);
    };
     if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("Connected succesfully");
      Serial.println(WiFi.localIP());
      Configuration.LastIP =  WiFi.localIP(); 

    }
  else setAP(); //если не вышло, переходим  в режим веб морды для ввода настроек сети
}

void setAP()
{
  Serial.println("AP Mode");
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  String NetName ="Detectors setup  ";
  //if (Configuration.LastIP.toString()!=""){NetName += Configuration.LastIP.toString();}
  WiFi.softAP(NetName);
  webFace.attachBuild(auth); //строим веб морду
  webFace.start();   // запускаем портал
  webFace.attach(action); //привязываем действия кнопок к веб морде
  while ( webFace.tick());
}

