int numbers[16] = {
    63,  // 0
    6,   // 1
    91,  // 2
    79,  // 3
    102, // 4
    109, // 5
    125, // 6
    7,   // 7
    127, // 8
    103, // 9
    123, // a
    124, // b
    57,  // c
    94,  // d
    121, // e
    113  // f
};

// Pin connected to ST_CP
int latchPin = 8;
// Pin connected to SH_CP
int clockPin = 12;
// Pin connected to DS
int dataPin = 11;


void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}


int convert(int i) {
    if (i < 0 || i > 15) i = i % 16;
    return numbers[i % 16];
}

int count = 0;
void loop() {
    int data = convert(count++);
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, data);  

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(500);
}
