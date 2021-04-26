#include <WiFiClientSecure.h> //Wifi library
#include "esp_wpa2.h" //wpa2 library for connections to Enterprise networks
#include <PubSubClient.h>
#include <time.h>
#include <ArduinoJson.h>

#include "config.h"

// Comment out the following line if you are using a WPA-2 network or hotspot
#define WPA_ENTERPRISE 1

WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);

/*
   Callback function for receiving mqtt messages. Based on the payload, we either turn the green LED
   on for 5 seconds (unlock msg) or blink the red LED (reject msg).
*/
void callback(char* topic, byte* payload, unsigned int length)
{
  StaticJsonDocument<200> rcvMsg;          // message that was received
  StaticJsonDocument<200> xmtMsg;          // message to send
  char jsonBuffer[512];

  struct tm timeinfo;

  // parse the received message
  payload[length] = '\0';
  deserializeJson(rcvMsg, String((char*)payload));

  // for debugging, print the received message
  serializeJsonPretty(rcvMsg, jsonBuffer);
  Serial.print("Received topic: " + String(topic));
  Serial.print(" payload: ");
  Serial.println(jsonBuffer);

  if(strstr(jsonBuffer,"forward"))                        ////////spin motors forward
  {
    digitalWrite(reverse,LOW);
    digitalWrite(forward,HIGH);
    // build a response
    getLocalTime(&timeinfo);
    xmtMsg["timestamp"] = asctime(&timeinfo);
    xmtMsg["state"] = "moving forward";
    serializeJson(xmtMsg, jsonBuffer);
    mqttClient.publish("Motor/status", jsonBuffer);
  }
  if(strstr(jsonBuffer,"reverse"))                        ///////////spin motors in reverse
  {
    digitalWrite(forward,LOW);
    digitalWrite(reverse,HIGH);
    // publish a status update
    mqttClient.publish("Motor/status", jsonBuffer);
 
     getLocalTime(&timeinfo);
    xmtMsg["timestamp"] = asctime(&timeinfo);
    xmtMsg["state"] = "moving in reverse";
    serializeJson(xmtMsg, jsonBuffer);
    mqttClient.publish("Motor/status", jsonBuffer);
  } 
   if(strstr(jsonBuffer,"forward"))                        ////////stop motors
  {
    digitalWrite(reverse,LOW);
    digitalWrite(forward,LOW);
    // build a response
    getLocalTime(&timeinfo);
    xmtMsg["timestamp"] = asctime(&timeinfo);
    xmtMsg["state"] = "moving forward";
    serializeJson(xmtMsg, jsonBuffer);
    mqttClient.publish("Motor/status", jsonBuffer);
  }
 
}

// Connect to the WiFi network
void reconnectWiFi()
{
  Serial.println();
  Serial.print("Connecting to network: ");
  Serial.println(ssid);
  WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
  WiFi.mode(WIFI_STA); //init wifi mode

#ifdef WPA_ENTERPRISE
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)identity, strlen(identity)); //provide identity
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)identity, strlen(identity)); //provide username --> identity and username is same
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)password, strlen(password)); //provide password
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT(); //set config settings to default
  esp_wifi_sta_wpa2_ent_enable(&config); //set config settings to enable function

  WiFi.begin(ssid); //connect to wifi
#else
  // connect to a WPA-2 network
  WiFi.begin(ssid, password);
#endif

  unsigned int counter = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    counter++;
    if (counter >= 60) { //after 30 seconds timeout - reset board
      ESP.restart();
    }
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address set: ");
  Serial.println(WiFi.localIP()); //print LAN IP

}

// Connect to AWS and mqtt broker
void reconnectAWS()
{
  unsigned int counter = 0;

  Serial.print("Connecting to AWS IoT...");

  // configure WiFiClientSecure with our AWS credentials
  wifiClient.setCACert(AWS_CERT_CA);
  wifiClient.setCertificate(AWS_CERT_DEVICE);
  wifiClient.setPrivateKey(AWS_CERT_PRIVATE);

  // connect to mqtt broker on AWS endpoint on port 8883
  mqttClient.setServer(AWS_ENDPOINT, 8883);

  // set callback function
  mqttClient.setCallback(callback);

  // now try to connect
  while (!mqttClient.connected()) {
    if (mqttClient.connect(THINGNAME)) {
      Serial.println("Connected\n");

      // subscribe to our topic
      mqttClient.subscribe(CMD_TOPIC);
    }
    else {
      // didn't connect, so wait and try again
      Serial.print(".");
      counter++;
      delay(500);

      if (counter >= 60) {
        Serial.print("Faled to connect to AWS, rc=");
        Serial.println(mqttClient.state());
        ESP.restart();
      }
    }
  }
}

void setup() {
  // initialize serial monitor for debug outptu
  Serial.begin(115200);
  delay(10);

  // configure IO pins
  pinMode(forward, OUTPUT);
  pinMode(reverse, OUTPUT);

  // turn LEDs off
  digitalWrite(forward, LOW);
  digitalWrite(reverse, LOW);

  // connect to wifi
  reconnectWiFi();

  // connect to a time server using UTC timezone
  configTime(0, 0, "pool.ntp.org");

}

void loop() {
  // connect to wifi if necessary
  if (WiFi.status() != WL_CONNECTED) {
    reconnectWiFi();
  }

  // connect to mqtt broker if necessary
  if (!mqttClient.connected()) {
    reconnectAWS();
  }

  // handle any mqtt traffic
  mqttClient.loop();

}
