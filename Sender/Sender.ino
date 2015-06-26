int Pin = 3;    // LED connected to digital pin 9

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    byte b = Serial.read();
    send(b, 10000);
  }
}

void send(byte A, int freq) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(Pin, HIGH);
    if (bitRead(A, i))
      delayMicroseconds(2 * freq);
    else
      delayMicroseconds(1 * freq);
    digitalWrite(Pin, LOW);
    delayMicroseconds(1 * freq);
  }
  digitalWrite(Pin, HIGH);
  delayMicroseconds(3 * freq);
  digitalWrite(Pin, LOW);

  Serial.print((char)A);
  delayMicroseconds(1 * freq);
}

