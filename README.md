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
