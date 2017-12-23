void modeManager(int mode) {
  switch(mode) {
    case 0:
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

void setMode(int newMode) {
  mode = newMode;
  displayMode();
}

void modeBaseColor() {
}

void modePartyLights() {
}

void modeBaseColorBreathe() {
}