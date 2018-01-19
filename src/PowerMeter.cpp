#include "ACController.h"

PowerMeter::PowerMeter(uint16_t pmPin, unsigned long sampleInterval, int sampleCount) {
    _pmPin = pmPin;
    _sampleInterval = sampleInterval;
    _sampleCount = sampleCount;
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
    POWER_METER_SAMPLE_COUNT
);
