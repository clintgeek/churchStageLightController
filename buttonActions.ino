void leftButton() {
  debugPrinter("Pressed Left", 1);
  delay(keyHandlerCheckDelay);
  decrementMode();
}

void downButton() {
  debugPrinter("Pressed Down", 1);
  delay(keyHandlerCheckDelay);
}

void upButton() {
  debugPrinter("Pressed Up", 1);
  delay(keyHandlerCheckDelay);
}

void rightButton() {
  debugPrinter("Pressed Right", 1);
  delay(keyHandlerCheckDelay);
  incrementMode();
}

void selectButton() {
  debugPrinter("Pressed Select", 1);
  delay(keyHandlerCheckDelay);
}

void decrementMode() {
  int newMode;

  if (mode == 1 || mode == 0) {
    newMode = numberOfModes;
  } else {
    newMode = mode - 1;
  }

  setMode(newMode);
}

void incrementMode() {
  int newMode;

  if (mode == numberOfModes) {
    newMode = 1;
  } else {
    newMode = mode + 1;
  }

  setMode(newMode);
}
