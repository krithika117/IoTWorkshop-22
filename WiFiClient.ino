
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
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    
}

int value = 0;

void loop() {
  for(int i = 0; i< 10; i++){
      Firebase.setInt(fbdo,"/testerval/IoT",i);  
      delay(1000);
    }
    Firebase.setString(fbdo,"testerval/String","IoTTest");
}
