const int buttonPin = 2;
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;

bool ledState = LOW;
bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    ledState = !ledState;

    digitalWrite(led1, ledState);
    digitalWrite(led2, ledState);
    digitalWrite(led3, ledState);

    delay(200); // debounce
  }

  lastButtonState = buttonState;
}
