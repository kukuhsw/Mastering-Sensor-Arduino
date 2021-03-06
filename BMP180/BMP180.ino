#include <BMP180.h>
#include <Wire.h>

BMP180 pressure;

#define KETINGGIAN 1655.0 // Deklarasi patokan rata-rata ketinggian air laut

void setup()
{
Serial.begin(9600);
Serial.println("booting");

if (pressure.begin())
Serial.println("Sukses mendapat data");
else
{
Serial.println("Gagal mendapat data");
while(1); // Berhenti
}
}

void loop()
{
char status;
double T,P,p0,a;
Serial.println();
Serial.print("Ketinggian dari permukaan air laut :");
Serial.print(KETINGGIAN,0);
Serial.print(" meter, ");
Serial.print(KETINGGIAN*3.28084,0);
Serial.println(" kaki");

status = pressure.startTemperature();
if (status != 0)
{

delay(status);

status = pressure.getTemperature(T);
if (status != 0)
{
  
// Cetak hasil perhitungan sensor
Serial.print("suhu: ");
Serial.print(T,2);
Serial.print(" C, ");
Serial.print((9.0/5.0)*T+32.0,2);
Serial.println(" F");

status = pressure.startPressure(3);
if (status != 0)
{
// Tunggu hasil pengukuran sensor
delay(status);

status = pressure.getPressure(P,T);
if (status != 0)
{
// Cetak hasil perhitungan sensor
Serial.print("absolute pressure: ");
Serial.print(P,2);
Serial.print(" mb, ");
Serial.print(P*0.0295333727,2);
Serial.println(" inHg");

Serial.print("relative (sea-level) pressure: ");

Serial.print(p0,2);
Serial.print(" mb, ");
Serial.print(p0*0.0295333727,2);
Serial.println(" inHg");

a = pressure.KETINGGIAN(P,p0);
Serial.print("KETINGGIAN: ");
Serial.print(a,0);
Serial.print(" meter, ");
Serial.print(a*3.28084,0);
Serial.println(" kaki");
}
else Serial.println("kesalahan mengambil pengukuran tekanan\n");
}
else Serial.println("kesalahan memulai pengukuran tekanan\n");
}
else Serial.println("kesalahan mengambil pengukuran suhu\n");
}
else Serial.println("kesalahan pengukuran suhu awal\n");
delay(6000); // jeda 6 detik
}
