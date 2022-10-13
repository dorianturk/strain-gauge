#include "HX711.h"

const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 umjeravanje;

void setup() {
  Serial.begin(9600);
  umjeravanje.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  if (umjeravanje.is_ready()) {
    long ocitanje = umjeravanje.read();    
    Serial.println(ocitanje);
  } else {
    Serial.println("HX711 nije pronađen.");
  }
  delay(50);
}
