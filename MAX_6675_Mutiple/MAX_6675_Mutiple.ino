#define CLK 52
#define DBIT1 48 // so
#define DBIT2 46
#define CS 50

#include <SoftwareSerial.h>

int a= 0;
int i=0,j=0;
int v[2]={0,0};
float Ctemp[2]={0,0};

void setup()  
{
  Serial.begin(9600);
  pinMode(CLK, OUTPUT);
  pinMode(DBIT1, INPUT);
  pinMode(DBIT1, INPUT);
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
  digitalWrite(CLK, LOW);

}

void loop()
{
  int value[2]={0,0};
  digitalWrite(CS,LOW);
  delay(2);
  digitalWrite(CS,HIGH);
  delay(220);

  digitalWrite(CS,LOW);
  digitalWrite(CLK,HIGH);
  delay(1);
  digitalWrite(CLK,LOW);
 
  for(i=14;i>=0;i--)
  {
    digitalWrite(CLK,HIGH);
    value[0] += digitalRead(DBIT1) << i;
    value[1] += digitalRead(DBIT2) << i;
    digitalWrite(CLK,LOW); 
  }

  for(j=0;j<=1;j++)
  {

    if ((value[j] & 0x04) == 0x04)
    {
        a=-1;
    }
    else
    {
       a=value[j]>>3;
    } 

   v[j]=a;
   if(v[j]==-1)
   {
    Serial.println("No sensor");
   }
   
   else if(v[j]!=-1)
   {
      Ctemp[j]=v[j]*0.25;
      Serial.print("Temperature in C for ");
      Serial.print(j);
      Serial.print(" Sensor is : ");
      Serial.println(Ctemp[j]);
      delay(1000);
   }
   a=0;
  }
}
