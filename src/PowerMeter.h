#ifndef _POWERMETER_H_
#define _POWERMETER_H_

#include "ACController.h"

class PowerMeter {
    public:
        PowerMeter(uint16_t pmPin, unsigned long sampleInterval, int sampleCount);
        void begin();
        void loop();
        void getData(int* buffer, int samples);
    private:
      uint16_t _pmPin;
      unsigned long _sampleInterval;
      unsigned int _sampleCount;
      int* _data;
};

extern PowerMeter powerMeter;

#endif
