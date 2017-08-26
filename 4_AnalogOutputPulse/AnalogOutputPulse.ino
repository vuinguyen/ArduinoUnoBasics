int greenLED = 3;
int yellowLED = 5;
int redLED = 6;

// length of time to hold in the "off" state, for dramatic effect, in ms
int holdOffTime = 1000;

// period of the on-off pulse, in ms
int pulsePeriod = 2000;

// a duty cycle of 100% is 255 in Arduino Land
int maxDutyCycle = 255;
// a duty cycle of 0% is 0 in Arduino Land
int minDutyCycle = 0;
// number of jumps

int dutyCycleHold = (pulsePeriod / 2) / maxDutyCycle;

// current dutyCycle
int dutyCycle;

boolean turnUp;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  dutyCycle = 0;
  turnUp = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  // set the brightness of pin 9:
  analogWrite(greenLED, dutyCycle);
  analogWrite(yellowLED, dutyCycle);
  analogWrite(redLED, dutyCycle);

  if (dutyCycle >= maxDutyCycle) {
    turnUp = false;
  }
  else if (dutyCycle <= minDutyCycle) {
    turnUp = true;

    // if at bottom of dutyCycle, pause for dramatic effect)
    delay(holdOffTime);
  }

  if (turnUp == true) {
    dutyCycle += 1;
  }
  else {
    dutyCycle -= 1;
  }
  
  delay(dutyCycleHold);
}
