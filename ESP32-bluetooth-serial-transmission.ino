#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("Krithika :)"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(SerialBT.available()){
  String data = SerialBT.readString();
  Serial.println("Data: " + data);
  }
}
