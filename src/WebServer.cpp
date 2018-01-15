#include "WebServer.h"
#include "IRCommands.h"

#include <ArduinoJson.h>

uint16_t _off[295] = {4334, 4490,  580, 1622,  582, 1616,  580, 1618,  582, 1556,  582, 454,  582, 498,  582, 1552,  582, 472,  578, 468,  582, 464,  580, 460,  580, 506,  582, 1604,  586, 1552,  580, 498,  580, 1572,  582, 468,  582, 464,  556, 484,  580, 454,  582, 454,  576, 504,  580, 1598,  582, 1624,  580, 1620,  582, 1620,  580, 1612,  580, 1612,  580, 1604,  560, 1576,  582, 446,  580, 472,  576, 468,  582, 464,  580, 460,  580, 460,  578, 454,  556, 476,  576, 502,  576, 1574,  580, 520,  582, 1564,  580, 510,  582, 1560,  580, 454,  556, 472,  582, 450,  576, 472,  580, 468,  554, 490,  576, 464,  550, 484,  582, 502,  580, 1604,  580, 1604,  580, 1572,  582, 520,  576, 1568,  582, 510,  556, 1586,  552, 480,  580, 450,  554, 472,  580, 472,  576, 468,  580, 464,  580, 460,  582, 454,  582, 506,  576, 1604,  582, 1552,  582, 424,  576, 5418,  4334, 4490,  580, 1620,  560, 1642,  582, 1612,  580, 1560,  582, 454,  580, 498,  582, 1550,  582, 472,  576, 468,  580, 464,  580, 460,  580, 506,  580, 1608,  580, 1552,  582, 496,  582, 1574,  580, 468,  582, 464,  582, 458,  580, 454,  582, 454,576, 502,  580, 1600,  582, 1624,  582, 1620,  580, 1620,  582, 1612,  580, 1612,  582, 1602,  586, 1552,  580, 446,  580, 472,  576, 468,582, 464,  582, 458,  582, 454,  580, 456,  582, 446,  582, 498,  582, 1572,  580, 520,  580, 1564,  580, 510,  582, 1560,  580, 456,  576,450,  580, 450,  576, 472,  580, 468,  580, 464,  578, 462,  576, 460,  580, 502,  582, 1602,  582, 1600,  584, 1570,  586, 514,  580, 1566,  584, 512,  576, 1560,  580, 456,  580, 448,  580, 452,  580, 468,  582, 468,  580, 464,  582, 458,  582, 454,  582, 502,  582, 1604,  580, 1552,  582, 420,  580};
uint16_t _on[295] = {4358, 4460,  590, 1612,  590, 1612,  586, 1608,  586, 1556,  584, 450,  584, 498,  580, 1548,  586, 468,  586, 464,  582, 458,  586, 460,  580, 506,  582, 1602,  586, 1546,  586, 498,  582, 1568,  590, 464,  580, 460,  584, 460,  582, 454,  580, 450,  586, 498,  580, 1600,  586, 1620,  584, 1616,  584, 1612,  590, 1608,  584, 1604,  590, 1604,  586, 1548,  584, 446,  580, 468,  586, 464,  582, 464,  580, 458,  582, 454,  586, 446,  584, 446,  586, 494,  584, 1564,  590, 516,  580, 1564,  586, 506,  586, 1556,  586, 450,  580, 446,  586, 446,  582, 468,  580, 468,  582, 458,  584, 460,  580, 456,  582, 450,  584, 498,  582, 1598,  586, 1568,  586, 514,  582, 1566,  584, 506,  586, 1556,  586, 450,  582, 446,  586, 446,  580, 468,  582, 468,  580, 464,  582, 458,  582, 454,  580, 452,  582, 502,  580, 1548,  586, 420,  580, 5384,  4354, 4468,  580, 1620,  582, 1620,  580, 1612,  580, 1560,  580, 456,  576, 502,  582, 1552,  580, 468,  580, 468,  582, 464,  580, 460,  580, 508,  580, 1608,  580, 1552,  582, 498,  582, 1574,  580, 468,  582, 464,  580, 460,  580, 454,  582, 454,  576, 502,  582, 1598,  586, 1620,  580, 1622,  584, 1612,  586, 1612,  580, 1608,  588, 1600,  586, 1546,  586, 446,  580, 468,  580, 468,  580, 464,  582, 458,  582, 454,  582, 450,  586, 446,  580, 498,  582, 1572,  582, 520,  580, 1564,  582, 512,  580, 1556,  584, 450,  582, 450,  582, 446,  580, 468,  584, 464,  582, 462,  582, 458,  582, 454,  586, 450,  580, 498,  580, 1600,  586, 1572,  582, 514,  586, 1560,  586, 510,  582, 1556,  586, 450,  580, 450,  582, 446,  580, 468,  584, 464,  584, 458,  582, 460,  580, 454,  586, 450,  580, 498,  584, 1548,  586, 420,  580};

IRCommand commands[] = {
    IRCommand {
        .key = "on_22",
        .description = "Set temp to 22C",
        .rawData = _on,
        .rawDataSize = 295,
        .frequency = 38
    },
    IRCommand {
        .key = "off",
        .description = "Turn off the AC",
        .rawData = _off,
        .rawDataSize = 295,
        .frequency = 38
    }
};

uint16_t commandsCount = sizeof(commands)/sizeof(IRCommand);

void WebServer::begin() {
    _server = new ESP8266WebServer(80);
    _server->on("/", std::bind(&WebServer::handle_root, this));
    _server->on("/commands", std::bind(&WebServer::handle_getCommands, this));
    _server->on("/exec", std::bind(&WebServer::handle_exec, this));
    _server->on("/power", std::bind(&WebServer::handle_getPower, this));

    _server->on("/exec_ir", std::bind(&WebServer::handle_execIR, this));

    _server->begin();
}

void WebServer::loop() {
    _server->handleClient();
}

void WebServer::handle_root() {
    _server->send(
        200,
        "text/plain",
        "AC remote.\nExposed endpoints are:\n */commands\n */exec?cmd=command_key\n */power");
}

void WebServer::handle_getPower() {
    _server->send(
        501,
        "text/plain",
        "Not Implemented yet");
}

void WebServer::handle_getCommands() {
    String result = "{";
    for (int i = 0; i < commandsCount; i++) {
        result += "\"";
        result += commands[i].key;
        result += "\":\"";
        result += commands[i].description;
        result += "\"";
        if (commandsCount < i-1) {
            result += ", ";
        }
    }
    _server->send(
        200,
        "application/json",
        result
    );
}

void WebServer::handle_exec() {
    String *key = NULL;
    for (int i = 0; i < _server->args(); i++) {
        if (_server->argName(i) == "key") {
            String value = _server->arg(i);
            key = &value;
            break;
        }
    }

    if (key == NULL) {
        _server->send(
            400,
            "text/plain",
            "Missing query argument \"key\""
        );
        return;
    }

    IRCommand *command = NULL;
    for (int i = 0; i < commandsCount; i++) {
        if (*key == commands[i].key) {
            command = &commands[i];
            break;
        }
    }

    if (key == NULL) {
        _server->send(
            400,
            "text/plain",
            "Invalid command key specified."
        );
        return;
    }

    // irRemote.send(command);
}

void WebServer::handle_execIR() {
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
    int frequency = root["frequency"];

    Serial.print("Got ");
    Serial.print(command.size());
    Serial.println(" elements in the command array");
    Serial.print("Last element is ");
    Serial.println((unsigned int)command[command.size()-1]);

    Serial.print("Free heep: ");
    Serial.print(ESP.getFreeHeap());


    _server->send(200);
}