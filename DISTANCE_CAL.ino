#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const int trigPin = 9;
const int echoPin = 10;
long duration;
int Cm,Inch;
void setup() {
lcd.begin(16,2); // Initializes the dimensions of LCD screen
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Cm= duration*0.034/2;
  Inch = duration*0.0133/2;
  lcd.setCursor(0,0); 
  lcd.print("Distance: "); 
  lcd.print(Cm);
  lcd.print(" cms");
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  lcd.print(Inch);
  lcd.print(" inches");
  delay(10);
}
