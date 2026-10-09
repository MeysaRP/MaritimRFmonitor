#include <iostream>
#include "led.h"

int main() {
    StatusLED normal = indikatorLED(0);
    StatusLED constant = indikatorLED(1);
    StatusLED periodic = indikatorLED(2);
    StatusLED unknown = indikatorLED(99);

    std::cout << "Normal: "
              << normal.hijau << " "
              << normal.merah << " "
              << normal.kuning << '\n';

    std::cout << "Constant: "
              << constant.hijau << " "
              << constant.merah << " "
              << constant.kuning << '\n';

    std::cout << "Periodic: "
              << periodic.hijau << " "
              << periodic.merah << " "
              << periodic.kuning << '\n';

    std::cout << "Unknown: "
              << unknown.hijau << " "
              << unknown.merah << " "
              << unknown.kuning << '\n';

    return 0;
}