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
      modeRainbowSwirl();
      break;
  }
}

void modeOff() {
  rgb(0, 0, 0);
}

void modeSolidColor() {
  rgb(solidColor[0], solidColor[1], solidColor[2]);
}

void modePartyLights() {
}

void modeBreathe() {
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
        screenPrinter(findModeName(mode), dispalyRgbVals(rgbColor));
        // delay(breatheSpeed);
        threadSafeDelay(breatheSpeed);
      }
    }
  }
}

void rgb(int r, int g, int b) {
  writeSingleColor(0, r);
  writeSingleColor(1, g);
  writeSingleColor(2, b);
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



void writeSingleColor(int colorIndex, int brightness) {
  int outPin;

  switch (colorIndex) {
    case 0:
      outPin = redLED;
      break;
    case 1:
      outPin = greenLED;
      break;
    case 2:
      outPin = blueLED;
      break;
  }

  analogWrite(outPin, brightness);
}

