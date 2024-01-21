
String createJson() {
    const int DETECTORS_COUNT = 9;
    StaticJsonDocument<800> doc;

    // Заполняем datetime объект
    JsonObject datetime = doc.createNestedObject("datetime");
    datetime["time"] = ntp.timeString() + "." + ntp.ms();
    datetime["data"] = ntp.dateString();

    // Заполняем каждый детектор
    for (int i = 0; i <= DETECTORS_COUNT; i++) {
      String detName = "det" + String(i);
      if (Configuration.DetSw[i]!=0)
      {
        JsonObject det = doc.createNestedObject(detName);
        det["power"] = "On";
        det["name"] = (Configuration.DetName[i]==""?"None",Configuration.DetName[i]);
        if (i=<4){
          switch(Configuration.DetType2PSel[i]){
          case 0: det["type"] =  "Door";   break;
          case 1: det["type"] =  "Window"; break;
          default: det["type"]=  "Error";  break;
          String Det2pState[5];
          UpdateState2P(Det2pState,Configuration.DetSw)

          

        det["state"] = i % 3 == 0 ? "Open" : "Closed";
      } else {det["power"] = "Off";}



    }

    // Сериализуем Json
    String jsonString;
    serializeJson(doc, jsonString);
    //Serial.println(jsonString);
    return jsonString;
  }



