#ifndef LED_H
#define LED_H

struct StatusLED {
    bool hijau;
    bool merah;
    bool kuning;
};

StatusLED indikatorLED(int status);

#endif