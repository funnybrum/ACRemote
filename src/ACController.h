#ifndef _ACCCONTROLLER_H_
#define _ACCCONTROLLER_H_

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <IRsend.h>
#include <ArduinoJson.h>

#include "WebServer.h"
#include "IRRemote.h"

#define HTTP_PORT 80

#define IR_REMOTE_PIN D2
#define POWER_METER_PIN A0

#define MAX_IR_COMMAND_LENGTH 300
#define JSON_BUFFER_SIZE JSON_ARRAY_SIZE(MAX_IR_COMMAND_LENGTH) + JSON_OBJECT_SIZE(2) + 1400

#endif
