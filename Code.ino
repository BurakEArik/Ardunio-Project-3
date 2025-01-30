int red = 7;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {                   // If data came from the computer
    String receivedString = Serial.readString();  // Read all incoming data

    if (receivedString == "SOS" || receivedString == "sos") {                // If the "SOS" command came
      soscode(red);  // Light up the LED with SOS code
    }

    Serial.print("You typed: ");
    Serial.println(receivedString);  // Print incoming data to the screen
  }
}

void soscode(int x) {
  for (int i = 0; i < 3; i++) {  // 3 short flashes
    digitalWrite(x, HIGH);
    delay(200);
    digitalWrite(x, LOW);
    delay(500);
  }

  for (int i = 0; i < 3; i++) {  // 3 long flashes
    digitalWrite(x, HIGH);
    delay(700);
    digitalWrite(x, LOW);
    delay(500);
  }

  for (int i = 0; i < 3; i++) {  // 3 short flashes
    digitalWrite(x, HIGH);
    delay(200);
    digitalWrite(x, LOW);
    delay(500);
  }
}
