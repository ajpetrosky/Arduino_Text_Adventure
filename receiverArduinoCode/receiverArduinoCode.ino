#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial  BTSerial(2, 3); //RX TX

const char p0[] PROGMEM = {"You wake up to a buzzing.\n\n\n"};
const char p1[] PROGMEM = {"The buzzing gets louder, you hear shouting out of your window.\n\n\n"};
const char p4[] PROGMEM = {"As you groggily drag yourself from your bed, you find that the noise is coming through your window. Confused you \nmove to open the curtains. However, before you do, your window is blown inward by a very loud sound of feedback. When the dust settles, you stand \nto see Vijay Kumar hovering, riding a drone outside your 17th story window, holding a megaphone. “You are to be expelled for forging meal \nswipes!” he shouts.  You know you cannot be expelled, your whole future depends on that $280,000 piece of paper. You have to \nthink quickly, your ese 190 lab is in a few minutes, that's it! Sid will save you! But you would have to get there before Vijay gets to you...\n"};
const char p5[] PROGMEM = {"Seeing your Spacex job flash before your eyes you panic and decide to end it all, but instead you land on a \nsurprisingly soft and oddly stationed halal cart. You roll off and start running toward Dedkin.\n\n\n"};
const char p6[] PROGMEM = {"You think quickly and bolt out the door. Unfortunately  for you, with his enhanced mobility, Vijay is waiting \nfor you. You book it down towards Detkin.\n\n\n"};
const char p7[] PROGMEM = {"You are approaching commons, and you realize you are starving.\n"};
const char p8[] PROGMEM = {"You run in to grab food, using your forged swipes to get in. As you are eating Vijay drops in from the skylight. \nHe moves to capture,  but upon seeing the food he is in shock, but not for long, you make your escape.\n\n\n"};
const char p9[] PROGMEM = {"Fight through the hunger!\n\n\n"};
const char p10[] PROGMEM = {"You see men working on locust, go around or run through?\n"};
const char p11[] PROGMEM = {"You stumble and bumble and fall. Vijay is gaining.\n\n\n"};
const char p12[] PROGMEM = {"You run around the maintenance but Vijays enhanced mobility keeps pace.\n\n\n"};
const char p13[] PROGMEM = {"You've made it out of Rodin, you've made it past commons, you are headed right towards Dedkin! You are about to \npass Fisher Fine arts, but wait! There is a tour group full of prospective victims outside of the Towne building, you certainly can't let them see \nthis, you are a fugitive! But maybe getting lost in a crowd is exactly what you need...\n\n\n"};
const char p14[] PROGMEM = {"As you get to about half way down the main hallway of Towne you notice a strange quiet. You are confused. Was this \nall a dream? Regardless you need to get to lab.\n\n\n"};
const char p15[] PROGMEM = {"God why did I forge those swipes? The food is awful anyway. Am I that cheap?” The words echo through your head as you\n round the corner with a damaged ankle. But damn, NCH is right there. Face it,  you're probably through anyway, might as well use the rest of \nthose fake swipes, right?\n\n\n"};
const char p16[] PROGMEM = {"You approach Dedkin, and still no sign of the Dean is to be had. Confused you move to open the door to the lab.\n\n\n"};
const char p17[] PROGMEM = {"With your last few forged swipes in hand you bolt through the walnut street traffic and head towards NCH. Vijay did not\n anticipate such a brazen act of shameless criminality, even from you. Nonetheless, he is far faster than you, and quickly is on your tail. \nYou are aching, your ankle is busted, you cough and wheeze as you sprint to the main door. 20ft, 10ft, 5ft, NO! Just as you nearly touch \nthe handle an arm extends from Vijay’s contraption and hoists you high into the air. “Where are you taking me!” you cry, to \nwhich the Dean responds: “To PERCH, through your true devotion to free horrid food you have proven to me that you are a perfect candidate\n to work in the lab.” You are confused but curious as you fly towards a land of Cheeto dust and Twix wrappers where the sun \nnever sets on research.\n\n\n "};
const char p19[] PROGMEM = {"Terrible pain is shooting up your body from your ankle. You turn around for a moment, Vijay is just behind you, his face \nis an expression of determination and disappointment, you were a good student in his school, but the Dean must protect the greater good, \nwhich you are no longer a part of. You reach your turn. Past the cherry trees, come on, there is the door! Just a few more paces! You grab \nthe handle and dart in. You turn to see that strangely Vijay isn't outside, in fact, he is no where to be seen...\n\n\n"};
const char p20[] PROGMEM = {"You pull open the door to Dedkin, out of breath and exhausted. Other students are there but you pay no attention to them. \nYou look around and spot Sid in his office, you're saved! You quickly head into the office, seeking asylum. Sid sees the state that you’re \nin, and asks you what happened.\n\n\n "};
const char p21[] PROGMEM = {"You break down and tell him everything, through your tears you confess to your crimes and beg for forgiveness, you tell him \nabout your hellish run here, your need for cheap food, the whole nine yards. Sid stays solemn the entire time you are telling him this, \nthat is, until he breaks down laughing. Before you can understand why, you hear another voice laughing, the door to the room behind the \noffice opens where you see Dean Kumar. You are frozen in fear, but before you run Vijay starts talking: “Calm down! You owned \nup to your crimes, and I can respect that. I'll lessen your punishment to getting banned from all places that accept swipes, sounds like a deal?\n\n\n"};
const char p22[] PROGMEM = {"You tell the lie and Sid expresses genuine concern. He tells you to go to the back room and wait for CPS. You open the door \nbut see a figure turned away in a chair. He slowly turns around. Color drains from your face. 'I am sorry it has to be this way'\n\n\n"};
const char p23[] PROGMEM = {"You are spared! You can now get to work on your final project! \n\n\n"};
const char p24[] PROGMEM = {"You got expelled. Congratulations!\n\n\n"};
const char* const messages[] PROGMEM = {p0, p1, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p19, p20, p21, p22, p23, p24};
char text[1000];

bool complete = false;
String stage = "";

void setup() {
  BTSerial.begin(9600); //begin bluetooth communication
  Serial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    char p = (char) BTSerial.read(); //reads single character at a time
    stage += p;
    if (p == '\n') {
       complete = true;
    }
  }
  if (complete) {
    int p = stage.toInt();
    if (p == 4) {
      p = 2;
    } else if (p == 5) {
      p = 3;
    } else if (p == 6) {
      p = 4;
    } else if (p == 7) {
      p = 5;
    } else if (p == 8) {
      p = 6;
    } else if (p == 9) {
      p = 7;
    } else if (p == 10) {
      p = 8;
    } else if (p == 11) {
      p = 9;
    } else if (p == 12) {
      p = 10;
    } else if (p == 13) {
      p = 11;
    } else if (p == 14) {
      p = 12;
    } else if (p == 15) {
      p = 13;
    } else if (p == 16) {
      p = 14;
    } else if (p == 17) {
      p = 15;
    } else if (p == 19) {
      p = 16;
    } else if (p == 20) {
      p = 17;
    } else if (p == 21) {
      p = 18;
    } else if (p == 22) {
      p = 19;
    } else if (p == 23) {
      p = 20;
    } else if (p == 24) {
      p = 21;
    }
    strcpy_P(text, (char*)pgm_read_word(&(messages[p])));
    Serial.println(text);
    complete = false;
    stage = "";
  }
}
