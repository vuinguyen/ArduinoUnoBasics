int ledPin = 3;
int potPin = A0;
float potValue = 0;

float minPotValue = 0;
float maxPotValue = 1023;

int greenLED = 3;
int yellowLED = 5;
int redLED = 6;

int ledPins[] = {
  greenLED, yellowLED, redLED
}; 

int pinCount = sizeof(ledPins) / sizeof(int);

int third = maxPotValue / pinCount;

// a duty cycle of 100% is 255 in Arduino Land
int maxDutyCycle = 255;

void setup() {
  // put your setup code here, to run once:
  //start serial connection
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);

  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the value from the sensor:
  potValue = analogRead(potPin);
  String message = "potValue: ";
  message += potValue;
  Serial.println(message);

  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    float remainder = potValue - ( (thisPin * maxPotValue) / (float)pinCount );
    /*
    message = "remainder ";
    message += thisPin;
    message += " : ";
    message += remainder;
    */
    
    //Serial.println(message);
    //delay(200);
    if (remainder >= third) {
      digitalWrite(ledPins[thisPin], HIGH);
    } else if (remainder <= 0) {
      digitalWrite(ledPins[thisPin], LOW);
    } else {
      int percentage = ( (remainder * maxDutyCycle) / third);
      analogWrite(ledPins[thisPin], percentage);
    }
    
  }
}
