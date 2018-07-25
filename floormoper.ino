int directionR1=5;
int directionR2=4;
int directionL1=6;
int directionL2=7;
int tripin =2;
int echopin=3;
int rir=8;
int lir=10;
int LIR=12;
int RIR=13;
int state='A'; // Starts arrested

void setup()
{
  Serial.begin(9600);
  pinMode( directionR1,OUTPUT);
  pinMode( directionR2,OUTPUT);
  pinMode( directionL1,OUTPUT);
  pinMode( directionL2,OUTPUT);
  pinMode(tripin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(rir,INPUT);
  pinMode(lir,INPUT);  
pinMode(RIR,INPUT);
  pinMode(LIR,INPUT);
}

void turnclock()
{
  delay(250);
  analogWrite(9,252);
   digitalWrite( directionR1,LOW);
   digitalWrite( directionR2,HIGH);
   analogWrite(11,244);
   digitalWrite( directionL1,HIGH);
   digitalWrite( directionL2,LOW);
   }
void turnanticlock()
{
  delay(250);
  analogWrite(9,255);
   digitalWrite( directionR1,HIGH);
   digitalWrite( directionR2,LOW);
   analogWrite(11,255);
   digitalWrite( directionL1,LOW);
   digitalWrite( directionL2,HIGH);
   }   
void stopmove()
{
  delay(100);
  digitalWrite( directionR1,0);
  digitalWrite( directionR2,0);
   digitalWrite( directionL1,0);
   digitalWrite( directionL2,0);
    delay(200);
}

void stopmove1()
{
  delay(100);
  digitalWrite( directionR1,0);
  digitalWrite( directionR2,0);
   digitalWrite( directionL1,0);
   digitalWrite( directionL2,0);
    delay(1000);
}
void backmove()
{
  digitalWrite( directionR1,LOW);
   digitalWrite( directionR2,HIGH);
   digitalWrite( directionL1,LOW);
   digitalWrite( directionL2,HIGH);
   delay(200);
}
void frontgo()
{
  delay(100);
    analogWrite(9,255);
   digitalWrite( directionR1,HIGH);
   digitalWrite( directionR2,LOW);
   analogWrite(11,244);
   digitalWrite( directionL1,HIGH);
   digitalWrite( directionL2,LOW);
} 
void turnleft()
{
   analogWrite(9,241);
   digitalWrite( directionR1,HIGH);
   digitalWrite( directionR2,LOW);
   analogWrite(11,235);
   digitalWrite( directionL1,LOW);
   digitalWrite( directionL2,HIGH);
}
void turnright()
{
  analogWrite(9,241);
   digitalWrite( directionR1,LOW);
   digitalWrite( directionR2,HIGH);
   analogWrite(11,250);
   digitalWrite( directionL1,HIGH);
   digitalWrite( directionL2,LOW);
}
void loop() 
{
  long duration,distance;
  int drir=digitalRead(rir);
  int dlir=digitalRead(lir);
  int dRIR=digitalRead(RIR);
  int dLIR=digitalRead(LIR);
  digitalWrite(tripin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(tripin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance = (duration/2)/29.1;
  Serial.println(distance);
  Serial.println("CM");
  delay(100);
 
 if(dLIR==HIGH&&dRIR==HIGH)
 {
  if(distance>35)
  {
  if(dlir==HIGH&&drir==LOW)
  {
    stopmove();
    backmove();
   turnright();
  if (Serial.available ()> 0) 
     remloop();
  }
  if(dlir==LOW&&drir==HIGH)
  {
    stopmove();
    backmove();
    turnleft();
     if (Serial.available ()> 0) 
     remloop();
  }
  if(dlir==LOW&&drir==LOW)
  {
  frontgo();
   if (Serial.available ()> 0) 
     remloop();
  }
  }
  else if(distance<=35)
{
  delay(100);
  analogWrite(9,241);
  digitalWrite(directionR1,HIGH);
  digitalWrite(directionR2,LOW);
   analogWrite(11,235);
  digitalWrite(directionL1,LOW);
  digitalWrite(directionL2,HIGH);
   if (Serial.available ()> 0) 
     remloop();
  }
}

 if(dLIR==HIGH&&dRIR==LOW)
 {
 stopmove();
 delay(50);
 backmove();
 turnleft();
  if (Serial.available ()> 0) 
     remloop();
 }
 if(dLIR==LOW&&dRIR==HIGH)
 {
 stopmove();
 delay(50);
 backmove();
 turnright();
  if (Serial.available ()> 0) 
     remloop();
 }
  if(dLIR==LOW&&dRIR==LOW)
 {
 stopmove();
 delay(500);
 backmove();
  if (Serial.available ()> 0) 
     remloop();
 }
}
 void remloop()
{
state = Serial.read (); 
if (state == 'A') {// Forward 
Serial.println (state); 
frontgo();
} 

if (state == 'D')
{// right 
Serial.println (state); 
turnright();
delay(250);
frontgo();
} 

if (state == 'E') {// Stop 
Serial.println (state); 
stopmove1();
} 

if (state == 'C') 
{// left 
Serial.println (state); 
turnleft();
delay(250);
frontgo();
} 

if (state == 'B') 
{
Serial.println (state); //reverse
backmove();
}
if (state == 'F')
{Serial.println (state);
  turnclock();
} 
if (state == 'G') 
{
  Serial.println (state);
  turnanticlock();

}
 }




