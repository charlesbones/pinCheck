# pinCheck
This sketch allows to check the basic status of any Arduino board by testing the pins one by one.

## Requirements
- An Arduino board
- A jumper wire

## How to use it
1. Download the sketch and upload it to the board.
2. Open the serial monitor. 

There are two different test you can run. The first one test if there is serial communication with the board by receiving a H or and L to light up the Built-in LED.

The second uses one two pins, one defined as INPUT and the other as OUTPUT and send HIGH or LOW between them. The idea of this test is to test if the port registers are working properly.

## Serial monitor

As soon as you open the serial monitor, you will be asked to defined which test you would like to run.

> Select the test you want to run (Send 0 to come back to this menu)
> 1. Pin13 Led test
> 2. Pin to pin test

*Note: You can come at anytime to this menu by sending a 0 through the serial monitor.*

### First test (Pin13 Led test)
This test is based on the Physical pixel example, part of the IDE built-in example pack. Send an H to light the Built-in LED of the board on or L to turn it off.

> Send a H or a L

### Second test (Pin to pin test)
Connect a jumper wire between the two pins you are going to test. Choose the pin you are going to use as OUTPUT first and then the Input.

You can use any digital pin from 2 to 13 and any Analog pin but set with its number i.e. A0 is 14, A1 is 15 and so on.

> Select the OUTPUT pin 
> Select the INPUT pin

The next message will give you the instruction of connecting a jumper wire between two pins.

> Please connect a jumper between pin X and Y

Now you can send a HIGH or a LOW to the input pin through the output pin and read the status of the input pin by sending an R.

> Send H or L from the output pin. If you want to read the input pin send an R




