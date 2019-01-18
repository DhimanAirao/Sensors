float distance =0;
long Time;

#define Echopin 13
#define Triggerpin 12

void setup()
{
    Serial.begin(9600);
    pinMode(Echopin,INPUT);
    pinMode(Triggerpin,OUTPUT);
    digitalWrite(Echopin,LOW);
    digitalWrite(Triggerpin,LOW);

}

void loop()
{
      ultra_sonic();
}

void ultra_sonic()
{
    digitalWrite(Triggerpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(Triggerpin,LOW);

    Time=pulseIn(Echopin,HIGH);

    distance=(Time*0.0343)/2;

    Serial.print("DISTANCE :");
    Serial.print("\t");
    Serial.print(distance);
    Serial.print("\n");
}
