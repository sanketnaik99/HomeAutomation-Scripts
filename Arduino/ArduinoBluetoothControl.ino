#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
int state = 0;
int message;
int Dev1 = 8;  //Defining the First Pin of the relay module
void setup()
{
 pinMode(Dev1,OUTPUT);  //Setting up the First pin of Relay module as OUTPUT Pin
 digitalWrite(Dev1,HIGH);
 BTserial.begin(9600); //Setting up Bluetooth Software Serial
}
 
 
void loop()
{
   if (BTserial.available()) //Looping to listen for incoming data continously
    {
      message = BTserial.read();  //Setting incoming data message variable 

      //Flipping relay switch accoring to the current state
      if(message = 7){
      if(state == 0){
        state = 1;
        digitalWrite(Dev1,LOW);
      }else if (state == 1) {
        state = 0;
        digitalWrite(Dev1, HIGH);
      }
      //End of code for First Pin of the relay module  
    }
    }
  delay(500);
}
