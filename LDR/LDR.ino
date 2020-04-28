const int LDR = A0;       // LDR -> pin analog A0 arduino
const int LED = 9;       // LED -> pin digital 9 arduino

// Deklarasi variabel
int value;          // Nilai tersedia dari photoresistor (0-1023)

void setup(){
 pinMode(LED, OUTPUT);     // Jadikan LED pin 9 sebagai output
 pinMode(LDR, INPUT);      // Jadikan LDR - A0 pin sebagai an input 
}

void loop(){
  value = analogRead(LDR);
  if (value > 30){
    digitalWrite(LED, LOW);  // LED Mati
  }
  else{
    digitalWrite(LED, HIGH); // LED Nyala
  }
  delay(500); //jeda waktu
}
