/*
XIOT Task.

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
 
Created 25 Jun 2018
By Mina Magdy Youssef
 
*/

#include <MsTimer2.h>         // This libarary to interface timer 2 on arduino uno.

//PIN Connections.
const int led = 13;           // LED connect to B5, Pin number (13).
const int button = 3;         // Button connect to D3, Pin number (3).  
const int temp_Sensor = A0 ;  // Temperature sensor connect to A0, Pin number (1).

//Variables Initialization.
int   button_State = 0;      // This Variable to carry the state of the button.
int   reading_Buffer;        // This Variable to carry the signal of tempurature sensor from the analog pin 
float voltage_Value;         // This variable to carry the voltage depending on reading_Buffer.
float temp_Value;            // This variable to carry the temprature depending on voltage_Value.

//Functions Prototypes.
void temp_Reading();
void button_Reading();



void setup()
{
    pinMode(led,OUTPUT);     // Initialize Led Pin as Output.
    pinMode(button,INPUT);   // Initialize Button Pin as Input.
    Serial.begin(9600);      // Initialize serial communication at 9600 bits per second.

    MsTimer2::set(3000, temp_Reading); // This function sets the timer 2 and takes the time with millisecond. 
                                       // Also, it takes the function which will be called after the timer is cleared.
                                       // Now it will set to Three seconds periodically, calling temp_Reading function.
 
    MsTimer2::start();                 // This function enables the interrupt.
/*
    This function takes: the pin which is connected to the external interrupt, the function which will be called when 
    the interrupt will happen and the mode which defined when the interrupt should trigger.
 
    Now the external interrupt connected to the button pin, calling button_Reading function and the interrupt will 
    trigger in any change will happen to the button pin.
*/  
    attachInterrupt(digitalPinToInterrupt(button),button_Reading, CHANGE);
  

}

void loop()
{
   
}
/*
Mission: This function calculates the temperature
Input  : Nothing.
Output : Nothing.
Notes  : This function will make the "LED" High if the "button_state" is Low and will make the "LED" Low if the "button_state" is High.
*/
void temp_Reading()
{
    reading_Buffer = analogRead(temp_Sensor);
    voltage_Value = ((reading_Buffer * 5.0) / 1024);    //calculate the decimal value which equivalent to the voltage which temperature sensor already reads.
    temp_Value = (voltage_Value - 0.5) * 100;           // convert temperature value to celsius.
    Serial.print("\nv = \'");
    Serial.print(voltage_Value);
    Serial.println("\n");
    Serial.print("Temperature = \'");
    Serial.print(temp_Value);
    Serial.println(" C");
    Serial.println("\n");
}
/*
Mission: This function controls in the state of the led dependeing on the state of the button.
Input  : Nothing.
Output : Nothing.
Notes  : This function will make the "LED" High if the "button_state" is Low and will make the "LED" Low if the "button_state" is High.
*/
void button_Reading()
{
    button_State = digitalRead(button);
  
    if  (button_State == LOW)
    {
        digitalWrite(led,HIGH);
    
        Serial.print("\n");
        Serial.println("\nPressed"); 
    
        Serial.println("\nLED is ON "); 
        Serial.println("\n");
    }
    else
    {
        digitalWrite(led,LOW);
    
        Serial.println("\nLED is OFF "); 
        Serial.println("\n");
    }
}

