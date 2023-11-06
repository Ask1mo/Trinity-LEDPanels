#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <Arduino.h>
#include <WiFi.h>

//const char* ssid = "Askimo";
//const char* password = "CringeDingus2003!";
#define SSID "Askimo"
#define PASSWORD "CringeDingus2003!"
#define TIMEOUTTIME 2000
#define PIN_A 13
#define PIN_B 14






class Webserver
{
private:
    WiFiServer      *server;
    String          header;
    String          output26State = "off";
    String          output27State = "off";
    unsigned long   currentTime;
    unsigned long   previousTime = 0; 
    bool            connected;
    void            printPage(WiFiClient client);
    
public:
    Webserver();
    void tick();
};

#endif




