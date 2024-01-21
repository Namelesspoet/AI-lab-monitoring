bool valSwitch1 = 0;
int LogShow = 5;
GP_SPINNER LogNum("LogNum");


String DetType2P[3] = {"Door","Window",""};
String DetType3P[6] ={"Temp det","Temp + humid det","Movement","IR led","IR det",""};
// bool DetSw[10] = {0};

void auth() {
  //веб морда для записи настроек WiFi
  GP.BUILD_BEGIN(1920);
  GP.JQ_SUPPORT();
  GP.ONLINE_CHECK();
  GP.THEME(GP_DARK);
  GP.PAGE_TITLE("GG Detectors");
  GP.GRID_RESPONSIVE(700);
  GP.NAV_TABS("Detectors,Net Settings,Servise");

  GP.NAV_BLOCK_BEGIN();
  M_GRID(
    M_BLOCK_TAB(
      "Reed switces",
      M_BOX(
        GP.LABEL("0");
        GP.TEXT("DetName0", "Имя (32 символа)", Configuration.DetName[0], "150px", 32);
        GP.SELECT("DetSel0", DetType2P,Configuration.DetType2PSel[0]);
        GP.SWITCH("DetSw0", Configuration.DetSw[0]);
        GP.LED("led0"););
      M_BOX(
        GP.LABEL("1");
        GP.TEXT("DetName1", "Имя (32 символа)", Configuration.DetName[1], "150px", 32);
        GP.SELECT("DetSel1", DetType2P,Configuration.DetType2PSel[1]);
        GP.SWITCH("DetSw1", Configuration.DetSw[1]);
        GP.LED("led1"););
      M_BOX(
        GP.LABEL("2");
        GP.TEXT("DetName2", "Имя (32 символа)", Configuration.DetName[2], "150px", 32);
        GP.SELECT("DetSel2", DetType2P,Configuration.DetType2PSel[2]);
        GP.SWITCH("DetSw2", Configuration.DetSw[2]);
        GP.LED("led2"););
      M_BOX(
        GP.LABEL("3");
        GP.TEXT("DetName3", "Имя (32 символа)", Configuration.DetName[3], "150px", 32);
        GP.SELECT("DetSel3", DetType2P, Configuration.DetType2PSel[3]);
        GP.SWITCH("DetSw3", Configuration.DetSw[3]);
        GP.LED("led3"););
      M_BOX(
        GP.LABEL("4");
        GP.TEXT("DetName4", "Имя (32 символа)", Configuration.DetName[4], "150px", 32);
        GP.SELECT("DetSel4", DetType2P, Configuration.DetType2PSel[4]);
        GP.SWITCH("DetSw4", Configuration.DetSw[4]);
        GP.LED("led4"););
      M_BOX(GP.BUTTON("Det2PSave", "Save reed settings"));
      //M_BOX(
      // );
      // M_BOX(
      // );
    );
    M_BLOCK_TAB(
      "Plots",
      GP.LABEL("test"));
      
  );
  M_GRID(
    M_BLOCK_TAB(
      "Sensors",
      M_BOX(
        GP.LABEL("5");
        GP.TEXT("DetName5", "Имя (32 символа)", Configuration.DetName[5], "150px", 32);
        GP.SELECT("", DetType3P,0, 0, 1);  
        GP.SWITCH("DetSw5", Configuration.DetSw[5]););
      M_BOX(
        GP.LABEL("6");
        GP.TEXT("DetName6", "Имя (32 символа)", Configuration.DetName[6], "150px", 32);
        GP.SELECT("", DetType3P,1, 0, 1);   
        GP.SWITCH("DetSw5", Configuration.DetSw[6]););
        M_BOX(
        GP.LABEL("7");
        GP.TEXT("DetName7", "Имя (32 символа)", Configuration.DetName[7], "150px", 32);
        GP.SELECT("", DetType3P,2, 0, 1);     
        GP.SWITCH("DetSw7", Configuration.DetSw[7]););
      M_BOX(
        GP.LABEL("8");
        GP.TEXT("DetName8", "Имя (32 символа)", Configuration.DetName[8], "150px", 32);
        GP.SELECT("", DetType3P,3, 0, 1);  
        GP.SWITCH("DetSw8", Configuration.DetSw[8]););
      M_BOX(
        GP.LABEL("9");
        GP.TEXT("DetName9", "Имя (32 символа)", Configuration.DetName[9], "150px", 32);
       GP.SELECT("", DetType3P,4, 0, 1);  
        GP.SWITCH("DetSw9", Configuration.DetSw[9]););
      );
    M_BLOCK_TAB(
      "plots",
      M_BOX(
        GP.LABEL("test");
      );
  );
  );
  GP.NAV_BLOCK_END();

  GP.NAV_BLOCK_BEGIN();
  M_GRID(
    M_BLOCK_TAB(
      "Wifi settings",
      //GP.BLOCK_BEGIN();
      GP.FORM_BEGIN("/netSettings");
      //GP.LABEL("Wifi connection settings");
      GP.TEXT("ssid", "SSID", Configuration.SSID);
      GP.BREAK();
      GP.PASS("pass", "Password", Configuration.PASS);
      GP.BREAK();
      //GP.BLOCK_END();
      GP.SUBMIT("Save");
      GP.BREAK();
      GP.BUTTON("rstBtn", "Reset");
      GP.FORM_END();););
  GP.NAV_BLOCK_END();

  GP.NAV_BLOCK_BEGIN();
  M_GRID(
    M_BLOCK_TAB(
      "Logs",
      GP.SPINNER("LogNum", LogShow, 1, LOG_SIZE, 1);
      
      M_TABLE(
        for (int i = 0; i < LogShow + 1; i++) {
          // макрос создаёт РЯД таблицы, элементы ЧЕРЕЗ ЗАПЯТУЮ
          M_TR(
            GP.LABEL(Configuration.LogRow[i]));
        }

      );
      ););
  M_GRID(
    M_BLOCK_TAB(
      "OTA",
      GP.OTA_FIRMWARE();););

  M_GRID(
    M_BLOCK_TAB(
      "FS",

      GP.FILE_MANAGER(&LittleFS);

    );
    M_BLOCK_TAB(

      "JSON",
      //GP.SPOILER_BEGIN("Json");
      GP.LABEL(createJson(), "", GP_DEFAULT, 0, 0, 1);
      //GP.SPOILER_END();
    ););
  GP.NAV_BLOCK_END();

  GP.UPDATE("ssid");
  GP.UPDATE("pass");
  GP.UPDATE("Json", 2000);
  GP.UPDATE("led0");
  GP.UPDATE("led1");
  GP.UPDATE("led2");
  GP.UPDATE("led3");
  GP.UPDATE("led4");
  //GP.UPDATE("l2");
  GP.BUILD_END();
}



