int red = 7;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {                  
    String receivedString = Serial.readString();  
    receivedString.trim();  // Boşlukları ve satır sonlarını kaldır

    Serial.print("You typed: ");
    Serial.println(receivedString);  // Gelen veriyi ekrana yazdır

    if (receivedString == "SOS") {  
      soscode(red);  
    }
  }
}

void soscode(int x) {
  for (int i = 0; i < 3; i++) {  
    digitalWrite(x, HIGH);
    delay(200);
    digitalWrite(x, LOW);
    delay(500);
  }

  for (int i = 0; i < 3; i++) {  
    digitalWrite(x, HIGH);
    delay(700);
    digitalWrite(x, LOW);
    delay(500);
  }

  for (int i = 0; i < 3; i++) {  
    digitalWrite(x, HIGH);
    delay(200);
    digitalWrite(x, LOW);
    delay(500);
  }
}
