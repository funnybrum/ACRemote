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

    Serial.printf("Connectiong to %s (%ddBm)\n", strongestSSID.c_str(), strongestSignalStrength);

    WiFi.begin(strongestSSID.c_str(), WIFI_PASSWORD.c_str());

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.print("\nConnected, ip address: ");
    Serial.println(WiFi.localIP());

    WiFi.scanDelete();
}

void setup()
{ 
    Serial.begin(115200);

    ScanAndConnect();

    // Connect to WiFi
    // WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // while (WiFi.status() != WL_CONNECTED) {
    //     delay(500);
    //     Serial.print(".");
    // }

    webServer.begin();
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    return;
    // digitalWrite(D2, HIGH);
    // delay(100);
    // digitalWrite(D2, LOW);
    // delay(900);
    // unsigned long now = millis();
    // unsigned long count = 0;
    // unsigned long sum = 0;
    // while (millis() - now < 50) {
    //     sum += analogRead(A0);
    //     count += 1;
    // }

    // Serial.print("Count: ");
    // Serial.println(count);
    // Serial.print("Sum: ");
    // Serial.println(sum);
    // Serial.println(sum/count);

    webServer.loop();
    delay(100);
}
