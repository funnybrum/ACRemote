#include "ACController.h"
#include "Secrets.h"

void ScanAndConnect() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    int networks = WiFi.scanNetworks();

    Serial.printf("Found %d networks\n", networks);

    String strongestSSID = String("");
    int strongestSignalStrength = -1000;

    for (int i = 0; i < networks; i++) {
        int signalStrength = WiFi.RSSI(i);
        String ssid = WiFi.SSID(i);
        if (strongestSignalStrength < signalStrength) {
            for (int j = 0; j < sizeof(WIFI_SSIDs)/sizeof(WIFI_SSIDs[0]); j++) {
                if (ssid.equals(WIFI_SSIDs[j])) {
                    strongestSignalStrength = signalStrength;
                    strongestSSID = WiFi.SSID(i);
                }
            }
        }
    }

    if (strongestSSID.compareTo("") != 0) {
        Serial.printf("Connectiong to %s (%ddBm)\n", strongestSSID.c_str(), strongestSignalStrength);

        WiFi.hostname(HOSTNAME);
        WiFi.begin(strongestSSID.c_str(), WIFI_PASSWORD.c_str());

        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }

        Serial.print("\nConnected, ip address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("No known network found. Rebooting in 5 minutes...");
        delay(5 * 60 * 1000);
        ESP.reset();
    }

    WiFi.scanDelete();
}

void setup()
{ 
    Serial.begin(115200);

    ScanAndConnect();

    webServer.begin();
    irRemote.begin();
}

void loop() {
    webServer.loop();
    irRemote.loop();
    delay(100);
}
