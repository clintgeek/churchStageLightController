#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
long currentMillis;
long lastKeyHandlerCheck;
long keyHandlerCheckDelay = 250;
const bool debug = true;
int mode;
int numberOfModes = 3;
String modes[3] = {"Base Color", "Party Lights", "BreatheBaseColor"};

void setup() {
  if (debug) {
    Serial.begin(115200);
  }
  lcd.begin(16, 2);
  debugPrinter("Arduino Booting...", 1);
  welcomeMessage();
  screenPrinter("Please Choose", "A Light Mode");
  debugPrinter("Arduino Ready!", 1);
}

void loop() {
  currentMillis = millis();
  modeManager(mode);
  if(int key = keyHandler()) { actionButtonDispatcher(key); }
}

int keyHandler() {
  bool shouldCheck = ((currentMillis - lastKeyHandlerCheck) > keyHandlerCheckDelay);
  int keyInput = analogRead(0);
  int keyOutput;

  if (shouldCheck && keyInput < 675) {
    debugPrinter("keyInput: ", keyInput, 0);

    if (keyInput < 50) { keyOutput = 4; }
    else if (keyInput < 180) { keyOutput = 3; }
    else if (keyInput < 336) { keyOutput = 2; }
    else if (keyInput < 528) { keyOutput = 1; }
    else { keyOutput = 5; }

    debugPrinter("keyOutput: ", keyOutput, 1);
    lastKeyHandlerCheck = currentMillis;
    return keyOutput;
  } else {
    return false;
  }
}

void actionButtonDispatcher(int key) {

  switch(key) {
    case 1:
      leftButton();
      break;
    case 2:
      downButton();
      break;
    case 3:
      upButton();
      break;
    case 4:
      rightButton();
      break;
    case 5:
      selectButton();
      break;
  }
}
