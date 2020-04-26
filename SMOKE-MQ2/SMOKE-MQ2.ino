const int pinSensor= 7;
const int pinBuzzer= 11;
int parameter_gas;

void setup() {
Serial.begin(115200); 
pinMode(pinSensor, INPUT);
pinMode(pinBuzzer, OUTPUT);
}

void loop() {
parameter_gas= analogRead(pinSensor); 
Serial.println(parameter_gas);
if(parameter_gas > 500){ 
digitalWrite(pinBuzzer, HIGH);
}
else{
digitalWrite(pinBuzzer, LOW);
}
}
