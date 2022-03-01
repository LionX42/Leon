int temp = A0;
int sensorwert;
int temperatur = 0;
int t = 500;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);// Komunikation mit serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:

sensorwert=analogRead(temp);// Auslesen Sensorwert

temperatur = map(sensorwert,321,690,150,-50);
delay(t);

Serial.print(temperatur);
Serial.println("C");

}
