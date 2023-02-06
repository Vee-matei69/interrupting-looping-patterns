const int buttonPin = 2; // the number of the pushbutton pin
const int ledPins[] = {3, 4, 5, 6, 7, 8, 9}; // the number of the LED pins
int ledCount = 7; // number of LEDs
int blinkFrequency = 1000; // frequency of LED blinking
int pattern = 1; // starting pattern
int buttonState = 0; // variable for reading the pushbutton status
long pressTime = 0; // variable to store the time of a long press
int debounceDelay = 50; // debounce time in milliseconds

void setup() {
  // initialize the LED pins as outputs:
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // attach interrupt to the button pin
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeBlink, CHANGE);
}

void loop() {
  switch (pattern) {
    case 1:
      // looping pattern 1
      for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledPins[i], HIGH);
        delay(blinkFrequency);
        digitalWrite(ledPins[i], LOW);
        delay(blinkFrequency);
      }
      break;
    case 2:
      // looping pattern 2
      for(int i=7; i>3; i--)
     {      
      digitalWrite(ledPins[i],HIGH);
      delay(blinkFrequency);
      digitalWrite(ledPins[i],LOW);
      delay(blinkFrequency);
        
      }
      break;
    case 3:
      // looping pattern 3
       for(int i=3; i<=9; i++)
    {
      digitalWrite(i,HIGH);
      digitalWrite(i-1,HIGH);
      digitalWrite(i+1,HIGH);
      delay(blinkFrequency);
      digitalWrite(i,LOW);
      digitalWrite(i-1,LOW);
      digitalWrite(i+1,LOW);
      }
      delay(blinkFrequency * 2);
      break;
    case 4:
      // looping pattern 4
      for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledPins[ledCount - i - 1], HIGH);
        delay(blinkFrequency);
        digitalWrite(ledPins[ledCount - i - 1], LOW);
        delay(blinkFrequency);
      }
      break;
    case 5:
      // looping pattern 5
      for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledPins[ledCount - i - 1], HIGH);
        delay(blinkFrequency);
        digitalWrite(ledPins[ledCount - i - 1], LOW);
      }
      delay(blinkFrequency);
      break;
  }
}

// interrupt function to change blink frequency or pattern
void changeBlink() {
  
buttonState = digitalRead(buttonPin);
  
  // Check if the button was pressed or released
  if (buttonState == LOW) {
    // Check if the button was held for a long time
    if (millis() - pressTime >= 2000) {
      // Change to the next pattern
      pattern = (pattern + 1) % 5;
    } else {
      // Change to the next frequency
      blinkFrequency = 2000;
      if (blinkFrequency = 2000)
         blinkFrequency = 500;      
     
      
    }
  }
}