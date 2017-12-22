#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
long currentMillis;
long lastKeyHandlerCheck;
long keyHandlerCheckDelay = 250;
const debug = true;
int mode = 1;

void setup() {
  if (debug) {
    Serial.begin(115200);
  }
  lcd.begin(16, 2);
  debugPrinter("Arduino Booting...", 1);
  welcomeMessage();
  debugPrinter("Arduino Ready!", 1);
}

void loop() {
  currentMillis = millis();
  if(int key = keyHandler()) { actionButtonDispatcher(key); }
}

int keyHandler() {
  int keyInput = analogRead(0);
  int keyOutput;

  bool shouldCheck = ((currentMillis - lastKeyHandlerCheck) > keyHandlerCheckDelay);

  if (keyInput < 675 && shouldCheck) {
    debugPrinter("keyInput: ", keyInput, 0);

    if (keyInput < 50) { keyOutput = 4; }
    else if (keyInput >= 50 && keyInput < 180) { keyOutput = 3; }
    else if (keyInput >= 180 && keyInput < 336) { keyOutput = 2; }
    else if (keyInput >= 336 && keyInput < 528) { keyOutput = 1; }
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
      actionButtonLeft();
      break;
    case 2:
      actionButtonDown();
      break;
    case 3:
      actionButtonUp();
      break;
    case 4:
      actionButtonRight();
      break;
    case 5:
      actionButtonSelect();
      break;
  }
}

void actionButtonLeft() {
  debugPrinter("Pressed Left", 1);
  screenPrinter("You Pressed:", "LEFT");
  delay(keyHandlerCheckDelay);
  clearScreen();
}

void actionButtonDown() {
  debugPrinter("Pressed Down", 1);
  screenPrinter("You Pressed:", "DOWN");
  delay(keyHandlerCheckDelay);
  clearScreen();
}

void actionButtonUp() {
  debugPrinter("Pressed Up", 1);
  screenPrinter("You Pressed:", "UP");
  delay(keyHandlerCheckDelay);
  clearScreen();
}

void actionButtonRight() {
  debugPrinter("Pressed Right", 1);
  screenPrinter("You Pressed:", "RIGHT");
  delay(keyHandlerCheckDelay);
  clearScreen();
}

void actionButtonSelect() {
  debugPrinter("Pressed Select", 1);
  screenPrinter("You Pressed:", "SELECT");
  delay(keyHandlerCheckDelay);
  clearScreen();
}
