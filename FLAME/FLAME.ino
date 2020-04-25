int led = 13;    // menggunakan led sebagai indikator 
int sensorApi = 2;   // input sensor deteksi api
int api = HIGH;   // kondisi status api 

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensorApi, INPUT); 
  Serial.begin(9600);
  
}

void loop() {
  api = digitalRead(sensorApi);
  if (api== HIGH)
  { Serial.println("terdeteksi ada api");
    digitalWrite(led, HIGH);
  }
  else
  { Serial.println("tidak terdeteksi api");
    digitalWrite(led, LOW);
  }
}
