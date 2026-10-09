#ifndef OUTPUT_H
#define OUTPUT_H

enum StatusJamming {
    NORMAL,
    CONSTANT_JAMMING,
    PERIODIC_JAMMING,
    STATUS_TIDAK_DIKENAL
};

const char* pesanStatus(StatusJamming status);

#endif