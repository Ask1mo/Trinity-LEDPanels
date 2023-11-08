// WebServerManager.cpp
#include "WebServerManager.h"
#include "webpage.html"

WebServerManager::WebServerManager(const char* ssid, const char* password, int port) : server(port), ssid(ssid), password(password) {}

void WebServerManager::start()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while(WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    delay(500); Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/",        std::bind(&WebServerManager::handleRoot, this));
  server.on("/readPOT", std::bind(&WebServerManager::handlePOT, this));
  server.begin();
  Serial.println("HTTP server started");
}

void WebServerManager::handleClient()
{
  server.handleClient(); delay(1);
}

void WebServerManager::handleRoot()
{
  server.send(200, "text/html", webpageCode);
}

void WebServerManager::handlePOT()
{
  String POTval = "color: rgb(";
  POTval += String(random(0, 255));
  POTval += String(", ");
  POTval += String(random(0, 255));
  POTval += String(", ");
  POTval += String(random(0, 255));
  POTval += String(");");
  server.send(200, "text/plane", POTval);
}