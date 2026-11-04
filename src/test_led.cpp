#include <iostream>
#include "led.h"

using namespace std;

const string RESET  = "\033[0m";
const string GREEN  = "\033[32m";
const string RED    = "\033[31m";
const string YELLOW = "\033[33m";
const string CYAN   = "\033[36m";
const string BOLD   = "\033[1m";
const string GRAY   = "\033[90m";

void garis() {
    cout << CYAN
         << "+------------------------------------------+\n"
         << RESET;
}

void tampilkanStatus(const string& nama, StatusLED led) {
    cout << "\n" << BOLD << nama << RESET << "\n";

    cout << "  Green LED  : "
         << (led.hijau ? GREEN : GRAY)
         << (led.hijau ? "MENYALA" : "MATI")
         << RESET << "\n";

    cout << "  Red LED    : "
         << (led.merah ? RED : GRAY)
         << (led.merah ? "MENYALA" : "MATI")
         << RESET << "\n";

    cout << "  Yellow LED : "
         << (led.kuning ? YELLOW : GRAY)
         << (led.kuning ? "MENYALA" : "MATI")
         << RESET << "\n";
}

int main() {
    StatusLED normal = indikatorLED(0);
    StatusLED constant = indikatorLED(1);
    StatusLED periodic = indikatorLED(2);
    StatusLED unknown = indikatorLED(99);

    cout << CYAN << BOLD;
    garis();
    cout << "       MARITIME RF MONITOR\n";
    cout << "          LED STATUS TEST\n";
    garis();
    cout << RESET;

    tampilkanStatus("[01] NORMAL", normal);
    tampilkanStatus("[02] CONSTANT JAMMING", constant);
    tampilkanStatus("[03] PERIODIC JAMMING", periodic);
    tampilkanStatus("[04] UNKNOWN", unknown);

    cout << "\n";
    garis();
    cout << GREEN << BOLD
         << "       PENGUJIAN SELESAI\n"
         << RESET;
    garis();

    return 0;
}