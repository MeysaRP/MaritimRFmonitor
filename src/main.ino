#include "input.h"
#include "output.h"
#include "led.h"

const unsigned long BAUD_RATE = 115200;
const unsigned long BATAS_WAKTU_SINYAL = 5000;

unsigned long waktuTerakhirDiterima = 0;

bool sinyalPernahDiterima = false;
bool sedangMenungguSinyal = true;

StatusJamming statusSaatIni = STATUS_TIDAK_DIKENAL;

void tampilkanStatus(StatusJamming status) {
  Serial.println(pesanStatus(status));

  StatusLED led = indikatorLED(static_cast<int>(status));

  Serial.print("LED Hijau: ");
  Serial.println(led.hijau ? "ON" : "OFF");

  Serial.print("LED Merah: ");
  Serial.println(led.merah ? "ON" : "OFF");

  Serial.print("LED Kuning/Oranye: ");
  Serial.println(led.kuning ? "ON" : "OFF");
}

void setup() {
  Serial.begin(BAUD_RATE);

  Serial.println("=== MaritimRFmonitor ===");
  Serial.println("Menunggu data klasifikasi...");
  Serial.println("Kirim: Normal, Constant Jamming, atau Periodic Jamming");
  Serial.println("Status: Menunggu Sinyal...");
}

void loop() {
  String dataMasuk = bacaStatus();

  if (dataMasuk != "") {
    waktuTerakhirDiterima = millis();
    sinyalPernahDiterima = true;
    sedangMenungguSinyal = false;

    if (dataMasuk == "Normal") {
      statusSaatIni = NORMAL;
    }
    else if (dataMasuk == "Constant Jamming") {
      statusSaatIni = CONSTANT_JAMMING;
    }
    else if (dataMasuk == "Periodic Jamming") {
      statusSaatIni = PERIODIC_JAMMING;
    }
    else {
      statusSaatIni = STATUS_TIDAK_DIKENAL;
    }

    tampilkanStatus(statusSaatIni);
  }

  bool waktuHabis =
      sinyalPernahDiterima &&
      millis() - waktuTerakhirDiterima >= BATAS_WAKTU_SINYAL;

  if (!sinyalPernahDiterima || waktuHabis) {
    if (!sedangMenungguSinyal) {
      Serial.println("Menunggu Sinyal...");
      Serial.println("Semua indikator LED: OFF");

      sedangMenungguSinyal = true;
      statusSaatIni = STATUS_TIDAK_DIKENAL;
    }
  }
}
