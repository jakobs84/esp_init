#include <Arduino.h>
#include <Credentials.h>
#include "version.h"

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

  Serial.printf("\n\nESPrinkler2 %s compiled %s %s %s\n", VERSION, __DATE__, __TIME__, __FILE__);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();      //  https://starter-kit.nettigo.pl/2018/02/nodemcu-praca-trybie-ap-czyli-wlasne-wifi/
  delay(500);
  // Connect to Wi-Fi
  Serial.print("Connecting to WiFi..  ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

}

void loop() {
 // digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  // put your main code here, to run repeatedly:
  delay(800);

  if (digitalRead(LED_BUILTIN))
      Serial.println("LED ON");
  else
      Serial.println("LED OFF");
}