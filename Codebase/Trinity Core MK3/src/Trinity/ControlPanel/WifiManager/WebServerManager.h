// WebServerManager.h
#include <WebServer.h>
#include <WiFi.h>

class WebServerManager
{
public:
  WebServerManager(const char* ssid, const char* password, int port);
  void start();
  void handleClient();

private:
  WebServer server;
  WiFiClient client;
  const char* ssid;
  const char* password;

  void handleRoot();
  void handlePOT();
};