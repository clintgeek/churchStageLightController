void leftButton() {
  debugPrinter("Pressed Left", 1);
  screenPrinter("You Pressed:", "LEFT");
  delay(keyHandlerCheckDelay);
  decrementMode();
}

void downButton() {
  debugPrinter("Pressed Down", 1);
  screenPrinter("You Pressed:", "DOWN");
  delay(keyHandlerCheckDelay);
  downButton();
}

void upButton() {
  debugPrinter("Pressed Up", 1);
  screenPrinter("You Pressed:", "UP");
  delay(keyHandlerCheckDelay);
  upButton();
}

void rightButton() {
  debugPrinter("Pressed Right", 1);
  screenPrinter("You Pressed:", "RIGHT");
  delay(keyHandlerCheckDelay);
  incrementMode();
}

void selectButton() {
  debugPrinter("Pressed Select", 1);
  screenPrinter("You Pressed:", "SELECT");
  delay(keyHandlerCheckDelay);
  selectButton();
}

void decrementMode() {
  int newMode;

  if (mode == 1) {
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
