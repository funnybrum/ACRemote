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

void WebServer::handle_exec() {
    if (_server->hasArg("plain")== false) {
        //Check if there is a body.
        _server->send(400);
    	return;
    }

    String body = _server->arg("plain");
    DynamicJsonBuffer jsonBuffer(8192);
    JsonObject& root = jsonBuffer.parse(body);
    if (!root.success()) {
        _server->send(500);
    }

    JsonArray& command = root["command"];
    int rawDataSize = command.size();

    if (rawDataSize > MAX_IR_COMMAND_LENGTH) {
        _server->send(400, "Command length exceeded.");
    }

    int frequency = root["frequency"];
    uint16_t rawData[MAX_IR_COMMAND_LENGTH];
    command.copyTo(rawData);

    // irRemote.send(rawData, rawDataSize, frequency);

    _server->send(200);
}

WebServer webServer = WebServer();
