#include "ACController.h"

PowerMeter::PowerMeter(uint16_t pmPin, unsigned long sampleInterval, int sampleCount, int r1, int r2) {
    _pmPin = pmPin;
    _sampleInterval = sampleInterval;
    _sampleCount = sampleCount;
    _r1 = r1;
    _r2 = r2;
    _data = new int[_sampleCount];
    memset(_data, 0, _sampleCount);
}

void PowerMeter::begin() {
    // Dummy method for consistencey between 'modules'.
}

void PowerMeter::loop() {
}

void PowerMeter::getData(int* buffer, int samples) {
}

PowerMeter powerMeter = PowerMeter(
    POWER_METER_PIN,
    POWER_METER_SAMPLING_INTERVAL,
    POWER_METER_SAMPLE_COUNT,
    POWER_METER_R1,
    POWER_METER_R2
);
