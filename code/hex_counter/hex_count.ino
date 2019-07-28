/****
 * 
 *  The 7 segment display is divided as such:
 *      A
 *   -------
 * F |     | B
 *   |  G  |
 *   -------
 * E |     | C
 *   |     |
 *   -------  0 DP
 *      D
 * 
 *   Finding a display pattern (e.g. the number 2):
 * 
 *        A
 *     -------
 *           | B
 *        G  |
 *     -------
 *   E |
 *     |
 *     -------
 *        D
 * 
 *  1. Follow, in alphabetic order:
 * 
 *      a b c d e f g dp
 *      1 1 0 1 1 0 1 0
 * 
 *  2. Then reverse it:
 * 
 *      01011011
 * 
 *  3. Convert to decimal or hex
 * 
 *     DEC: 91
 *     HEX: 5B
 * 
 *  4. Shift out that number
 */

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
    119, // a
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

int count = 0;
void loop() {
    // 1. Get data to shift out
    int data = numbers[count++ % 16];

    // 2. Set the latch to LOW
    digitalWrite(latchPin, LOW);

    // 3. shift out the bits
    shiftOut(dataPin, clockPin, MSBFIRST, data); 

    // 4. set latch pin HIGH
    digitalWrite(latchPin, HIGH);

    // 5. pause before next value
    delay(250);
}
