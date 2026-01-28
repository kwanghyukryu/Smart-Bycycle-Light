
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

#include <Wire.h>


const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
int state;
int right;
int left;


String out(){
  if(state == HIGH){
    return "on";
  }
  else{
    return "off";
  }
}

String turn(){
  if(right == HIGH && left == HIGH){
    return "n";
  }
  if(right == LOW){
    return "right";
  }
  if(left == LOW){
    return "left";
  }
  
  
  return "n";
  }//on port 80
AsyncWebServer server(80);


void setup(){
  // Serial port for debugging purposes
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.println();
  
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/brake", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", out().c_str());
  });

  server.on("/turn", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", turn().c_str());
  });

  
  // Start server
  server.begin();
}
 
void loop(){
  state = digitalRead(18);
  left = digitalRead(19);
  right = digitalRead(21);

}


