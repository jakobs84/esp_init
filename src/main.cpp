#include <Arduino.h>
#include <Credentials.h>

// Import required libraries
#ifdef ESP32
  #include <WiFi.h>
//  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
//  #include <ESPAsyncTCP.h>
#endif
//#include <ESPAsyncWebServer.h>

#include <Credentials.h>

const char* ssid       = WIFI_SSID;               // WiFi SSID     replace with details for your local network
const char* password   = WIFI_PW;           // WiFi Password replace with details for your local network
//const char* ssid       = WIFI_SSIDtel
//const char* password   = WIFI_PWtel

//#define LED_BUILTIN LED_BUILTIN
//static const uint8_t LED_BUILTIN = 2;//new ESP-12E GPIO2

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  //digitalWrite(LED_BUILTIN, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
}