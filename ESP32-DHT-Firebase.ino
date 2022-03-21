#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

String a;
const char* ssid     = "COE CHROMIUM";
const char* password = "Welcome@123";
#define FIREBASE_HOST "iotworkshop-22-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "5xoFnqlK14kdCXMOQNd4U7Ozbfw6PSGKdw2oqK3g"
#define DHTPIN 2
#define DHTTYPE DHT11

FirebaseData fbdo;
DHT_Unified dht(DHTPIN, DHTTYPE);

void setup()
{   
    pinMode(2,OUTPUT);
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);    
    Firebase.reconnectWiFi(true);
    dht.begin();
}


void loop() {

  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float temp = event.temperature;
  
  dht.humidity().getEvent(&event);
  float humidity = event.relative_humidity;

  Firebase.setFloat(fbdo,"/Sensor/temp",temp);
  delay(1000);
  Firebase.setFloat(fbdo,"/Sensor/humidity",humidity);
  delay(1000);
  
  if(Firebase.getString(fbdo,"/LED/Demo")){
    a = fbdo.stringData();
    Serial.println(a);
    //delay(1000);
  }
//  if(a=="1"){
//    digitalWrite(2, HIGH);
//  }
//  else if(a=="0"){
//    digitalWrite(2, LOW);
//  }
}
