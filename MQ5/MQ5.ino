float pinSensor=A0;
float nilaiSensor;
void setup()
{ 
  pinMode(pinSensor,INPUT);
  Serial.begin(9600);
}
void loop()
{
  nilaiSensor=analogRead(pinSensor);
  Serial.println(nilaiSensor);
}
