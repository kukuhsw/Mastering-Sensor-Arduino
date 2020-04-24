int masukanAnalog = A1;
float vKeluar = 0.0;
float vMasuk = 0.0;
float R1 = 30000.0; //  resistor 1
float R2 = 7500.0; //   resistor 2
int value = 0;

void setup(){
   pinMode(masukanAnalog, INPUT);
   Serial.begin(9600);
   Serial.print("Pengukur Tegangan DC");
}
void loop(){
   // membaca nilai dari sensor analog
   value = analogRead(masukanAnalog);
   vKeluar = (value * 5.0) / 1024.0; // rumus hitung tegangan keluar
   vMasuk = vKeluar / (R2/(R1+R2)); // rumus hitung tegangan masuk
   
  Serial.print("ITegangan Masuk = ");
  Serial.println(vMasuk,2);
  delay(500);
}
