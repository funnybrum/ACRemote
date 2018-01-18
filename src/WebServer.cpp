#include "ACController.h"

void WebServer::begin() {
    _server = new ESP8266WebServer(80);
    _server->on("/", std::bind(&WebServer::handle_root, this));
    _server->on("/exec", std::bind(&WebServer::handle_exec, this));
    _server->on("/power", std::bind(&WebServer::handle_getPower, this));

    _server->begin();
}

void WebServer::loop() {
    _server->handleClient();
}

void WebServer::handle_root() {
    _server->send(
        200,
        "text/plain",
        "AC remote.\nExposed endpoints are:\n */exec\n */power");
}

void WebServer::handle_getPower() {
    _server->send(
        501,
        "text/plain",
        "Not Implemented yet");
}

/**
 * Expect POST call with body like:
 * {
 *   "command": [10,100,10,......],
 *   "frequency": 38
 * }
 * The command and freqency parameters are as defined by the IRremoteESP8266 library. Both are
 * passed as arguments to the IRSend functionality. The content type should be 'application/json'
 */
void WebServer::handle_exec() {
    if (_server->hasArg("plain")== false) {
        //Check if there is a body.
        _server->send(400, "Body not received");
    	return;
    }

    DynamicJsonBuffer jsonBuffer(JSON_BUFFER_SIZE);

    JsonObject& root = jsonBuffer.parse(_server->arg("plain"));
    if (!root.success()) {
        _server->send(400, "Request body too big.");
    }

    JsonArray& command = root["command"];
    int rawDataSize = command.size();

    if (rawDataSize > MAX_IR_COMMAND_LENGTH) {
        _server->send(400, "Maximum command length exceeded.");
    }

    int frequency = root["frequency"];
    uint16_t rawData[MAX_IR_COMMAND_LENGTH];
    command.copyTo(rawData);

    jsonBuffer.clear();

    irRemote.send(rawData, rawDataSize, frequency);

    _server->send(200);
}

WebServer webServer = WebServer();
