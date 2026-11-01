#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

void mulaiDisplay();
void tampilkanPesan(const char* baris1, const char* baris2 = "");
void tampilkanStatusOLED(const char* pesan);
void tampilkanMenungguSinyal();

#endif