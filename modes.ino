void modeManager(int mode) {
  switch(mode) {
    case 0:
      modeOff();
      break;
    case 1:
      modeBaseColor();
      break;
    case 2:
      modePartyLights();
      break;
    case 3:
      modeBaseColorBreathe();
      break;
  }
}

void modeOff() {
  rgb(0, 0, 0);
}

void modeBaseColor() {
  rgb(baseColor[0], baseColor[1], baseColor[2]);
}

void modePartyLights() {
}

void modeBaseColorBreathe() {
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

