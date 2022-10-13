#include "HX711.h"

const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
double deformacija;
float naprezanje;
int modul_elasticnosti = 210000; //MPa

HX711 tenzometar;

void setup() {
  Serial.begin(9600);
  tenzometar.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  if (tenzometar.is_ready()) {
    double ocitanje = tenzometar.read();

    deformacija = 3 * pow(10,-10) * ocitanje + 0,0005;
    naprezanje = deformacija * modul_elasticnosti;
    
    Serial.print("Deformacija: ");
    Serial.print(deformacija, 6);
    Serial.print(" Naprezanje: ");
    Serial.print(naprezanje, 2);
    Serial.println(" MPa");
  } else {
    Serial.println("HX711 nije pronađen.");
  }
  delay(500);
}
