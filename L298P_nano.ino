#include <SoftwareSerial.h>
//SoftwareSerial BTSerial(2, 3); // 接收腳, 傳送腳
/* Input for motorA:
   IN1      IN2      Action
   LOW      LOW      Motor Stop
   HIGH     LOW      Motor moves forward  
   LOW      HIGH     Motor moves backward
   HIGH     HIGH     Motor Stop
*/   
const int motorIn1 = 8;//前輪
const int motorIn2 = 9;
const int motorIn3 = 10;//後輪      
const int motorIn4 = 11;  

int state = 0;
int value;


const int DELAY = 1000;

void setup()  
{
  //BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);    
  
}

void loop()
{ 
  if(Serial.available())
  {
    value = Serial.read();
    Serial.println(value);
    switch(value)
    {
      case 119:
        forward();
        state = 1;
        break;
        
      case 115:
        backward();
        state = 2;
        break;
        
      case 97:
        if(state == 1){
          forward();
          left();
          state = 0;
          }else if(state == 2){
           backward();
           left();
           state = 0;  
          }else{
           left();  
          }
        break;
        
      case 100:
        if(state == 1){
          forward();
          right();
          state = 0;
          }else if(state == 2){
            backward();
            right();
            state = 0;  
          }else{
            right();  
          }
        right();
        break;
        
      default:
        Stop();
        break;
      }
    }
}

void left()
{
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, HIGH);
  }

void right()
{
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  }

void forward()
{
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, HIGH);
  }

void backward()
 {
  digitalWrite(motorIn3, HIGH);
  digitalWrite(motorIn4, LOW);
  }

void Stop()
{
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, LOW);
  }
