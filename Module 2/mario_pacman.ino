// Joystick
int VRx = 2;
int VRy = 15;
int SW = 13;

// LED pins
int redLEDPin = 32;
int yellowLEDPin = 33;
int greenLEDPin = 25;

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

  if (Serial.available()) {
    char receivedChar = Serial.read();
    
    // Turn off all LEDs
    digitalWrite(redLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
    
    // Turn on the corresponding LED based on the received character
    if (receivedChar == 'r') {
      digitalWrite(redLEDPin, HIGH);
    } else if (receivedChar == 'y') {
      digitalWrite(yellowLEDPin, HIGH);
    } else if (receivedChar == 'g') {
      digitalWrite(greenLEDPin, HIGH);
    }
  }

  delay(100);
}
