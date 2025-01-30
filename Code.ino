int red = 7;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {                   // Eğer bilgisayardan veri geldiyse
    String receivedString = Serial.readString();  // Tüm gelen veriyi oku

    if (receivedString == "SOS" || receivedString == "sos") {                // "SOS" komutu geldiyse
      soscode(red);  // LED'i SOS koduyla yak
    }

    Serial.print("You typed: ");
    Serial.println(receivedString);  // Gelen veriyi ekrana yazdır
  }
}

void soscode(int x) {
  for (int i = 0; i < 3; i++) {  // 3 kısa yanıp sönme
    digitalWrite(x, HIGH);
    delay(200);
    digitalWrite(x, LOW);
    delay(500);
  }

  for (int i = 0; i < 3; i++) {  // 3 uzun yanıp sönme
    digitalWrite(x, HIGH);
    delay(700);
    digitalWrite(x, LOW);
    delay(500);
  }

  for (int i = 0; i < 3; i++) {  // 3 kısa yanıp sönme
    digitalWrite(x, HIGH);
    delay(200);
    digitalWrite(x, LOW);
    delay(500);
  }
}
