#include "ACController.h"

IRRemote::IRRemote(uint16_t irSendPin) {
    _irSendPin = irSendPin;
}

void IRRemote::begin() {
    _irSend = new IRsend(_irSendPin);
    _irSend->begin();
}

void IRRemote::send(uint16_t* rawData, uint16_t rawDataSize, uint16_t frequency) {
    _irSend->sendRaw(rawData, rawDataSize, frequency);
}

IRRemote irRemote = IRRemote(IR_REMOTE_PIN);
