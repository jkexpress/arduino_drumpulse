//send 2 LEDs to cascade - working
// now add the sound switch (working), increment colour (working )  and boom
//could use parsed intensity to speed the light path

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 12
 
#define DATA_PIN 6
#define CLOCK_PIN 13
int sensorPin =A1 ;  // define analog port A0 for intensity later
int value = 0;    //set value to 0

const byte interruptPin = 2; //Uno takes 1 or 2 I think
volatile byte state = LOW;

// Define the array of leds which have parameters 
CRGB leds[NUM_LEDS];

void setup() { 
    pinMode(12,OUTPUT); //turn on sounds sensor
    digitalWrite(12, HIGH);
    //pinMode(2,INPUT); // pull pin
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), pushpins, CHANGE);

 
    // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
    blankout();
     delay(200);
    leds[0] = CRGB::Black;
    leds[1] = CRGB::Red;
    leds[3] = CRGB::Red;
    leds[2] = CRGB::Black;
}

void loop() { 
   cascade();
  
}

void cascade(){
for (int j=NUM_LEDS-1;j>0;j--){
  leds[j] = leds[j-1];
  //leds[j-1] = CRGB::Black;
    FastLED.show();
    delay(5);
  }
}

void blankout(){
     //turn all black
     for (int i=0; i <=NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
    }
     FastLED.show();

}

void pushpins(){
  leds[0] = CRGB::Black;
  leds[1] = CHSV(random8(96), 200, 190);
  leds[2] = CRGB::Black;
  leds[3] = leds[1];  
}
