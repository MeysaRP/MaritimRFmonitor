#include "led.h"

StatusLED indikatorLED(int status) {
    switch (status) {
        case 0: // Normal
            return {true, false, false};

        case 1: // Constant Jamming
            return {false, true, false};

        case 2: // Periodic Jamming
            return {false, false, true};

        default:
            return {false, false, false};
    }
}