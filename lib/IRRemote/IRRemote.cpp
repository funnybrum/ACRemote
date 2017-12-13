#include "IRRemote.h"
#include "IRCommands.cpp"

IRRemote::IRRemote(uint16_t irSendPin) {
    _irSendPin = irSendPin;
}

void IRRemote::begin() {
    _irSend = new IRsend(_irSendPin);
    _irSend->begin();
}

void IRRemote::send(IRCommand* command) {
    _irSend->sendRaw(command->rawData, command->rawDataSize, command->frequency);
}
