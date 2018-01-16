#include "ACController.h"
#include "Secrets.h"

void setup()
{ 
    Serial.begin(115200);

    // Connect to WiFi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.print("\nWiFi connected, ip address: ");
    Serial.println(WiFi.localIP());

    webServer.begin();
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
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
