#include <iostream>
#include <cassert>

const unsigned long BATAS_WAKTU_SINYAL = 5000;

bool sinyalPernahDiterima = false;
bool sedangMenungguSinyal = true;
unsigned long waktuTerakhirDiterima = 0;

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
    // Uji 1: Saat mulai, perangkat menunggu sinyal.
    periksaWatchdog(0);
    assert(sedangMenungguSinyal);
    std::cout << "PASS: Awal program menunggu sinyal\n";

    // Uji 2: Sinyal diterima, status menunggu berakhir.
    terimaSinyal(1000);
    assert(!sedangMenungguSinyal);
    std::cout << "PASS: Sinyal diterima\n";

    // Uji 3: Belum melewati 5 detik, status tetap aktif.
    periksaWatchdog(5999);
    assert(!sedangMenungguSinyal);
    std::cout << "PASS: Sinyal belum timeout sebelum 5 detik\n";

    // Uji 4: Tepat 5 detik tanpa sinyal baru, watchdog aktif.
    periksaWatchdog(6000);
    assert(sedangMenungguSinyal);
    std::cout << "PASS: Watchdog aktif setelah 5 detik\n";

    std::cout << "Semua pengujian logika watchdog berhasil.\n";
    return 0;
}
