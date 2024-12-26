#include <Arduino.h>
#include <Adafruit_TinyUSB.h>

// HID-Report-Descriptor für eine Tastatur
const uint8_t HID_KEYBOARD_REPORT_DESC[] = {
    TUD_HID_REPORT_DESC_KEYBOARD()
};

// HID-Instanz
Adafruit_USBD_HID usb_hid;

uint8_t keycode[6] = {0};  // Tastencode-Array

void setup() {
    // USB-Serielle Schnittstelle initialisieren
    Serial.begin(115200);
    while (!Serial) {
        delay(10);  // Warten, bis die serielle Schnittstelle bereit ist
    }
    Serial.println("USB CDC (Serial) gestartet!");

    // HID initialisieren
    Serial.println("Initialisiere HID...");
    usb_hid.setPollInterval(10);  // Setze Polling-Intervall auf 10ms
    usb_hid.setReportDescriptor(HID_KEYBOARD_REPORT_DESC, sizeof(HID_KEYBOARD_REPORT_DESC));

    // Überprüfen, ob HID erfolgreich gestartet wird
    if (usb_hid.begin()) {
        Serial.println("HID gestartet! Endpunkt erfolgreich registriert.");
    } else {
        Serial.println("Fehler beim Starten von HID! Endpunkt konnte nicht registriert werden.");
    }

    // Debugging: Größe des HID-Report-Descriptors
    Serial.print("HID-Report-Descriptor-Größe: ");
    Serial.println(sizeof(HID_KEYBOARD_REPORT_DESC));
}

void loop() {
    // Debugging: Serielle Ausgabe zur Überprüfung des Gerätestatus
    Serial.println("Hello from RP2040!");

    // HID: Buchstabe 'A' senden
    Serial.println("Sende HID-Daten (Buchstabe 'A')...");
    keycode[0] = HID_KEY_A;

    // HID-Bericht senden und Ergebnis überprüfen
    if (usb_hid.keyboardReport(0, 0, keycode)) {
        Serial.println("HID-Bericht erfolgreich gesendet.");
    } else {
        Serial.println("Fehler beim Senden des HID-Berichts.");
    }
    delay(100);

    // Taste loslassen
    Serial.println("Sende HID-Daten (Taste loslassen)...");
    keycode[0] = 0;
    if (usb_hid.keyboardReport(0, 0, keycode)) {
        Serial.println("HID-Bericht (Taste loslassen) erfolgreich gesendet.");
    } else {
        Serial.println("Fehler beim Senden des HID-Berichts (Taste loslassen).");
    }
    delay(2000);
}
