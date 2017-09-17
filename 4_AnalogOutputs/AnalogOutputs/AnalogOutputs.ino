// Lights up a group of LEDs all at once, 
// at different intervals/steps, from dimmest to brightest
// and back to dim again

int greenLED = 3;
int yellowLED = 5;
int redLED = 6;

// define the length of time to hold a single duty cycle, in ms
int dutyCycleHoldPeriod = 1000;

// a duty cycle of 100% is 255 in Arduino Land
int maxDutyCycle = 255;
// a duty cycle of 0% is 0 in Arduino Land
int minDutyCycle = 0;
// number of jumps
int numDutyCycles = 5;
// the amount we will increment or decrement the duty cycle each time
int dutyCycleJump = maxDutyCycle / numDutyCycles;

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
  analogWrite(greenLED, dutyCycle);
  analogWrite(yellowLED, dutyCycle);
  analogWrite(redLED, dutyCycle);

  if (dutyCycle >= maxDutyCycle) {
    turnUp = false;
  }
  else if (dutyCycle <= minDutyCycle) {
    turnUp = true;
  }

  if (turnUp == true) {
    dutyCycle += dutyCycleJump;
  }
  else {
    dutyCycle -= dutyCycleJump;
  }
  
  delay(dutyCycleHoldPeriod);
}
