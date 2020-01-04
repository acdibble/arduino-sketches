int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

int state = HIGH;
bool stillPushed = false;

void loop()
{
  if (digitalRead(buttonBpin) == LOW)
  {
    if (!stillPushed) {
      state ^= 1;
      digitalWrite(ledPin, state);
    }
    stillPushed = true;
  } else {
    stillPushed = false;
  }
}
