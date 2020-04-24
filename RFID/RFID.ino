#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup()
{
Serial.begin(9600); // Memulai komunikasi serial
SPI.begin(); // Memulai bus SPI
mfrc522.PCD_Init(); // Mulai MFRC522
Serial.println("Perkirakan kartu Anda ke pembaca ...");
Serial.println();
}
void loop()
{

// Cari kartu baru
if ( ! mfrc522.PICC_IsNewCardPresent())
{
return;
}

// Pilih salah satu kartu
if ( ! mfrc522.PICC_ReadCardSerial())
{
  return;
}

// Tampilkan UID pada monitor serial
Serial.print("UID tag :");
String content= "";
byte letter;
for (byte i = 0; i < mfrc522.uid.size; i++)
{
Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
Serial.print(mfrc522.uid.uidByte[i], HEX);
content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
Serial.println();
Serial.print("Pesan : ");
content.toUpperCase();
if (content.substring(1) == "AA 45 78 9D") 
{
  Serial.println("Boleh mengakses");
  Serial.println();
  delay(3000);
}
  else {
  Serial.println("Tidak diperbolehkan mengakses");
  delay(3000);
  }
}
