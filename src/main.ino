#include "input.h"

const unsigned long BAUD_RATE = 115200;

void setup() {
  Serial.begin(BAUD_RATE);

  Serial.println("=== MaritimRFmonitor ===");
  Serial.println("Menunggu data klasifikasi...");
}

void loop() {
  String status = bacaStatus();

  if (status == "Normal") {
    Serial.println("Status diterima: Normal");
  }
  else if (status == "Constant Jamming") {
    Serial.println("Status diterima: Constant Jamming");
  }
  else if (status == "Periodic Jamming") {
    Serial.println("Status diterima: Periodic Jamming");
  }
  else if (status != "") {
    Serial.println("Status tidak dikenali: " + status);
  }
}
