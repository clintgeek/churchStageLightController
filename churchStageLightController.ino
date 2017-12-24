#include <LiquidCrystal.h>
// Configure RGB Control Pins
#define redLED 9
#define greenLED 10
#define blueLED 11

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
const int numberOfModes = 4; // excluding "OFF"
const String modes[] = {"OFF", "Solid Color", "Party Lights", "Breathe", "Rainbow Swirl"};

// Global Variables
int mode;
int potentialMode;
unsigned long currentMillis;
int breatheSpeed = 30;
int solidColor[3] = {0, 0, 255};
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
  if(int key = keyHandler()) { actionButtonDispatcher(key); }
}
