// Joystick
int VRx = 12;
int VRy = 13;
int SW = 15;

// LED pins
int redLEDPin = 22;
int yellowLEDPin = 2;
int greenLEDPin = 21;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
  pinMode(redLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
}

void loop() {
  int xValue = analogRead(VRx);
  int yValue = analogRead(VRy);
  int buttonState = digitalRead(SW);

  Serial.print(xValue);
  Serial.print(",");
  Serial.print(yValue);
  Serial.print(",");
  Serial.println(buttonState);

  // Turn off all LEDs
  digitalWrite(redLEDPin, LOW);
  digitalWrite(yellowLEDPin, LOW);
  digitalWrite(greenLEDPin, LOW);

  if (Serial.available()) {
    char receivedChar = Serial.read();
    
    // Turn on the corresponding LED based on the received character
    if (receivedChar == 'y') {
      digitalWrite(yellowLEDPin, HIGH);
    } else if (receivedChar == 'g') {
      digitalWrite(greenLEDPin, HIGH);
    } else if (receivedChar == 'r') {
       digitalWrite(redLEDPin, HIGH);
    } else if (receivedChar == 'x') {
       for (int i = 0; i < 18; i++) {
        digitalWrite(greenLEDPin, HIGH);
        delay(100);
        digitalWrite(greenLEDPin, LOW);
        digitalWrite(yellowLEDPin, HIGH);
        delay(100);
        digitalWrite(yellowLEDPin, LOW);
        digitalWrite(redLEDPin, HIGH);
        delay(100);
        digitalWrite(redLEDPin, LOW);
       }
    }
  }

  delay(100);
}
