#include "IRRemote.h"
#include "IRCommands.h"

IRRemote::IRRemote(uint16_t irSendPin) {
    _irSendPin = irSendPin;
}

void IRRemote::begin() {
    _irSend = new IRsend(_irSendPin);
    _irSend->begin();
}
