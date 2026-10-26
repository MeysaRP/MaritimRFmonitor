#include "input.h"
#include "output.h"
#include "led.h"

const unsigned long BAUD_RATE = 115200;

void tampilkanStatus(StatusJamming status) {
  // Tampilkan pesan status
  Serial.println(pesanStatus(status));

  // Ambil hasil pemetaan indikator LED
  StatusLED led = indikatorLED(static_cast<int>(status));

  // Tampilkan kondisi LED secara logika di Serial Monitor
  Serial.print("LED Hijau: ");
  Serial.println(led.hijau ? "ON" : "OFF");

  Serial.print("LED Merah: ");
  Serial.println(led.merah ? "ON" : "OFF");

  Serial.print("LED Kuning: ");
  Serial.println(led.kuning ? "ON" : "OFF");
}

void setup() {
  Serial.begin(BAUD_RATE);

  Serial.println("=== MaritimRFmonitor ===");
  Serial.println("Menunggu data klasifikasi...");
  Serial.println("Kirim: Normal, Constant Jamming, atau Periodic Jamming");
}

void loop() {
  String status = bacaStatus();

  if (status == "Normal") {
    tampilkanStatus(NORMAL);
  }
  else if (status == "Constant Jamming") {
    tampilkanStatus(CONSTANT_JAMMING);
  }
  else if (status == "Periodic Jamming") {
    tampilkanStatus(PERIODIC_JAMMING);
  }
  else if (status != "") {
    Serial.println("Status tidak dikenali: " + status);
  }
}
