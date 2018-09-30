# Home Automation Scripts
**Version 1.0**
The Raspberry Pi and Arduino compatible scripts for communicating with the Home Automation App
---
# Overview 
These scripts are written to work with the Home Automation App and are compatible with all Arduino Boards paired with an HC-06 Bluetooth Module on a Raspberry Pi Model 3+ ( also works with previous Raspberry Pi Models but a Bluetooth Dongle is required ). To run these Scripts simply download them from this repository and follow the steps for the respective platform to run them.

---

## Arduino Boards

Step 1 : Download and install the Arduino IDE from the following link :- 
https://www.arduino.cc/en/Main/Software

Step 2 : Download the Arduino compatible script from the Arduino folder of this repository.

Step 3 : Open the downloaded script in the Arduino IDE.

Step 4 : Connect your Arduino Board to your computer via USB and click on the upload button.

Step 5 : You can connect as many devices as you'd like, to do so first you have to add the following code snippets to the script.

First declare a new device and its status flag. The number that the device_name equals to is the pin number of the Arduino Digital Output Pin.
```
int Device_Name = 2;
int state2 = 0;
```

Setup your device in the void setup() loop.
```
 pinMode(Device_Name,OUTPUT); 
 digitalWrite(Device_Name,HIGH);
```

Add the Device switching logic to the void loop() method 
```
if(message = 2){
      if(state2 == 0){
        state2 = 1;
        digitalWrite(Device_Name,LOW);
      }else if (state2 == 1) {
        state2 = 0;
        digitalWrite(Device_Name, HIGH);
      }
```

Step 6 : Connect the HC-06 Bluetooth Module and a 5V Relay Module by following the diagram given below.

![](Images/Arduino%20Pin%20Layout.png)




Step 7 : Your Arduino is all set up! Follow the app guide to complete the setup process.

---

## Raspberry Pi 
Step 1 : If you're setting up a Raspberry Pi for the first time, follow this get to get up and running :- https://lifehacker.com/the-always-up-to-date-guide-to-setting-up-your-raspberr-1781419054

Step 2 : After you're done setting up your Raspberry Pi, setup remote access using VNC by following this guide :-  https://www.raspberrypi.org/documentation/remote-access/vnc/

Step 3 : To setup Bluetooth on the Raspberry Pi, open the terminal and run the following commands. These will download the required Python Modules for the Raspberry Pi.

```
sudo apt-get install bluetooth libbluetooth-dev
sudo python3 -m pip install pybluez
```

Step 4 : Connect to your Raspberry Pi using a VNC connection.

Step 5 : Download the Raspberry Pi compatible script from the Raspberry Pi folder in this repository.

Step 6 : Right Click on the downloaded '.py' file and select the Edit With Python 3.5 IDLE option.

Step 7 : If you wish to control more than one device, copy the following snippets according to the number of devices you wish to connect.

Declare the Pin number of the new device and create a status flag for it
```
Device_name = 16
status2 = 0
```

Setup the GPIO pin for the new device
```
GPIO.setup(Device_name,GPIO.OUT) 
GPIO.output(Device_name,1)
```

Add the device to the If conditions in the Incoming data listener loop
```
if (data == 1):
                GPIO.output(Device_name,status1)
                print ("Device_name Switched")
                status2 = flipStatus(status2)
```

Step 8 : Refer the following diagram to connect a relay module to your Raspberry Pi.

![](Images/Raspberry%20Pi%20Pin%20Layout.png)



Step 9 : Your Raspberry Pi is all set up! Follow the app guide to complete the setup process.

---

## App Guide
Step 1 : Once you've set up your Arduino Board or Raspberry Pi, download the app from the following link :- 

Step 2 : Open the app and click on the settings tab.

<img src="https://github.com/sanketnaik99/HomeAutomation-Scripts/blob/master/Images/Step-1.png" width="300">

  

Step 3 : Click on the Add Button option.

<img src="https://github.com/sanketnaik99/HomeAutomation-Scripts/blob/master/Images/Step-2.png" width="300">
  


Step 4 : Give a suitable name for the Device, then select the type of the device and finally enter the value that it corresponds to in your Arduino or Raspberry Pi script.

<img src="https://github.com/sanketnaik99/HomeAutomation-Scripts/blob/master/Images/Step-3.png" width="250"><img src="https://github.com/sanketnaik99/HomeAutomation-Scripts/blob/master/Images/Step-4.png" width="250"><img src="https://github.com/sanketnaik99/HomeAutomation-Scripts/blob/master/Images/Step-5.png" width="250">
  

Step 5 : The button should now appear on the Home Screen.

Step 6 : Click on the Connect to a device button to connect your Raspberry Pi or your HC-06 Module ( the PIN for the HC-06 Module is usually 1234 )

<img src="https://github.com/sanketnaik99/HomeAutomation-Scripts/blob/master/Images/Step-6.png" width="300"><img src="https://github.com/sanketnaik99/HomeAutomation-Scripts/blob/master/Images/Step-7.png" width="300">


Step 7 : You're all set up! You can now control your devices using your smartphone. 

---

## Contributors 
P Sujay Surendranath  
Sahil Nair  
Sharayu Mhaske  
Adhishree Vast
