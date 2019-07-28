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

class SevenSegment {
    public:
        int latchPin;
        int clockPin;
        int dataPin;

        SevenSegment(int lp, int cp, int dp) {
          latchPin = lp;
          clockPin = cp;
          dataPin = dp;
        }

        void write(int data) {
          // 1. Set the latch to LOW
          digitalWrite(latchPin, LOW);

          // 2. shift out the bits
          shiftOut(dataPin, clockPin, MSBFIRST, data); 

          // 3. set latch pin HIGH
          digitalWrite(latchPin, HIGH);
        }
};

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
int latchPin1 = 5;
// Pin connected to SH_CP
int clockPin1 = 6;
// Pin connected to DS
int dataPin1 = 7;

int latchPin2 = 8;
int clockPin2 = 9;
int dataPin2 = 10;


void setup() {
  pinMode(latchPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);
  pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
}

SevenSegment *leftSeg = new SevenSegment(latchPin1, clockPin1, dataPin1);
SevenSegment *rightSeg = new SevenSegment(latchPin2, clockPin2, dataPin2);
void loop() {
    int l, r;
    for (l = 0; l < 16; l++) {
      for (r = 0; r < 16; r++) {
        leftSeg->write(numbers[l]);
        rightSeg->write(numbers[r]);
        delay(250);
      }
    }
}