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

void allOff() {
  rgb(0, 0, 0);
}