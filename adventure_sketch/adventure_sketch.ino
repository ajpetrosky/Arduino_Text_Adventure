#include <Arduino.h>
#include <Button.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7, 6);

// Messages to be displayed for each room
const char p0[] PROGMEM = {"Y:Wake up and look?"};
const char p1[] PROGMEM = {"Y:Look?"};
const char p4[] PROGMEM = {"Y:Out the window!"};
const char p7[] PROGMEM = {"Y:Eat!"};
const char p10[] PROGMEM = {"Y:Go through"};
const char p13[] PROGMEM = {"Y:Through the crowd"};
const char p14[] PROGMEM = {"Y:Take Towne hallway"};
const char p15[] PROGMEM = {"Y:Use the swipes!"};
const char p16[] PROGMEM = {"Y/W:Open door"};
const char p17[] PROGMEM = {"Y/W:Restart"};
const char p19[] PROGMEM = {"Y/W:Go towards lab"};
const char p20[] PROGMEM = {"Y:Tell the truth"};
const char p21[] PROGMEM = {"Y:Sure does!"};
const char p22[] PROGMEM = {"Y/W:Restart"};
const char p23[] PROGMEM = {"Y/W:Restart"};
const char p24[] PROGMEM = {"Y/W:Restart"};
const char p0w[] PROGMEM = {"W:Stay in bed?"};
const char p1w[] PROGMEM = {""};
const char p4w[] PROGMEM = {"W:Run! The stairs!"};
const char p7w[] PROGMEM = {"W:Keep hauling!"};
const char p10w[] PROGMEM = {"W:Go around"};
const char p13w[] PROGMEM = {"W:Down the stairs!"};
const char p14w[] PROGMEM = {"W:Go down and left"};
const char p15w[] PROGMEM = {"W:Class > Food"};
const char p16w[] PROGMEM = {""};
const char p17w[] PROGMEM = {""};
const char p19w[] PROGMEM = {""};
const char p20w[] PROGMEM = {"W:Lie to Sid"};
const char p21w[] PROGMEM = {"W:That sounds lame!"};
const char p22w[] PROGMEM = {""};
const char p23w[] PROGMEM = {""};
const char p24w[] PROGMEM = {""};
const char* const messages[] PROGMEM = {p0, p1, p4, p7, p10, p13, p14, p15, p16, p17, p19, p20, p21, p22, p23, p24};
const char* const messagesW[] PROGMEM = {p0w, p1w, p4w, p7w, p10w, p13w, p14w, p15w, p16w, p17w, p19w, p20w, p21w, p22w, p23w, p24w};

// Buffer PROGMEM will store the current LCD text to
char choices[40];
char choicesW[40];

// Game variables
int p = 0; // The player's current stage in the game

const int rightButtonPin = 5;
int rightButtonState = LOW;
const int leftButtonPin = 13;
int leftButtonState = LOW;
SoftwareSerial  BTSerial(2, 3); //RX TX

void setup() {
  lcd.begin(20, 4);
  BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(rightButtonState, INPUT);
  pinMode(leftButtonState, INPUT);
}

void loop() {
  if (p == 0) {
    printMessage(4,1);
  } else if (p == 1) {
    printMessage(4,4);
  } else if (p == 4) {
    printMessage(7,7);
  } else if (p == 7) {
    printMessage(10,10);
  } else if (p == 10) {
    printMessage(13,13);
  } else if (p == 13) {
    printMessage(14,15);
  } else if (p == 14) {
    printMessage(16,16);
  } else if (p == 15) {
    printMessage(17,19);
  } else if (p == 16) {
    printMessage(20,20);
  } else if (p == 17) {
    printMessage(0,0);
  } else if (p == 19) {
    printMessage(16,16);
  } else if (p == 20) {
    printMessage(21,22);
  } else if (p == 21) {
    printMessage(23,24);
  } else if (p == 22) {
    printMessage(0,0);
  } else if (p == 23) {
    printMessage(0,0);
  } else if (p == 24) {
    printMessage(0,0);
  }

  delay(500);
}

void printMessage(int delta1, int delta2) {
  int index = p;
  if (p == 4) {
    index = 2;
  } else if (p == 7) {
    index = 3;
  } else if (p == 10) {
    index = 4;
  } else if (p == 13) {
    index = 5;
  } else if (p == 14) {
    index = 6;
  } else if (p == 15) {
    index = 7;
  } else if (p == 16) {
    index = 8;
  } else if (p == 17) {
    index = 9;
  } else if (p == 19) {
    index = 10;
  } else if (p == 20) {
    index = 11;
  } else if (p == 21) {
    index = 12;
  } else if (p == 22) {
    index = 13;
  } else if (p == 23) {
    index = 14;
  } else if (p == 24) {
    index = 15;
  }
  strcpy_P(choices, (char*)pgm_read_word(&(messages[index])));
  strcpy_P(choicesW, (char*)pgm_read_word(&(messagesW[index])));
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(choices);
  lcd.setCursor(0, 2);
  lcd.print(choicesW);
  String pStr = String(p);
  BTSerial.println(pStr);
  
  while (true) {
    rightButtonState = digitalRead(rightButtonPin);
    leftButtonState = digitalRead(leftButtonPin);
    if (rightButtonState == HIGH) {
      if (p == 4) {
        BTSerial.println("5");
      } else if (p == 7) {
        BTSerial.println("8");
      } else if (p == 10) {
        BTSerial.println("11");
      }
      p = delta1;
      break;
    } else if (leftButtonState == HIGH) {
      if (p == 4) {
        BTSerial.println("6");
      } else if (p == 7) {
        BTSerial.println("9");
      } else if (p == 10) {
        BTSerial.println("12");
      }
      p = delta2;
      break;
    } 
  }
  rightButtonState = LOW;
  leftButtonState = LOW;
}
