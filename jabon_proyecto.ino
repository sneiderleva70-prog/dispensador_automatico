#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
Servo servo1;
int sensor2 = 8;
int sensor = 11;
int rele1 = 10;
int estado = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(rele1, OUTPUT);
  servo1.attach(9);
  lcd.begin(16, 2); 
}

void loop() {

  
estado=digitalRead(sensor);
if(estado==LOW)
{
  lcd.clear();
  lcd.setCursor(0,2);
  lcd.print("LAVANDO MANOS");
  digitalWrite(rele1, HIGH);
  delay(5000); 
}
else
{
  lcd.clear();
  lcd.setCursor(0,3);
  lcd.print("BIENVENIDOS");
  digitalWrite(rele1, LOW);    
}



estado=digitalRead(sensor2);
if(estado==LOW)
{
  delay(2000);
  servo1.write(180);
  delay(1500);

}
else
{
  servo1.write(0);
}
}
