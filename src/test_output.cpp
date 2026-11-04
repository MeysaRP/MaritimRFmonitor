#include <iostream>
#include "output.h"

using namespace std;

const string RESET  = "\033[0m";
const string GREEN  = "\033[32m";
const string RED    = "\033[31m";
const string YELLOW = "\033[33m";
const string CYAN   = "\033[36m";
const string BOLD   = "\033[1m";

void garis() {
    cout << CYAN
         << "+----------------------------------------------+\n"
         << RESET;
}

int main() {
    cout << CYAN << BOLD;
    garis();
    cout << "          MARITIME RF MONITOR\n";
    cout << "             STATUS OUTPUT\n";
    garis();
    cout << RESET;

    cout << "\n" << GREEN << BOLD
         << "[01] NORMAL\n"
         << RESET;
    cout << "     " << pesanStatus(NORMAL) << "\n";

    cout << "\n" << RED << BOLD
         << "[02] CONSTANT JAMMING\n"
         << RESET;
    cout << "     " << pesanStatus(CONSTANT_JAMMING) << "\n";

    cout << "\n" << YELLOW << BOLD
         << "[03] PERIODIC JAMMING\n"
         << RESET;
    cout << "     " << pesanStatus(PERIODIC_JAMMING) << "\n";

    cout << "\n" << CYAN << BOLD
         << "[04] UNKNOWN STATUS\n"
         << RESET;
    cout << "     " << pesanStatus(STATUS_TIDAK_DIKENAL) << "\n";

    cout << "\n";
    garis();
    cout << GREEN << BOLD
         << "          OUTPUT TEST SELESAI\n"
         << RESET;
    garis();

    return 0;
}