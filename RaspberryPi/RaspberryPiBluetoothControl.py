import bluetooth
import RPi.GPIO as GPIO  # calling for header file which helps in using GPIOs of PI


Dev1 = 17   #The GPIO pin for the first relay module
            #Copy the same declaration again and give a pin number to each device

status1 = 0 #Status Flag for the Device

# DECLARE THE STATUS FLAG FOR A NEW DEVICE


GPIO.setmode(GPIO.BCM)     #programming the GPIO by BCM pin numbers. (like PIN40 as GPIO21)
GPIO.setwarnings(False)
GPIO.setup(Dev1,GPIO.OUT) 
GPIO.output(Dev1,1)

# ADD THE NEW DEVICES YOU WANT TO SETUP OVER HERE




def flipStatus(stat):  #Function to flip the status Flag
    if stat == 0:
        stat = 1
    else:
        stat = 0
    return stat

while 1:
    server_socket=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
    port = 1
    server_socket.bind(("",port))
    server_socket.listen(1)

    try:
        client_socket,address = server_socket.accept()
        print ("Accepted connection from ",address)
        current = str(status1) #sending the current status of the devices
        client_socket.send(current)
        still_connected = True

        while still_connected:  #Loop for continously listening for incoming data
            print("Ready for Data")
            data = client_socket.recv(1024)
            print ("Received: %s" % data)
            data=int(data)
    
            if (data == 0):
                GPIO.output(Dev1,status1)
                print ("DEV1 Switched")
                status1 = flipStatus(status1)

            # ADD A UNIQUE DATA VALUE IN THE IF STATEMENT AND WRITE THE NAME OF THE
            # STATUS FLAG IN THE SNIPPET
                
    
            if (data == 99):
                print ("Exiting")
                client_socket.close()
                server_socket.close()
            client_socket.getpeername()
    except:
        still_connected = False
        c = input("Device disconnected\nDo you want to Search for new device? (Enter y/n) ")
