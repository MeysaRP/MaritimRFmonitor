#include <Arduino.h>
#include "input.h"
#include "output.h"
#include "led.h"

// Pin GPIO ESP32 — sesuaikan dengan wiring saat perangkat tersedia.
const int LED_HIJAU = 25;
const int LED_MERAH = 26;
const int LED_KUNING = 27;

const unsigned long BAUD_RATE = 115200;

void aturLED(StatusJamming status) {
    StatusLED led = indikatorLED(static_cast<int>(status));

    digitalWrite(LED_HIJAU, led.hijau ? HIGH : LOW);
    digitalWrite(LED_MERAH, led.merah ? HIGH : LOW);
    digitalWrite(LED_KUNING, led.kuning ? HIGH : LOW);
}

void tampilkanStatus(StatusJamming status) {
    Serial.println(pesanStatus(status));
    aturLED(status);

    StatusLED led = indikatorLED(static_cast<int>(status));

    Serial.print("LED Hijau: ");
    Serial.println(led.hijau ? "ON" : "OFF");

    Serial.print("LED Merah: ");
    Serial.println(led.merah ? "ON" : "OFF");

    Serial.print("LED Kuning: ");
    Serial.println(led.kuning ? "ON" : "OFF");

    Serial.println("------------------------");
}

void matikanSemuaLED() {
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(LED_MERAH, LOW);
    digitalWrite(LED_KUNING, LOW);
}

void setup() {
    Serial.begin(BAUD_RATE);

    pinMode(LED_HIJAU, OUTPUT);
    pinMode(LED_MERAH, OUTPUT);
    pinMode(LED_KUNING, OUTPUT);

    matikanSemuaLED();

    Serial.println("=== MaritimRFmonitor ===");
    Serial.println("Visualisasi Status Jamming");
    Serial.println("Menunggu data klasifikasi...");
    Serial.println("Kirim salah satu status berikut:");
    Serial.println("Normal");
    Serial.println("Constant Jamming");
    Serial.println("Periodic Jamming");
    Serial.println("------------------------");
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
        Serial.print("Status tidak dikenali: ");
        Serial.println(status);
        matikanSemuaLED();
    }
}