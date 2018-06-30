# XIOT-Task


Hardware Connections: Arduino Uno, Button on D3, LED on B5, Temperature Sensor on ASC0,
                      the RX of the serial monitor is connected to Pin 0 (TX of the Arduino)
                      and the TX of the serial monitor is connected to Pin 1 (RX of the Arduino).

The project Scenario: when you push the Button, the Led will open and "pressed" &"LED is ON" 
                      will appear in the serial monitor and when you close the button, LED 
                      will close and "LED is OFF" will appear in the serial monitor. Besides, 
                      there is a Temperature sensor reads the temperature every  Three seconds  
                      and send the readings (The voltage and the temperature) to the serial monitor.

The Project Technics: The button is connected to The external interrupt pin (D3) to call The 
                      (button_Reading) function when any change happens to the button using 
                      (attachInterrupt) function. Timer 2 is initialized to three seconds, 
                      after that it will interrupt the code to call (temp_Reading) function 
                      using (MsTimer2::set. Temperature sensor is connected to analog digital 
                      converter on AD0.

-Also I Attached a simulation using Proteus 7.7 Professional.

-I have a good knowledge of C language, Also have knowlegde of Arduino and AVR kits.
 
Created 25 Jun 2018
Board Arduino UNO
Arduino 1.8.2
By Mina Magdy Youssef