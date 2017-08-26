// configure button at pin 12
int button = 12;

int noLEDs = 0;
int greenLED = 3;
int yellowLED = 5;
int redLED = 6;

int timer;
int reverseTimer = 100;
int advanceTimer = 300;           // The higher the number, the slower the timing.
int ledPins[] = {
  noLEDs, greenLED, yellowLED, redLED
};       // an array of pin numbers to which LEDs are attached
int pinCount;            // the number of pins (i.e. the length of the array)



int position;

void setup() {
  //start serial connection
  Serial.begin(9600);

  position = 0;
  timer = advanceTimer;
/*
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
*/
// sizeof gets the size in bytes because there is
// no length() function
pinCount = sizeof(ledPins) / sizeof(int);

   for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
   
  // Arduino doesn't have a built-in pulldown in the board
  pinMode(button, INPUT_PULLUP);  
}

int advance(int thisPosition) {
  int nextPosition;
  if (thisPosition < pinCount - 1) {
    nextPosition = thisPosition + 1;
  }
  else {
    nextPosition = 0;
  }
  return nextPosition;
}

int reverse(int thisPosition) {
  int nextPosition;
  if (thisPosition > 0) {
    nextPosition = thisPosition - 1;
  }
  else {
    nextPosition = pinCount - 1;
  }
  return nextPosition;
}

void loop() {
  //read the pushbutton value into a variable
  int buttonVal = digitalRead(button);
  //print out the value of the pushbutton
  //Serial.println(buttonVal);

  // loop from the lowest pin to the highest:
  
    digitalWrite(ledPins[position], HIGH);
    String message = "position: ";
    message += position;
    Serial.println(message);
    String pinCountMessage = "PinCount: ";
    pinCountMessage += pinCount;
    Serial.println(pinCountMessage);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[position], LOW);

    if (buttonVal == HIGH) {
      position = advance(position);
      timer = advanceTimer;
    }
    else {
      position = reverse(position);
      timer = reverseTimer;
    }

  

/*
  // loop from the highest pin to the lowest:
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }
  */
}
