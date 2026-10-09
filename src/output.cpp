#include "output.h"

const char* pesanStatus(StatusJamming status) {
    switch (status) {
        case NORMAL:
            return "Status: Aman";

        case CONSTANT_JAMMING:
            return "PERINGATAN: Constant Jamming";

        case PERIODIC_JAMMING:
            return "PERINGATAN: Periodic Jamming";

        default:
            return "Status tidak dikenal";
    }
}