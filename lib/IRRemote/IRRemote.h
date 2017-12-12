#ifndef _IRREMOTE_H_
#define _IRREMOTE_H_

#include <stdint.h>
#include <IRsend.h>

class IRRemote {
    public:
        void begin(uint16_t irSendPin);
    private:
        IRsend *_irSend;
};

#endif