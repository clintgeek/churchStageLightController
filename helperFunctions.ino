void welcomeMessage() {
  screenPrinter("First Methodist", "Mansfield");
  powerOnSelfTest();
  clearScreen();
}

void clearScreen() {
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}

String findModeName(int mode) {
  return String(modes[mode]);
}

void displayMode() {
  clearScreen();
  if (mode > 0) {
    screenPrinter("Current Mode:", findModeName(mode));
  } else {
    screenPrinter("LEFT or RIGHT", "to select mode");
  }
}

void displayPotentialMode() {
  potentialModeStart = currentMillis;
  clearScreen();
  screenPrinter("Press SELECT for:", findModeName(potentialMode));
}

void screenPrinter(String line1, String line2) {
  debugPrinter("LCD Updated", 1);
  clearScreen();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
}

void threadSafeDelay(int min, int max) {
  int totalDelay = random(min, max);
  threadSafeDelay(totalDelay);
}

void threadSafeDelay(int duration) {
  for (int delayCounter = 0; delayCounter < duration; delayCounter++) {
    loop();
    delay(1);
  }
}

void debugPrinter(String title, int blankLines) {
  if (debug) {
    Serial.println(title);

    for (int i=0; i < blankLines; i++) {
      Serial.println();
    }
  }
}

void debugPrinter(String title, int value, int blankLines) {
  if (debug) {
    Serial.print(title);
    Serial.println(value);

    for (int i=0; i < blankLines; i++) {
      Serial.println();
    }
  }
}

void debugPrinter(String title, char* value, int blankLines) {
  if (debug) {
    Serial.print(title);

    int x = 0;
    while (true) {
      if (value[x] == '\n') {
        Serial.println();
        break;
      } else {
        Serial.print(value[x]);
        x++;
      }
    }

    for (int i=0; i < blankLines; i++) {
      Serial.println();
    }
  }
}
