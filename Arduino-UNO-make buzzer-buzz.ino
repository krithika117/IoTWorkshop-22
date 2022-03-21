#define ir 6
#define buzzer 7
int x;
void setup() {
 
  // put your setup code here, to run once:
pinMode(ir,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
  x=digitalRead(ir);
  if(x==0){
  digitalWrite(buzzer,HIGH);
  }

  else if(x==1){
  digitalWrite(buzzer,LOW);
  }
Serial.println(digitalRead(ir));
delay(100);
}