void action(GyverPortal& p) {

  if (p.click("DetSw0")){Configuration.DetSw[0] = p.getCheck("DetSw0");}
  if (p.click("DetSw1")){Configuration.DetSw[1] = p.getCheck("DetSw1");}
  if (p.click("DetSw2")){Configuration.DetSw[2] = p.getCheck("DetSw2");}
  if (p.click("DetSw3")){Configuration.DetSw[3] = p.getCheck("DetSw3");}
  if (p.click("DetSw4")){Configuration.DetSw[4] = p.getCheck("DetSw4");}

  if (p.click("DetName0")){p.copyStr("DetName0",Configuration.DetName[0]);}
  if (p.click("DetName1")){p.copyStr("DetName1",Configuration.DetName[1]);}
  if (p.click("DetName2")){p.copyStr("DetName2",Configuration.DetName[2]);}
  if (p.click("DetName3")){p.copyStr("DetName3",Configuration.DetName[3]);}
  if (p.click("DetName4")){p.copyStr("DetName4",Configuration.DetName[4]);}

  if (p.click("DetSel0")){p.copyInt("DetSel0",Configuration.DetType2PSel[0]);}
  if (p.click("DetSel1")){p.copyInt("DetSel1",Configuration.DetType2PSel[1]);}
  if (p.click("DetSel2")){p.copyInt("DetSel2",Configuration.DetType2PSel[2]);}
  if (p.click("DetSel3")){p.copyInt("DetSel3",Configuration.DetType2PSel[3]);}
  if (p.click("DetSel4")){p.copyInt("DetSel4",Configuration.DetType2PSel[4]);}

  if (p.click("Det2PSave")){Cfg.updateNow();}


  if (p.update()) {
    UpdateState2P(Det2pState,Configuration.DetSw);
    if (p.update("led0")) {p.answer(Det2pState[0]); }
    if (p.update("led1")) {p.answer(Det2pState[1]); }
    if (p.update("led2")) {p.answer(Det2pState[2]); }
    if (p.update("led3")) {p.answer(Det2pState[3]); }
    if (p.update("led4")) {p.answer(Det2pState[4]); }
    
  }
  if (p.form("/netSettings")) {
    p.copyStr("ssid", Configuration.SSID);
    p.copyStr("pass", Configuration.PASS);
    Cfg.updateNow();
    logWrite("Data read:");
    logWrite(Configuration.SSID);
    logWrite(Configuration.PASS);
  }
  if (p.hold("rstBtn")) {
    p.stop();
    ESP.reset();
  }
  //if (ui.update("sw")) ui.answer(ui.getSystemTime().encode());
}


// void UI()
// {
//   //веб морда для записи настроек WiFi
//   GP.BUILD_BEGIN();
//   GP.PAGE_TITLE("GG Detecters")
//   GP.ONLINE_CHECK();
//   GP.THEME(GP_DARK);
//   GP.PLAIN(GP_LOG)
//   GP_LOG();
//   GP.BUTTON_MINI("rstBtn", "Reset");
//   GP.FILE_MANAGER(&LittleFS);
//   GP.BUILD_END();
// }
//String GP_JSWS() {
//  String s;
//  s += F("<details open="
//         "><summary align=\"left\" style=\"\">Json</summary><div align=\"center\" style=\"white-space:normal;\">");
//  s += F("<label style=\"white-space:normal;\">");
//  s += createJson();
//  s += F("</label>");
//  s += F("</div></details>");
//  GP.SEND(s);
//}


String GP_LOG(int N = LOG_SIZE) {

  String s;
  for (int i = 0; i < N; i++) {
    s += "<p>";
    s += Configuration.LogRow[i];
    s += "/n";
  }
  GP.SEND(s);
  return s;
}
