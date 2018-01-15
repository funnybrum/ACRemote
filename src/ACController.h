#ifndef _ACCCONTROLLER_H_
#define _ACCCONTROLLER_H_

#include <ESP8266WiFi.h>
#include "WebServer.h"
#include "IRRemote.h"
#include "Secrets.h"

#define IR_REMOTE_PIN D2

WebServer webServer = WebServer();
IRRemote irRemote = IRRemote(IR_REMOTE_PIN);

#endif