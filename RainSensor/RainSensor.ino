//Deklarasi pin sensor hujan
int pinSensor = A0;
int ledHijau = 6;
int ledMerah = 7;

// batas kalibrasi sensor bisa diubah disesuaikan kondisi
int thresholdValue = 500;

void setup(){
//pengaturan pin input/output
pinMode(pinSensor, INPUT);
pinMode(ledHijau, OUTPUT);
pinMode(ledMerah, OUTPUT);

//
digitalWrite(ledHijau, LOW);  // led hijau mati
digitalWrite(ledMerah, LOW);  // led merah mati
Serial.begin(9600);
}

void loop() {
// baca input pada pin analog 0:
int sensorValue = analogRead(pinSensor);

Serial.print(sensorValue);

if(sensorValue < thresholdValue){
  Serial.println("Hujan");
  digitalWrite(ledHijau, LOW);   //led hijau mati
  digitalWrite(ledMerah, HIGH);  //led merah nyala
}
  else {
    Serial.println("Kering");
    digitalWrite(ledHijau, HIGH);  //led hijau nyala
    digitalWrite(ledMerah, LOW);   //led merah mati
  }
  delay(500);
}
