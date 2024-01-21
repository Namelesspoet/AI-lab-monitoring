void sendJsonHTML ()
{ server.send(200, "text/html", createJsonHTML());
  logWrite("sendJson");
}

void sendLogsHTML ()
{ server.send(200, "text/html", createLogsHTML());
  logWrite("sendLogs");
}


void sendMainHTML ()
{ server.send(200, "text/html", createMainHTML());
  logWrite("sendmain");
}


String createJsonHTML()
{
  String html = "<!DOCTYPE html><meta http-equiv=\"refresh\" content=\"2\"><html><head><title>JSON Display</title></head><body><p>";
  html += createJson() ; // Append JSON string to HTML
  html += "</p></body></html>";

  return html;
}
String createLogsHTML ()
{
  String page = "<!DOCTYPE html><html><head><title>JSON Display</title></head><body>";
  //Выводим логи на страницу
  for (int i = 0; i < LOG_SIZE; i++) {
    page += "<p>";
    page += Configuration.LogRow[i];
    page += "</p>";
  }
  page += "</body></html>";
  return page;

}

String createMainHTML ()
{
  String html = "<!DOCTYPE html><head><title>Button Page</title></head><body>";
  html += "<button onclick=\"redirectToLogs()\">Logs</button>";
  html += "<button onclick=\"redirectToJson()\">Json</button>";
  html += "<script>";
  html += "function redirectToLogs() {window.location.href = \"http://" ;
  html += WiFi.localIP().toString();
  html += "/logs\";}";
  html += "function redirectToJson() {window.location.href = \"http://";
  html += WiFi.localIP().toString();
  html += "/json\";}";
  html += "</script></body></html>";

  return html;
}
