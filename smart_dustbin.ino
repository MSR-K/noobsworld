#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const int trigPin = 9;
const int echoPin = 10;
const int redLed = 4;
long duration;
int Cm,Inch;
void setup() {
lcd.begin(16,2); // Initializes the dimensions of LCD screen
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(redLed, OUTPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Cm= duration*0.034/2;
  

  if(Cm<5cm ||  Cm<0)   // when garbage reaches upto 5 cm from top
       {
      digitalWrite(redLed,HIGH); // glow the LEd
      tone(2, 940,1000);         //  Buzzer On
      delay(1000);
      digitalWrite(redLed,LOW);
      noTone(2);
      lcd.setCursor(0,0);
      lcd.setCursor(3,0);
      lcd.print("DUSTBIN FULL");    // Dustbin Full Status
      delay(1000);
      lcd.clear();
      
      }
      else
      {
      lcd.setCursor(0,0);
      lcd.setCursor(3,0);
      lcd.print("USE DUSTBIN");          // Use the Dustbin 
      delay(1000);
      lcd.clear();
      
      }
  
}
