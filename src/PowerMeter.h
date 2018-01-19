#ifndef _POWERMETER_H_
#define _POWERMETER_H_

#include "ACController.h"

class PowerMeter {
    public:
        PowerMeter(uint16_t pmPin, unsigned long sampleInterval, int sampleCount, int r1, int r2);
        void begin();
        void loop();
        void getData(int* buffer, int samples);
    private:
      uint16_t _pmPin;
      unsigned long _sampleInterval;
      unsigned int _sampleCount;
      int* _data;
      int _r1;
      int _r2;
};

extern PowerMeter powerMeter;

#endif
