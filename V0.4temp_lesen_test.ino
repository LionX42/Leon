// V0.4   Ausgabe Temeratur mit LED flip flop
// V0.3   Ausgabe Temeratur, Erfolgreich!
// V0.2   Ermittlung Spannung Eingang Sensor
// V0.1   Temperaturausgabe

int temp = A0;
int sensorwert;
float spannung = 0;
float widerstand = 0;
int temperatur = 0;
int t = 500;
int z = 0;
int LED = LED_BUILTIN;
int flip = 0;

void setup() {
  // put your setup code here,  to run once:
Serial.begin(9600);// Komunikation mit serial monitor
}

void loop() {
  // put your main code here,  to run repeatedly:

sensorwert=analogRead(temp);// Auslesen Sensorwert

spannung = sensorwert * 0.0048828;
widerstand = (spannung*1000)/(5-spannung);

//Temperatur -55 / 0
if (widerstand < 807) {
  temperatur = map(widerstand, 485, 806, -55, -1);
  z=1;
}

//Temperatur 0 / 10
if (widerstand >= 807 && widerstand < 877) {
  temperatur = map(widerstand, 807, 876, 0, 10);
  z=2;
}

//Temperatur 10 / 20
if (widerstand >= 877 && widerstand < 951) {
  temperatur = map(widerstand, 877, 950, 10, 20);
  z=3;
}

//Temperatur 20 / 25
if (widerstand >= 951 && widerstand < 990) {
  temperatur = map(widerstand, 951, 989, 20, 25);
  z=4;
}

//Temperatur 25 / 30
if (widerstand >= 990 && widerstand < 1029) {
  temperatur = map(widerstand, 990, 1028, 25, 30);
  z=5;
}

//Temperatur 30 / 40
if (widerstand >= 1029 && widerstand < 1111) {
  temperatur = map(widerstand, 1029, 1110, 30, 40);
  z=6;
}

//Temperatur 40 / 50
if (widerstand >= 1111 && widerstand < 1196) {
  temperatur = map(widerstand, 1111, 1195, 40, 50);
  z=7;
}

//Temperatur 50 / 60
if (widerstand >= 1196 && widerstand < 1286) {
  temperatur = map(widerstand, 1196, 1285, 50, 60);
  z=8;
}

//Temperatur 60 / 70
if (widerstand >= 1286 && widerstand < 1378) {
  temperatur = map(widerstand, 1286, 1377, 60, 70);
  z=9;
}

//Temperatur 70 / 80
if (widerstand >= 1378 && widerstand < 1475) {
  temperatur = map(widerstand, 1378, 1474, 70, 80);
  z=10;
}

//Temperatur 80 / 150
if (widerstand >= 1475 && widerstand < 2189) {
  temperatur = map(widerstand, 1475, 2189, 80, 150);
  z=11;
}


Serial.print(sensorwert);
Serial.print("\t");
Serial.print(spannung, 3);//Ausgabe Spannung
Serial.print("V");
Serial.print("\t");
Serial.print(widerstand, 1);
Serial.print(" Ohm");
Serial.print("\t");
Serial.print(temperatur);
Serial.print("C");
Serial.print("\t");
Serial.print("Zeile:");
Serial.print(z);
Serial.println();


if(flip==0) (flip=1);
else if(flip==1) (flip=0);

if(flip==1)(digitalWrite(LED, HIGH));
if(flip==0)(digitalWrite(LED, LOW));

delay(t);

}
