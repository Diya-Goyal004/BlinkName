// Define constants
const int ledPin = LED_BUILTIN;  // Built-in LED pin
const int buttonPin = 2;  // Push button pin

boolean ledState = LOW;
boolean lastButtonState = LOW;
boolean buttonState;

const char* morseCode = ". -.. .. -.-";  // Morse code for "DIYA"
int morseIndex = 0;
unsigned long previousMillis = 0;
const long dotDuration = 200;
const long dashDuration = dotDuration * 3;
const long spaceDuration = dotDuration * 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    morseIndex = 0;
    blinkMorseMessage(morseCode);
  }
  
  lastButtonState = buttonState;
}

void blinkMorseMessage(const char* message) {
  for (int i = 0; message[i] != '\0'; i++) {
    char c = message[i];
    if (c == '.') {
      blinkDot();
    } else if (c == '-') {
      blinkDash();
    } else if (c == ' ') {
      delay(spaceDuration * 3);
    }
  }
}

void blinkDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(spaceDuration);
}

void blinkDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(spaceDuration);
}
