/*
 * Serena Ramley, UBC Engineering
 * 
 * Pin Connections:
 * GPIO4 is Pulse Input PIN (PCNT_INPUT_SIG_IO in my-pcnt.h)
 * This code assumes and external pulse generator is connected to GPIO4 (also connect GND of ESP32 to GND of pulse generator)
 * Alternatively, ESP32 GPIO18 could be configured to 1 kHz pulse (refer to ESP32 documentation)
 * Connect GPIO5 to 3.3 V
 */

#include "my-pcnt.h"

#define WAIT_MS  2000 // Time to wait (in ms) before reporting pulse count reading


void setup() {
  /* CONFIG: Printing to Console */
  Serial.begin(115200);                     // Set Baud to 115200
}

void loop() {
  int16_t count = 0;                        // 16-bit count register
  pcnt_init_and_start();                    // Start counting pulses
  Serial.printf("\nCounter started\n");
  delay(WAIT_MS);                              
  pcnt_get(&count);
  Serial.printf("\nCurrent counter value :%d\n", count);
  pcnt_clear();
  pcnt_get(&count);
  Serial.printf("\nCurrent counter value :%d\n", count);
}
