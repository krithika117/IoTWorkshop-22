#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);
float x;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
}

void loop() {
 
  // put your main code here, to run repeatedly:
x=analogRead(A1);
float volt= x*(0.0048828125);
float mv= volt*1000;
float degree= mv/10;

  // Turn on the blacklight and print a message.
lcd.print("Temp: ");
lcd.setCursor(1,1);
lcd.print(degree);
delay(10000);
lcd.clear();
}
