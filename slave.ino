
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

const char* serverNameTemp = "http://192.168.4.1/brake";
const char* serverNameTemp1 = "http://192.168.4.1/turn";



String p;
String turn;


unsigned long previousMillis = 0;
const long interval = 5000; 

void setup() {
  pinMode(2,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(16,OUTPUT);
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
    if(WiFi.status()== WL_CONNECTED ){ 
      p = httpGETRequest(serverNameTemp);
      turn = httpGETRequest(serverNameTemp1);
      Serial.println(p);
      Serial.println(turn);
      if(turn != "n"){
          if(turn == "right"){
            digitalWrite(0,HIGH);
            delay(750);
            digitalWrite(0,LOW);
            delay(750);
          }
          else if(turn == "left"){
            digitalWrite(4,HIGH);
            delay(750);
            digitalWrite(4,LOW);
            delay(750);
          }
      }
      else{
      if(p == "on"){
          digitalWrite(2,HIGH);
          digitalWrite(16,HIGH);
      }
      else if(p == "off"){
        digitalWrite(2,LOW);
        digitalWrite(16,LOW);
      }
      }
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  http.begin(client, serverName);
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();

  return payload;
}
