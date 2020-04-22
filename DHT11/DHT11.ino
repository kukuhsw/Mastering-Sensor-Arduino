#include "DHT.h"
#define DHTPIN 2        // deklarasi PIN DHT
#define DHTTYPE DHT11   // jenis sensor DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
dht.begin();
}

void loop() {

delay(2000);
// baca data suhu dan kelembaban
float h = dht.readHumidity();
float t = dht.readTemperature();
float f = dht.readTemperature(true);

if (isnan(h) || isnan(t) || isnan(f)) {
Serial.println("Gagal mendapat data sensor");
return;
}

float hif = dht.computeHeatIndex(f, h);
float hic = dht.computeHeatIndex(t, h, false);

Serial.print("Kelembaban: ");
Serial.print(h);
Serial.print(" %\t");

Serial.print("Suhu: ");
Serial.print(t);
Serial.print(" *C ");
Serial.print(f);
Serial.print(" *F\t");

Serial.print("Indek panas: ");
Serial.print(hic);
Serial.print(" *C ");
Serial.print(hif);
Serial.println(" *F");
}
