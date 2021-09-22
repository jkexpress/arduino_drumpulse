# arduino_drumpulse

Arduino microphone producing a pulse of LEDs v1 using FASTLED library

I used an Arduino UNO , you will need a bigger power supply for more LEDs. 
add a resistor between the DataPIN and the LEDs , Usually add a capacitor across the LED strip power pins 

Configurable for :
#define NUM_LEDS 12
 
#define DATA_PIN 6
#define CLOCK_PIN 13
const byte interruptPin = 2; //Uno takes pin  1 or 2 I think , put the digital output of the microphone sensor on 2
pinMode(12,OUTPUT); //turn on sounds sensor - I put its power pin on 12 save on soldering
digitalWrite(12, HIGH);
pinMode(interruptPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(interruptPin), pushpins, CHANGE);   // Call the function pushpins if Pin 2 goes high

