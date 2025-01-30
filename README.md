# Ardunio-Project-3
This project use lamp and Serial command prompt for make S.O.S. code.

# Components Used
- 1x LED whatever color you want
- 1x 330 ohm resistance
- Wires
- Ardunio R3

# Circuit Diagram
![Circuit Diagram](circuit.png)

# Code
```cpp
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
```
# How to Install
1. Setup circuit same as diagram with componeents
2. Upload the ![code](Code.ino)
