int ledPin = 2;
int ldrPin = A0;

void setup() {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);

pinMode(ldrPin, INPUT);

}

void loop() {

int Darkness = analogRead(ldrPin);

if (ldrStatus <= 50) {
digitalWrite(ledPin, HIGH);
delay(200);
Serial.print(" Turn on the LED : ");

Serial.println(ldrStatus);

} else {

digitalWrite(ledPin, LOW);

Serial.print(" Turn off the LED : ");

Serial.println(ldrStatus);

}

}
