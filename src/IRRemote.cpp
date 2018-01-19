#include "ACController.h"

IRRemote::IRRemote(uint16_t irSendPin) {
    _irSend = new IRsend(irSendPin);
}

void IRRemote::begin() {
    _irSend->begin();
}

void IRRemote::loop() {
    // Dummy method for consistencey between 'modules'.
}

void IRRemote::send(uint16_t* rawData, uint16_t rawDataSize, uint16_t frequency) {
    _irSend->sendRaw(rawData, rawDataSize, frequency);
}

IRRemote irRemote = IRRemote(IR_REMOTE_PIN);
