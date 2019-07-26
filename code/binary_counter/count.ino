// Pin connected to ST_CP
int latchPin = 12;
// Pin connected to SH_CP
int clockPin = 8;
// Pin connected to DS
int dataPin = 11;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
    int i;
    for (i = 0; i < 256; i++) {
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, i);
        digitalWrite(latchPin, HIGH);
        delay(100);
    }
}
