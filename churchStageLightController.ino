#include <LiquidCrystal.h>

// Configure RGB Control Pins
#define redLED 9;
#define greenLED 10;
#define blueLED 11;

// Configure LCD Pins
// if using Uno, define LCD[x] as x, on nano choose non-PWM pins where possible.
#define LCD4 4
#define LCD5 13
#define LCD6 2
#define LCD7 7
#define LCD8 8
#define LCD9 12
#define LCDBUTTON A0
LiquidCrystal lcd(LCD8, LCD9, LCD4, LCD5, LCD6, LCD7);

// List and count of modes for menu system
const int numberOfModes = 3; // excluding "OFF"
const String modes[] = {"OFF", "Base Color", "Party Lights", "BreatheBaseColor"};

// Global Variables
int mode;
int potentialMode;
unsigned long currentMillis;
unsigned long potentialModeStart;
const unsigned long potentialModeTimeout = 10000; // defines how long mode choice menu shows
unsigned long lastKeyHandlerCheck;
const unsigned long keyHandlerCheckDelay = 500; // debounce for mechanical keys

// Debug Mode
const bool debug = true; // setting to false will disable serial output

void setup() {
  if (debug) {
    Serial.begin(115200);
  }
  lcd.begin(16, 2);
  debugPrinter("Arduino Booting...", 1);
  welcomeMessage();
  digitalWrite(redLED, LOW);
  pinMode(redLED, OUTPUT);
  digitalWrite(greenLED, LOW);
  pinMode(greenLED, OUTPUT);
  digitalWrite(blueLED, LOW);
  pinMode(blueLED, OUTPUT);
  displayMode();
  debugPrinter("Arduino Ready!", 1);
}

void loop() {
  currentMillis = millis();
  potentialModeClear();
  modeManager(mode);
  if(int key = keyHandler()) { actionButtonDispatcher(key); }
}

int keyHandler() {
  bool shouldCheck = ((currentMillis - lastKeyHandlerCheck) > keyHandlerCheckDelay);
  int keyInput = analogRead(LCDBUTTON);
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
