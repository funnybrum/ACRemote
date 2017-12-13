#ifndef _IRREMOTE_H_
#define _IRREMOTE_H_

#include <stdint.h>
#include <IRsend.h>
#include "IRCommands.h"

class IRRemote {
    public:
        IRRemote(uint16_t irSendPin);
        void begin();
        void send(IRCommand* command);
    private:
        IRsend *_irSend;
        uint16_t _irSendPin;
};

#endif