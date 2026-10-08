#include "input.h"

String bacaStatus() {
  if (Serial.available() > 0) {
    String status = Serial.readStringUntil('\n');
    status.trim();

    return status;
  }

  return "";
}