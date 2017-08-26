// pin number 3
  int greenLED = 3;

  // in milliseconds
  int blinkPeriod = 500;  

void setup() {
  // put your setup code here, to run once:

  
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenLED, HIGH);
  delay(blinkPeriod);
  digitalWrite(greenLED, LOW);
  delay(blinkPeriod);
}
