#include <SoftwareSerial.h>
SoftwareSerial BTserial(3, 4); // RX | TX
int state1 = 0;
int message;
int Dev1 = 2;  //Defining the First Pin of the relay module
// DEFINE YOUR NEW PINS HERE


void setup()
{
 pinMode(Dev1,OUTPUT);  //Setting up the First pin of Relay module as OUTPUT Pin
 digitalWrite(Dev1,HIGH);
 BTserial.begin(9600); //Setting up Bluetooth Software Serial

//SETUP THE PINS BY COPYING THE CODE SNIPPETS AND ADDING THE DEVICE NAME
}
 
 
void loop()
{
   if (BTserial.available()) //Looping to listen for incoming data continously
    {
      message = BTserial.read();  //Setting incoming data message variable 

      //Flipping relay switch accoring to the current state
      if(message = 7){
      if(state1 == 0){
        state1 = 1;
        digitalWrite(Dev1,LOW);
      }else if (state1 == 1) {
        state1 = 0;
        digitalWrite(Dev1, HIGH);
      }
      //End of code for First Pin of the relay module 

       //ADD CODE FOR NEW RELAY MODULE PINS HERE
    }
    }
  delay(500);
}
