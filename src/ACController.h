#ifndef _ACCCONTROLLER_H_
#define _ACCCONTROLLER_H_

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <IRsend.h>
#include <ArduinoJson.h>

#include "WebServer.h"
#include "IRRemote.h"
#include "PowerMeter.h"

#define HTTP_PORT 80

#define IR_REMOTE_PIN D2
#define POWER_METER_PIN A0

#define MAX_IR_COMMAND_LENGTH 300
#define JSON_BUFFER_SIZE JSON_ARRAY_SIZE(MAX_IR_COMMAND_LENGTH) + JSON_OBJECT_SIZE(2) + 1400

#define POWER_METER_SAMPLING_INTERVAL 1000
#define POWER_METER_SAMPLE_COUNT 60
#define POWER_METER_R1 4260  //422.6 kiloohm
#define POWER_METER_R2 996   //99.6 kiloohm

#endif
