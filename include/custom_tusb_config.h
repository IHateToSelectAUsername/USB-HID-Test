#ifndef _CUSTOM_TUSB_CONFIG_H_
#define _CUSTOM_TUSB_CONFIG_H_

// Allgemeine USB-Einstellungen
#define CFG_TUSB_MCU             OPT_MCU_RP2040
#define CFG_TUSB_RHPORT0_MODE    (OPT_MODE_DEVICE | OPT_MODE_FULL_SPEED)
#define CFG_TUSB_OS              OPT_OS_PICO

// Debugging aktivieren
#ifndef CFG_TUSB_DEBUG
#define CFG_TUSB_DEBUG           3  // Debug-Level: Fehler, Warnungen und Informationen
#endif

// Aktivierte Klassen
#define CFG_TUD_CDC              1  // USB CDC (Serial)
#define CFG_TUD_HID              1  // HID (z. B. Tastatur)
#define CFG_TUD_MSC              0  // Mass Storage deaktiviert
#define CFG_TUD_MIDI             0  // MIDI deaktiviert
#define CFG_TUD_VENDOR           0  // Vendor-spezifisch deaktiviert
#define CFG_TUD_VIDEO            0  // Video deaktiviert

// HID-spezifische Einstellungen
#define CFG_TUD_HID_EP_BUFSIZE   64

// CDC FIFO Buffergröße
#define CFG_TUD_CDC_RX_BUFSIZE   256
#define CFG_TUD_CDC_TX_BUFSIZE   256

#endif
