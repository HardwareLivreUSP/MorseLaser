
unsigned long time;
unsigned long delta;
int estado = 0;
int Pin = A0;

byte A;
int count = 0;
int freq = 80;
int sensorMax = 2000;

void setup()
{
  Serial.begin(9600);
  time = millis();
  delay(200);

  while (millis() < 5000) {
    int sensorValue = analogRead(Pin);

    // record the maximum sensor value
    if (sensorValue < sensorMax) {
      sensorMax = sensorValue;
    }
  }

  sensorMax *= 0.85;
  Serial.println("RECEBENDO...");

}

void loop() {
  int a;
  int b = analogRead(Pin);

  time = micros();
  while (analogRead(Pin) < sensorMax);

  delta = micros() - time;
  if (delta > 150) {
    //Serial.println(delta);
    if (count == 8 || delta > 30000) {
      Serial.print((char)A);
      count = 0;
      A = 0;
    } else if (delta > 20000) {
      bitSet(A, count);
      count++;
    } else {
      bitClear(A, count);
      count++;
    }
  }

  /*
    if(b<sensorMax){

        estado = a;
        int delta = millis()-time;
        time = millis();
        if(delta>5){
          Serial.println(delta);
        }
        if(a == 1 && delta < 2*freq*1.2 && delta > 2*freq*0.8){
          bitSet(A, count);
          count++;
        } else if(a == 1 && delta < freq*1.2 && delta > freq*0.8){
          bitClear(A, count);
          count++;
        }

        if(a==0&&delta>3*freq*1.2 || count == 8){
          if(count == 8)
            Serial.print((char)A);
          A = 0;
          count = 0;
        }
    }
    */
}

