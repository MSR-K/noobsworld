void setup() {
 pinMode(1,INPUT);
 pinMode(2,INPUT);
 pinMode(13,OUTPUT);
}
int b1=0,b2=0;
void loop() {
  // put your main code here, to run repeatedly:
  b1=digitalRead(1);
  b2=digitalRead(2);
  if(b1==HIGH && b2==HIGH)
  {
    digitalWrite(13,HIGH);
  }
}
