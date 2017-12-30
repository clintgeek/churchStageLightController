#include <LiquidCrystal.h>
// Configure RGB Control Pins
#define REDLED 11
#define GREENLED 10
#define BLUELED 9
#define LCDLED 3

// Configure LCD Pins
// if using Uno, define LCD[x] as x, on nano choose non-PWM pins where possible.
#define LCD4 4
#define LCD5 5
#define LCD6 6
#define LCD7 7
#define LCD8 8
#define LCD9 12
#define LCDBUTTON A0
LiquidCrystal lcd(LCD8, LCD9, LCD4, LCD5, LCD6, LCD7);

// List and count of modes for menu system
const int numberOfModes = 6; // excluding "OFF"
const String modes[] = {"OFF", "Solid Color", "Party Lights", "Breathe", "RGB Breathe", "Rainbow Swirl", "Fire"};

// Global Variables
int mode;
int adjustMode;
int potentialMode;
unsigned long currentMillis;
int breatheSpeed = 30;
int solidColor[3] = {0, 0, 255};
unsigned long potentialModeStart;
const unsigned long potentialModeTimeout = 10000; // defines how long mode choice menu shows
unsigned long lastKeyHandlerCheck;
const unsigned long keyHandlerCheckDelay = 250; // debounce for mechanical keys
unsigned long backlightStart;
const unsigned long backlightTimeout = 30000; // backlight dims after
unsigned long adjustModeStart;
const unsigned long adjustModeTimeout = 15000;

// Debug Mode
const bool debug = true; // setting to false will disable serial output

void setup() {
  if (debug) {
    Serial.begin(115200);
  }
  lcd.begin(16, 2);
  debugPrinter("Arduino Booting...", 1);
  digitalWrite(REDLED, LOW);
  pinMode(REDLED, OUTPUT);
  digitalWrite(GREENLED, LOW);
  pinMode(GREENLED, OUTPUT);
  digitalWrite(BLUELED, LOW);
  pinMode(BLUELED, OUTPUT);
  digitalWrite(LCDLED, LOW);
  pinMode(LCDLED, OUTPUT);
  analogWrite(LCDLED, 255);
  welcomeMessage();
  displayMode();
  debugPrinter("Arduino Ready!", 1);
}

void loop() {
  currentMillis = millis();
  timeOutWatcher();
  if(int key = keyHandler()) { actionButtonDispatcher(key); }
}

void timeOutWatcher() {
  adjustModeClear();
  potentialModeClear();
  backlightDimmer();
}