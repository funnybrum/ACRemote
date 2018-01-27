# ACRemote

*Work in progress!. Expected to be finished in February 2018.*

Software for module providing REST interface to any air conditioner.

## Summary

This is implemented in quite generic approach. The HTTP server exposes an endpoint. The endpoint accept POST requests with JSON body. The JSON body provides the full IR command to be executed. This means that the same hardware device will be able to control different air conditioners.

The client for this in my case will be a Raspberry Pi with that will have a list of all required commands and will do some automation - set the temp to 16 degree when there is nobody at home, put it to 21 when family members are getting back from work.

For getting the IR commands you'll need [IRrecvDumpV2.ino](https://github.com/markszabo/IRremoteESP8266/blob/master/examples/IRrecvDumpV2/IRrecvDumpV2.ino). The sketch contain link to example hardware.

## Hardware details
Required components:
* NodeMCU module (ESP8266)
* IR LED
* NPN transistor (i.e. BC550) and a few resistors

The hardware is pretty simple. ESP8266 with IR LED, transistor and few resistors to controll the LED.

There is also OTA support. The module is designed to be put inside the air conditiner near the IR receiver. Both ACs that I have are having 5V line to that module and sufficient space around it, so this would be pretty straight forward.

Pictures and schematics will be added as last part of the project. This is quite simple, so I suppose the lack of the schematics will not block anyone.

## Update log

### 25 January 2018

### 25 January 2018

Scrapped the power metering part. This was designed to be used with ACS712. But most AC doesn't have power factor of 1, so ACS712 just by itself is insufficient to calculate the power. Removing the power meter will also allow this to be integrated inside the AC body near the IR receiver panel. There are 5V on both of my ACs going to that board that will do pretty good job for powering up the ESP8266.

Decided to add OTA update support. Since this is going to be integrated inside the AC the regular approach for update with cable becomes quite unacceptable.

Added support for multiple WiFi networks. In my case I have two with different names. The software will scan for all available networks, filter out the one that passwords are provided for and choose the one with the strongest signal.

### 27 January 2018
The unit is finally assembled in a ready to use version and is mounted in a Panasonic KIT-NE-9MKE Nordic unit. There was plenty of space behind the IR receiver board. Two wires were soldered to the IR receiver board for providing DC5V to the ESP8266. The Panasonic commands seems to be a bit bigger than expected and the command buffer size was increased to 450 (so good to have the OTA update support). Tested with a few command send with curl and everything works fine. Below are examples:

1. Execute a command (not sure if it was powering off or setting the AC to 26C):
> curl http://192.168.0.44/exec -d '{"command": [3494, 1656,  474, 404,  474, 1246,  468, 418,  446, 420,  448, 424,  448, 426,  444, 434,  448, 408,  444, 416,  448, 404,  474, 398,  448, 412,  474, 398,  474, 1260,  472, 434,  448, 404,  448, 408,  470, 390,  448, 412,  474, 400,  448, 420,  474, 1290,  444, 1288,  474, 1258,  474, 404,  474, 390,  474, 1252,  472, 416,  442, 426,  448, 434,  444, 424,  474, 390,  444, 408,  448, 416,  444, 416,  448, 424,  444, 424,  448, 424,  442, 434,  448, 408,  444, 408,  474, 386,  472, 398,  448, 416,  444, 424,  448, 434,  444, 424,  474, 390,  444, 408,  448, 416,  444, 416,  448, 420,  448, 424,  448, 424,  444, 434,  446, 408,  444, 416,  444, 1276,  442, 1294,  474, 416,  470, 398,  474, 408,  444, 438,  442, 390,  444, 10198,  3494, 1646,  474, 416, 444, 1272,  470, 416,  448, 416,  470, 400,  474, 406,  444, 436,  444, 408,  444, 408,  474, 390,  444, 416,  472, 400,  442, 426,  474, 1290,  442, 424,  474, 390,  444, 408,  448, 416,  444, 416,  422, 450,  444, 424,  448, 1282,  494, 1290,  470, 1246,  468, 408,  448, 416,  470, 1246,  470, 424,  448, 424,  444, 430,  442, 434,  422, 434,  444, 416,  442, 408,  472, 400,  442, 416,  474, 400,  448, 434,  444, 424,  474, 390,  444, 1264,  496, 390,  444, 420,  468, 1256,  468, 426,  448, 434,  444, 1282,  498, 390,  442, 408,  444, 416,  474, 1268,  474, 398,  474, 1276,  474, 1258,  474, 426,  474, 390,  444, 406,  444, 416,  448, 416,  442, 426,  448, 424,  444, 428,  444, 432,  474, 1238,  498, 1238,  502, 1242,  500, 1242,  498, 1252,  500, 1250,  504, 1242,  490, 404,  474, 378,  474, 408,  468, 1246,  500, 1250,  474, 386,  500, 400,  474, 408,  442, 426,  474, 390,  444, 408,  448, 416,  444, 416,  442, 430,  444, 424,  448, 424,  444, 434,  448, 408,  444, 416,  446, 1270,  476, 1268,  498, 1252,  474, 394,  474, 424,444, 438,  444, 408,  442, 416,  448, 408,  468, 400,  448, 416,  470, 400,  472, 1260,  504, 1260,  500, 1234,  474, 386,  474, 408,  468, 400,  448, 416,  470, 400,  472, 408,  442, 426,  474, 390,  444, 408,  448, 418,  442, 416,  448, 424,  444, 424,  448, 426,  442, 438,  444, 408,  470, 1272,  442, 416,  448, 416,  444, 416,  474, 400,  448, 434,  442, 434,  444, 1268,  474, 372,  504, 360,  474, 426,  442, 416,  444, 430,  442, 434,  422, 452,  468, 390,  448, 406,  444, 416,  422, 442,  444, 426,  422, 450,  444, 424,  422, 460,  442, 412,  468, 1246,  474, 1268,  472, 1268,  474, 394,  478, 1276,  500, 1250,  504, 374,  504, 1216,  474], "frequency": 38}' -H "Content-Type: application/json" -v

2. OTA firmware upgrade:
> curl -F "image=@.pioenvs/d1_mini/firmware.bin" 192.168.0.44/update

Next step - put the same device in a Toshiba RAS-10SKVP2-E. And implement /sleep endpoint so the WiFi electromagnetic radiation can be reduced while the room is in use and the WiFi remote functionality is not needed.