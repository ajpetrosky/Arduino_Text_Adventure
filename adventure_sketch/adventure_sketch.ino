#include <Arduino.h>
#include <Button.h>

// Messages to be displayed for each room
const char p0[] PROGMEM = {"Area 0"};
const char p1[] PROGMEM = {"Area 1"};
const char p2[] PROGMEM = {"Area 2"};
const char p3[] PROGMEM = {"Area 3"};
const char p4[] PROGMEM = {"Area 4"};
const char p5[] PROGMEM = {"Area 5"};
const char p6[] PROGMEM = {"Area 6"};
const char p7[] PROGMEM = {"Area 7"};
const char p8[] PROGMEM = {"Area 8"};
const char p9[] PROGMEM = {"Area 9"};
const char p10[] PROGMEM = {"Area 10"};
const char p11[] PROGMEM = {"Area 11"};
const char p12[] PROGMEM = {"Area 12"};
const char p13[] PROGMEM = {"Area 13"};
const char p14[] PROGMEM = {"Area 14"};
const char p15[] PROGMEM = {"Area 15"};
const char p16[] PROGMEM = {"Area 16"};
const char p17[] PROGMEM = {"Area 17"};
const char p18[] PROGMEM = {"Area 18"};
const char p19[] PROGMEM = {"Area 19"};
const char p20[] PROGMEM = {"Area 20"};
const char p21[] PROGMEM = {"Area 21"};
const char p22[] PROGMEM = {"Area 22"};
const char p23[] PROGMEM = {"Area 23"};
const char p24[] PROGMEM = {"Area 24"};
const char* const messages[] PROGMEM = {p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24};

// Buffer PROGMEM will store the current LCD text to
char text[80];

// Game variables
int p = 0; // The player's current stage in the game
int distFromDean = 10; //The players distance from the dean, game over when 0

const int rightButtonPin = 2;
int rightButtonState = LOW;
const int leftButtonPin = 12;
int leftButtonState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(rightButtonState, INPUT);
  pinMode(leftButtonState, INPUT);
}

void loop() {
  if (p == 0) {
    printMessage();
  } else if (p == 1) {
    printMessage();
  } else if (p == 2) {
    printMessage();
  } else if (p == 3) {
    printMessage();
  } else if (p == 4) {
    printMessage();
  } else if (p == 5) {
    printMessage();
  } else if (p == 6) {
    printMessage();
  } else if (p == 7) {
    printMessage();
  } else if (p == 8) {
    printMessage();
  } else if (p == 9) {
    printMessage();
  } else if (p == 10) {
    printMessage();
  } else if (p == 11) {
    printMessage();
  } else if (p == 12) {
    printMessage();
  } else if (p == 13) {
    printMessage();
  } else if (p == 14) {
    printMessage();
  } else if (p == 15) {
    printMessage();
  } else if (p == 16) {
    printMessage();
  } else if (p == 17) {
    printMessage();
  } else if (p == 18) {
    printMessage();
  } else if (p == 19) {
    printMessage();
  } else if (p == 20) {
    printMessage();
  } else if (p == 21) {
    printMessage();
  } else if (p == 22) {
    printMessage();
  } else if (p == 23) {
    printMessage();
    p = 0;
  } else if (p == 24) {
    printMessage();
    p = 0;
  } else if (p == -1) {
    printMessage();
  }

  delay(500);
}

void printMessage() {
  strcpy_P(text, (char*)pgm_read_word(&(messages[p])));
  Serial.println(text);
  while (true) {
    rightButtonState = digitalRead(rightButtonPin);
    leftButtonState = digitalRead(leftButtonPin);
    if (rightButtonState == HIGH) {
      p = p + 1;
      break;
    } else if (leftButtonState == HIGH) {
      p = p + 2;
      break;
    } 
  }
  rightButtonState = LOW;
  leftButtonState = LOW;
}
