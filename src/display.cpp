#include "display.h"

void mulaiDisplay() {
    // Inisialisasi OLED akan ditambahkan setelah model layar diketahui.
}

void tampilkanPesan(const char* baris1, const char* baris2) {
    // Fungsi tampilan OLED akan diimplementasikan setelah pustaka ditentukan.
    Serial.println(baris1);

    if (baris2[0] != '\0') {
        Serial.println(baris2);
    }
}

void tampilkanStatusOLED(const char* pesan) {
    tampilkanPesan(pesan);
}

void tampilkanMenungguSinyal() {
    tampilkanPesan("Menunggu Sinyal...");
}