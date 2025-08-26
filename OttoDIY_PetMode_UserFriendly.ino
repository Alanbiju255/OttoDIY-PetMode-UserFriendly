//------------------------------------------------------------------
// Otto DIY Pet Mode — User Friendly
// Commands over BT (9600):
//   forward, backward, left, right, jump, dance, sing, happy, sad, sleep
// made by alan 
//------------------------------------------------------------------
#include <SoftwareSerial.h>
#include <Otto.h>

SoftwareSerial BT(11, 12);   // RX=12, TX=11
Otto OttoBot;

// ---- Pins ----
#define LeftLeg   9
#define RightLeg  2
#define LeftFoot  7
#define RightFoot 5
#define Buzzer    13

// ---- State ----
unsigned long lastCmd = 0;
const unsigned long idleTimeout = 6000UL;

// --- Helpers ---
void doCommand(String cmd){
  cmd.toLowerCase();  // ignore case
  if (cmd == "forward")   OttoBot.walk(1, 1000, 1);
  else if (cmd == "backward") OttoBot.walk(1, 1000, -1);
  else if (cmd == "left")     OttoBot.turn(1, 1000, -1);
  else if (cmd == "right")    OttoBot.turn(1, 1000, 1);
  else if (cmd == "jump")     OttoBot.jump(1, 1000);
  else if (cmd == "dance") {  // small dance routine
    OttoBot.moonwalker(1, 800, 20, 1);
    OttoBot.swing(1, 800, 20);
    OttoBot.jitter(1, 600, 20);
    OttoBot.sing(S_superHappy);
  }
  else if (cmd == "sing")     OttoBot.sing(S_cuddly);
  else if (cmd == "happy") {  OttoBot.sing(S_happy);  OttoBot.updown(1, 800, 20); }
  else if (cmd == "sad")   {  OttoBot.sing(S_sad);    OttoBot.swing(1, 1200, 10); }
  else if (cmd == "sleep") {  OttoBot.sing(S_sleeping); OttoBot.home(); }
}

void randomPet(){
  // simple random idle behavior
  int r = random(4);
  if (r==0) OttoBot.sing(S_cuddly);
  else if (r==1) OttoBot.swing(1, 1000, 15);
  else if (r==2) OttoBot.jitter(1, 800, 20);
  else OttoBot.updown(1, 1000, 15);
}

void setup(){
  BT.begin(9600);
  OttoBot.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  OttoBot.home();
  OttoBot.sing(S_connection);
  randomSeed(analogRead(0));
  lastCmd = millis();
}

void loop(){
  static String input = "";

  while (BT.available()){
    char c = BT.read();
    if (c=='\r' || c=='\n'){
      if (input.length()>0){
        doCommand(input);
        input = "";
        lastCmd = millis();
      }
    } else {
      input += c;
    }
  }

  // Idle pet mode
  if (millis() - lastCmd > idleTimeout){
    randomPet();
    lastCmd = millis();
  }
}
    
