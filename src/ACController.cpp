#include "ACController.h"


IRsend irsend(D2);


void setup(void)
{ 
    irsend.begin();

    Serial.begin(9600);

    // Connect to WiFi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // while wifi not connected yet, print '.'
    // then after it connected, get out of the loop
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    //print a new line, then print WiFi connected and the IP address
    Serial.print("\nWiFi connected, ip address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
}
