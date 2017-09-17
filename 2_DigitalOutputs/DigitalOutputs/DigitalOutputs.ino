// Light up a series of LEDs, one at a time, in round robin fashion

int greenLED = 3;
int yellowLED = 5;
int redLED = 6;

int greenLEDState;
int yellowLEDState;
int redLEDState;

int blinkPeriod = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  greenLEDState  = digitalRead(greenLED);
  yellowLEDState = digitalRead(yellowLED);
  redLEDState    = digitalRead(redLED);

  if (greenLEDState == 1) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else if (yellowLEDState == 1) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else if (redLEDState == 1) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }
 
  delay(blinkPeriod);
}
