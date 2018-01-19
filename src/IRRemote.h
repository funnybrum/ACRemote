#ifndef _IRREMOTE_H_
#define _IRREMOTE_H_

#include "ACController.h"

class IRRemote {
    public:
        IRRemote(uint16_t irSendPin);
        void begin();
        void loop();
        void send(uint16_t* rawData, uint16_t rawDataSize, uint16_t frequency);
    private:
        IRsend *_irSend;
};

extern IRRemote irRemote;

#endif
