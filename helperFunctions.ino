void welcomeMessage() {
  screenPrinter("First Methodist", "Mansfield");
  powerOnSelfTest();
}

String findModeName(int mode) {
  return String(modes[mode]);
}

String dispalyRgbVals() {
  return dispalyRgbVals(solidColor);
}

String dispalyRgbVals(int rgbVals[3]) {
  return "r:" + String(rgbVals[0]) + " g:" + String(rgbVals[1]) + " b:" + String(rgbVals[2]);
}

void displayMode() {
  if (mode < 1) {
    screenPrinter("LEFT or RIGHT", "to select mode");
  } else if (mode == 1 || mode == 4) {
    screenPrinter(findModeName(mode), dispalyRgbVals());
  } else {
    screenPrinter("Current Mode:", findModeName(mode));
  }
}

void displayPotentialMode() {
  potentialModeStart = currentMillis;
  screenPrinter("Press SELECT for:", findModeName(potentialMode));
}

void screenPrinter(String line1, String line2) {
  debugPrinter("LCD Updated", 1);
  lcd.clear();
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

bool continueMode (int checkMode) {
  if (checkMode == mode && potentialMode == 255) { 
    return true;
  } else {
    return false;
  }
}
