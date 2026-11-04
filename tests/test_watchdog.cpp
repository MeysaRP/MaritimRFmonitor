#include <iostream>
#include <cassert>

using namespace std;

const unsigned long BATAS_WAKTU_SINYAL = 5000;

const string RESET  = "\033[0m";
const string GREEN  = "\033[32m";
const string RED    = "\033[31m";
const string YELLOW = "\033[33m";
const string CYAN   = "\033[36m";
const string BOLD   = "\033[1m";
const string GRAY   = "\033[90m";

bool sinyalPernahDiterima = false;
bool sedangMenungguSinyal = true;
unsigned long waktuTerakhirDiterima = 0;

void garis() {
    cout << CYAN
         << "+--------------------------------------------------+\n"
         << RESET;
}

void tampilkanHasil(const string& pesan) {
    cout << "  " << GREEN << "[PASS] " << RESET
         << pesan << "\n";
}

void terimaSinyal(unsigned long waktu) {
    waktuTerakhirDiterima = waktu;
    sinyalPernahDiterima = true;
    sedangMenungguSinyal = false;
}

void periksaWatchdog(unsigned long waktuSekarang) {
    bool waktuHabis =
        sinyalPernahDiterima &&
        waktuSekarang - waktuTerakhirDiterima >= BATAS_WAKTU_SINYAL;

    if (!sinyalPernahDiterima || waktuHabis) {
        sedangMenungguSinyal = true;
    }
}

int main() {
    cout << CYAN << BOLD;
    garis();
    cout << "          MARITIME RF MONITOR\n";
    cout << "             WATCHDOG TEST\n";
    garis();
    cout << RESET;

    cout << "\n" << YELLOW << BOLD
         << "  [TEST 01] KONDISI AWAL\n" << RESET;
    periksaWatchdog(0);
    assert(sedangMenungguSinyal);
    tampilkanHasil("Program menunggu sinyal");

    cout << "\n" << CYAN << BOLD
         << "  [TEST 02] PENERIMAAN SINYAL\n" << RESET;
    terimaSinyal(1000);
    assert(!sedangMenungguSinyal);
    tampilkanHasil("Sinyal berhasil diterima");

    cout << "\n" << CYAN << BOLD
         << "  [TEST 03] PEMERIKSAAN TIMEOUT\n" << RESET;
    periksaWatchdog(5999);
    assert(!sedangMenungguSinyal);
    tampilkanHasil("Status aktif sebelum 5 detik");

    cout << "\n" << RED << BOLD
         << "  [TEST 04] WATCHDOG AKTIF\n" << RESET;
    periksaWatchdog(6000);
    assert(sedangMenungguSinyal);
    tampilkanHasil("Watchdog aktif setelah 5 detik");

    cout << "\n";
    garis();
    cout << GREEN << BOLD
         << "       SEMUA PENGUJIAN BERHASIL!\n"
         << RESET;
    garis();

    return 0;
}