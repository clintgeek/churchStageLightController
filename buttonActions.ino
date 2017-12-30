int keyHandler() {
  bool shouldCheck = ((currentMillis - lastKeyHandlerCheck) > keyHandlerCheckDelay);
  if (shouldCheck) {
    int keyInput = analogRead(LCDBUTTON);
    if (keyInput < 675) {
      int keyOutput;
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
  } else {
    return false;
  }
}

void actionButtonDispatcher(int key) {
  backlightOn();

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

void leftButton() {
  debugPrinter("Pressed Left", 1);
  decrementPotentialMode();
}

void downButton() {
  debugPrinter("Pressed Down", 1);
  debugPrinter("potentialMode: ", potentialMode, 0);
  debugPrinter("adjustMode: ", adjustMode, 0);

  if (potentialMode == 255 && adjustMode < 4) {
    adjustModeStart = currentMillis;
    int colorIndex;

    switch (adjustMode) {
      case 1:
        colorIndex = 0;
        break;
      case 2:
        colorIndex = 1;
        break;
      case 3:
        colorIndex = 2;
        break;
    }
    decrementSolidColor(colorIndex);
  }
}

void upButton() {
  debugPrinter("Pressed Up", 1);
  debugPrinter("potentialMode: ", potentialMode, 0);
  debugPrinter("adjustMode: ", adjustMode, 0);

  if (potentialMode == 255 && adjustMode < 4) {
    adjustModeStart = currentMillis;
    int colorIndex;

    switch (adjustMode) {
      case 1:
        colorIndex = 0;
        break;
      case 2:
        colorIndex = 1;
        break;
      case 3:
        colorIndex = 2;
        break;
    }
    incrementSolidColor(colorIndex);
  }
}

void rightButton() {
  debugPrinter("Pressed Right", 1);
  incrementPotentialMode();
}

void selectButton() {
  debugPrinter("Pressed Select", 1);
  if (potentialMode != 255) {
    setPotentialMode();
  } else if (mode == 1) {
    switch(adjustMode) {
      case 0:
        adjustSolidColorRed();
        break;
      case 1:
        adjustSolidColorGreen();
        break;
      case 2:
        adjustSolidColorBlue();
        break;
      case 3:
        adjustSolidColorDone();
        break;
    }
  }
}

void decrementPotentialMode() {
  if (potentialMode == 255) {
    if(mode == 0) {
      potentialMode = numberOfModes;
    } else {
      potentialMode = mode - 1;
    }
  } else if (potentialMode == 0) {
    potentialMode = numberOfModes;
  } else {
    potentialMode = potentialMode - 1;
  }
  debugPrinter("potentialMode: ", potentialMode, 1);
  displayPotentialMode();
}

void incrementPotentialMode() {
  if (potentialMode == 255) {
    if(mode == numberOfModes) {
      potentialMode = 0;
    } else {
      potentialMode = mode + 1;
    }
  } else if (potentialMode == numberOfModes) {
    potentialMode = 0;
  } else {
    potentialMode = potentialMode + 1;
  }
  debugPrinter("potentialMode: ", potentialMode, 1);
  displayPotentialMode();
}

void potentialModeClear() {
  if (potentialMode != 255) {
    bool shouldClear = (currentMillis - potentialModeStart) > potentialModeTimeout;

    if (shouldClear) {
      potentialMode = 255;
      modeManager(mode);
    }
  }
}

void setPotentialMode() {
  mode = potentialMode;
  potentialMode = 255;
  displayMode();
  modeManager(mode);
}

void adjustModeClear() {
  if (potentialMode != 0) {
    bool shouldClear = (currentMillis - adjustModeStart) > adjustModeTimeout;

    if (shouldClear) {
      adjustMode = 0;
    }
  }
}

void adjustSolidColorRed() {
  adjustMode = 1;
  adjustModeStart = currentMillis;
  blinkColorIndicator(0);
}

void adjustSolidColorGreen() {
  adjustMode = 2;
  adjustModeStart = currentMillis;
  blinkColorIndicator(1);
}

void adjustSolidColorBlue() {
  adjustMode = 3;
  adjustModeStart = currentMillis;
  blinkColorIndicator(2);
}

void adjustSolidColorDone() {
  adjustMode = 0;
}

void blinkColorIndicator(int colorIndex) {
  String indicatorR;
  String indicatorG;
  String indicatorB;

  if (colorIndex == 0) {
    indicatorR = " ";
    indicatorG = "G";
    indicatorB = "B";
  } else if (colorIndex == 1) {
    indicatorR = "R";
    indicatorG = " ";
    indicatorB = "B";
  } else {
    indicatorR = "R";
    indicatorG = "G";
    indicatorB = " ";
  }

  while (continueMode(1) && adjustMode > 0) {
    lcd.setCursor(0, 1);
    lcd.print(indicatorR);
    lcd.setCursor(1, 1);
    lcd.print(String(solidColor[0]));
    lcd.setCursor(6, 1);
    lcd.print(indicatorG);
    lcd.setCursor(7, 1);
    lcd.print(String(solidColor[1]));
    lcd.setCursor(12, 1);
    lcd.print(indicatorB);
    lcd.setCursor(13, 1);
    lcd.print(String(solidColor[2]));
    threadSafeDelay(250);
    lcd.setCursor(0, 1);
    lcd.print("R");
    lcd.setCursor(1, 1);
    lcd.print(String(solidColor[0]));
    lcd.setCursor(6, 1);
    lcd.print("G");
    lcd.setCursor(7, 1);
    lcd.print(String(solidColor[1]));
    lcd.setCursor(12, 1);
    lcd.print("B");
    lcd.setCursor(13, 1);
    lcd.print(String(solidColor[2]));
    threadSafeDelay(250);
  }
}

void incrementSolidColor(int colorIndex) {
  if(solidColor[colorIndex] < 255) {
    solidColor[colorIndex] = solidColor[colorIndex] + 5;
    modeManager(mode);
  }
}

void decrementSolidColor(int colorIndex) {
  if(solidColor[colorIndex] > 0) {
    solidColor[colorIndex] = solidColor[colorIndex] - 5;
    modeManager(mode);
  }
}
