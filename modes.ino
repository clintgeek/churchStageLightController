void modeManager(int mode) {
  switch(mode) {
    case 0:
      modeOff();
      break;
    case 1:
      modeSolidColor();
      break;
    case 2:
      modePartyLights();
      break;
    case 3:
      modeBreathe();
      break;
    case 4:
      modeRgbBreathe();
      break;
    case 5:
      modeRainbowSwirl();
      break;
    case 6:
      modeFire();
      break;
  }
}

void modeOff() {
  rgb(0, 0, 0);
}

void modeSolidColor() {
  rgb(solidColor[0], solidColor[1], solidColor[2]);
  displayMode();
}

void modePartyLights() {
  int checkMode = mode;
  while (continueMode(checkMode)) {
    int rgbValue[3] = { 0, 0, 0 };
    int primaryColor = random(0, 3);
    rgbValue[primaryColor] = 255;

    for (int i = 0; i < 3; i++) {
      if (i != primaryColor) {
        rgbValue[i] = random(0, 85);
      }
    }

    rgb(rgbValue[0], rgbValue[1], rgbValue[2]);
    displayMode(rgbValue);
    threadSafeDelay(100, 500);
  }
}

void modeBreathe() {
  int checkMode = mode;
  while(continueMode(checkMode)) {
    breatheIn(primaryColor(), checkMode);
    breatheOut(primaryColor(), checkMode);
  }
}

void modeRgbBreathe() {
  int checkMode = mode;
  while(continueMode(checkMode)) {
    breatheIn(0, checkMode);
    breatheOut(0, checkMode);
    breatheIn(1, checkMode);
    breatheOut(1, checkMode);
    breatheIn(2, checkMode);
    breatheOut(2, checkMode);
  }
}

void modeRainbowSwirl() {
  int checkMode = mode;
  int rgbColor[3];

  // Start off with red.
  rgbColor[0] = 255;
  rgbColor[1] = 0;
  rgbColor[2] = 0;

  while (continueMode(checkMode)) {
    // Choose the colors to increment and decrement.
    for (int decColor = 0; (decColor < 3) && continueMode(checkMode); decColor += 1) {
      int incColor = decColor == 2 ? 0 : decColor + 1;

      // cross-fade the two colors.
      for (int i = 0; (i < 255) && continueMode(checkMode); i += 1) {

        rgbColor[decColor] -= 1;
        rgbColor[incColor] += 1;

        rgb(rgbColor[0], rgbColor[1], rgbColor[2]);
        displayMode(rgbColor);
        threadSafeDelay(breatheSpeed);
      }
    }
  }
}

void modeFire() {
  int checkMode = mode;
  while (continueMode(checkMode)) {
    int greenValue = random(25, 75);
    int redValue = random(225, 245);
    rgb(redValue, greenValue, 0);
    int rgbColor[3] = {redValue, greenValue, 0};
    displayMode(rgbColor);
    threadSafeDelay(63, 125);
  }
}

void powerOnSelfTest() {
  rgb(100, 0, 0);
  delay(750);

  rgb(0, 100, 0);
  delay(750);

  rgb(0, 0, 100);
  delay(750);

  rgb(0, 0, 0);
}

void rgb(int r, int g, int b) {
  writeSingleColor(0, r);
  writeSingleColor(1, g);
  writeSingleColor(2, b);
}

void breatheIn(int color, int checkMode) {
  int rgbColor[3];
  rgbColor[0] = 0;
  rgbColor[1] = 0;
  rgbColor[2] = 0;

  for (int brightness = 0; (brightness <= 255) && (continueMode(checkMode)); brightness++) {
    rgbColor[color] = brightness;
    rgb(rgbColor[0], rgbColor[1], rgbColor[2]);
    displayMode(rgbColor);
    threadSafeDelay(breatheSpeed);
  }
}

void breatheOut(int color, int checkMode) {
  int rgbColor[3];
  rgbColor[0] = 0;
  rgbColor[1] = 0;
  rgbColor[2] = 0;
  rgbColor[color] = 255;

  for (int brightness = 255; (brightness >= 1) && (continueMode(checkMode)); brightness--) {
    rgbColor[color] = brightness;
    rgb(rgbColor[0], rgbColor[1], rgbColor[2]);
    displayMode(rgbColor);
    threadSafeDelay(breatheSpeed);
  }
}

int primaryColor() {
  int primaryColor;
  if (solidColor[0] > solidColor[1] && solidColor[0] > solidColor[2]) {
    primaryColor = 0;
  }
  else if (solidColor[1] > solidColor[0] && solidColor[1] > solidColor[2]) {
    primaryColor = 1;
  }
  else primaryColor = 2;

  return primaryColor;
}

void writeSingleColor(int colorIndex, int brightness) {
  int outPin;

  switch (colorIndex) {
    case 0:
      outPin = REDLED;
      break;
    case 1:
      outPin = GREENLED;
      break;
    case 2:
      outPin = BLUELED;
      break;
  }

  analogWrite(outPin, brightness);
}

