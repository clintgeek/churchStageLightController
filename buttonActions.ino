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
  delay(keyHandlerCheckDelay);
  decrementPotentialMode();
}

void downButton() {
  debugPrinter("Pressed Down", 1);
  delay(keyHandlerCheckDelay);
  if (potentialMode == 255) {

  }
}

void upButton() {
  debugPrinter("Pressed Up", 1);
  delay(keyHandlerCheckDelay);
  if (potentialMode == 255) {

  }
}

void rightButton() {
  debugPrinter("Pressed Right", 1);
  delay(keyHandlerCheckDelay);
  incrementPotentialMode();
}

void selectButton() {
  debugPrinter("Pressed Select", 1);
  delay(keyHandlerCheckDelay);
  setPotentialMode();
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
