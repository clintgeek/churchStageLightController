void leftButton() {
  debugPrinter("Pressed Left", 1);
  delay(keyHandlerCheckDelay);
  decrementPotentialMode();
}

void downButton() {
  debugPrinter("Pressed Down", 1);
  delay(keyHandlerCheckDelay);
}

void upButton() {
  debugPrinter("Pressed Up", 1);
  potentialMode = 2;
  potentialModeStart = currentMillis;
  screenPrinter("Test", "Display");
  delay(keyHandlerCheckDelay);
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

void setPotentialMode() {
  mode = potentialMode;
  potentialMode = 255;
  displayMode();
}