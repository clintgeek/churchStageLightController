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

void potentialModeClear() {
  if (potentialMode != 255) {
    bool shouldClear = (currentMillis - potentialModeStart) > potentialModeTimeout;
    
    if (shouldClear) {
      potentialMode = 255;
      displayMode();
    }
  }
}

void modeOff() {

}

void modeBaseColor() {
}

void modePartyLights() {
}

void modeBaseColorBreathe() {
}