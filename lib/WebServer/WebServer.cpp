#include "WebServer.h"
#include <IRCommands.cpp>

void WebServer::begin() {
    _server = new ESP8266WebServer(80);
    _server->on("/", std::bind(&WebServer::handle_root, this));
    _server->on("/commands", std::bind(&WebServer::handle_getCommands, this));
    _server->on("/exec", std::bind(&WebServer::handle_exec, this));
    _server->on("/power", std::bind(&WebServer::handle_getPower, this));
    _server->begin();
}

void WebServer::loop() {
    _server->handleClient();
}


void WebServer::handle_root() {
  _server->send(200,
                "text/plain",
                "AC remote.\nExposed methods are /commands and /exec?cmd=command_key and /power");
  delay(100);
}

void WebServer::handle_getPower() {

}

void WebServer::handle_getCommands() {

}

void WebServer::handle_exec() {
    
}