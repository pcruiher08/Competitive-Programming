/*
  ILX751A
  29/04/2019
  Ver. 01
*/
const int pinLaser = 2; // for testing
int vout = 0; // sample this pin to get image data
int shsw = 5;  // sample hold. GND cuts on vdd2 cuts off
int clk = 11;   // clock timer pin. controls the timing.
int pin_shut = 3; 
int pin_rog = 2; // pulse rog low once to start sequence
int interruptPinCounter = 18;
int pulseCount = 0;

void setup(){
  Serial.begin(9600);  
  pinMode (vout,INPUT); 
  pinMode (shsw,OUTPUT);
  pinMode (clk,OUTPUT);
  pinMode (pin_shut,OUTPUT);
  pinMode (pin_rog,OUTPUT);  
  //1MHZ Clk Signal
  TCCR1A = ( (1<< COM1A0) );
  TCCR1B = ( (1<<WGM12) | (1<<CS10));
  TIMSK1 = 0;
  OCR1A = 7;
  //1MHZ Clk Signal
  attachInterrupt(digitalPinToInterrupt(interruptPinCounter), changeCLK, RISING);
}

void loop(){

  digitalWrite(clk,HIGH);
  digitalWrite(pin_rog,HIGH);
  digitalWrite(pin_shut,HIGH);
  digitalWrite(clk,LOW);
  digitalWrite(clk,HIGH);
  digitalWrite(pin_rog,LOW);
  

 
}


void rog(){         
  digitalWrite(pin_rog,LOW);
}


void laser_on(){
  digitalWrite(pinLaser, HIGH);    // emit red laser 
}

void changeCLK(){
  pulseCount++;
  if(pulseCount > 2087){
    pulseCount = 0;
  }
  println(pulseCount);
}
