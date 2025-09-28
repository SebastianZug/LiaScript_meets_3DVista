#include <PID_v1.h>
#define trigPin 12
#define echoPin 13

//Deklaration von Variablen und dem PID Regler
int Signalausgang =5;
int Schalter = 7;
int Lichtschrankeneingang =9;

double Dauer;
double Distanz;
double Output;

bool Schaltzustand;
bool Lichtschranke;

double Kp = 0.0;                //Hier sind die Reglerparameter einzustellen und zu variieren. Dezimaltrennzeichen ist ein Punkt.         
double Ki = 0.0;
double Kd = 0.0;

double Sollwert = 22.0;            //Hier kann der Sollwert, also die Ballhöhe eingestellt werden.
double Sollwert_unten =0.0;
double Sollwert_oben =50.0;

int y_min = 0;                  //Die ermittelten Systemgrenzen sind hier einzutragen. Die untere Grenze y_min
int y_max = 255;                //und die obere Grenze y_max.

PID myPID(&Distanz, &Output, &Sollwert,Kp,Ki,Kd , REVERSE);

void setup()
{
 Serial.begin(9600);               //Starten der seriellen Schnitstelle
 pinMode(Signalausgang,OUTPUT);    //Definitionen, was ist Eingang, was Ausgang
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(Schalter,INPUT);
 pinMode(Lichtschrankeneingang, INPUT);
 
 myPID.SetMode(AUTOMATIC);      //Einstellungen für den Regler
 myPID.SetOutputLimits(y_min,y_max);
}
void loop()
{
 //Ultraschall-Messung:
 //Durch Generieren eines "Stoßes" am Ausgang wird am Sender eine Schallwelle im Ultraschallbereich erzeugt.
 //Anschließend wird eine konstante Zeit abgewartet, bis am Empfänger die reflektierte Welle auftritt.
 //Aus der Lauftzeit des Schalls wird die Distanz berechnet. (Vgl. Gewitter-Sekunden-Zählen)
 digitalWrite(trigPin,LOW);      //Setze Augang ==0V
 delayMicroseconds(2);           //Warte 2mus
 digitalWrite(trigPin,HIGH);     //Setze Ausgang==5V
 delayMicroseconds(10);          //Warte 10mus
 digitalWrite(trigPin,LOW);      //Setze Augang ==0V
 Dauer=pulseIn(echoPin,HIGH);    //Erwarte Signal am Eingang
 Distanz=(Dauer/2)/29.1;         //Berechne Distanz
 
 Lichtschranke = digitalRead(Lichtschrankeneingang);        //Lesen von Eingängen
 Schaltzustand = digitalRead(Schalter);
 
 if (Schaltzustand == false)     //Das Einschalten des Lüfters durch den Schalter kann hiermit bewerkstelligt werden.
  {
    Sollwert = Sollwert_unten;
    myPID.Compute();              //PID-Regler regelt auf neuen Sollwert 
  }
 else{};

 if (Schaltzustand == true) //Regelwert berechnen
  {
    Sollwert = Sollwert_oben;
    myPID.Compute();
  }
 else{};
 
 analogWrite(5,Output);  //Schreibe Regelwert auf Ausgang
 
 Serial.print(millis());         //Ausgabe in die serielle Schnittstelle
 Serial.print("\t");             //Zeit
 Serial.print(Distanz);          //IST Wert
 Serial.print("\t");
 Serial.print(Sollwert);         //SOLL Wert  
 Serial.print("\t");
 Serial.print(Schaltzustand);    //Zustand am Schalter 
 Serial.print("\t");
 Serial.print(Output);           //Reglerausgang Wert
 Serial.print("\t");
 Serial.print(Lichtschranke);    //Zustand der Lichtschranke
 Serial.print("\n");
 
 delay(50);    //Warte Zeit 50ms
}
