#include "IRRemote.h"


void IRRemote::begin(uint16_t irSendPin) {
    _irSend = new IRsend(irSendPin);
    _irSend->begin();
}
