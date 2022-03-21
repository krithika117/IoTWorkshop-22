#include <WiFi.h>
#include <FirebaseESP32.h>

const char* ssid     = "COE CHROMIUM";
const char* password = "Welcome@123";
#define FIREBASE_HOST "iotworkshop-22-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "5xoFnqlK14kdCXMOQNd4U7Ozbfw6PSGKdw2oqK3g"

FirebaseData fbdo;

void setup()
{   
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);    
}


void loop() {
  if(Firebase.getString(fbdo,"/LED/Demo")){
  String a = fbdo.stringData();
  Serial.println(a);
  }
}
