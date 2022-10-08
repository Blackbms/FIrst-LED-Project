#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 60
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

int i=0,h=0,s=0,v=0;
int direction = 1;
int brightness = 1;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds,NUM_LEDS);
  
}

void loop() {
  
  // put your main code here, to run repeatedly:\  // Turn the LED on, then pause
  //leds[0] = CRGB::Red;
  //fill_solid(&(leds[0]),NUM_LEDS,CRGB::Red);
  //leds[0].setHue(224);
  h++;
  
  if (v <= 100) brightness = 1;
    else if (v >= 150) brightness = -1;

  for (i=0;i<NUM_LEDS;i++){
    leds[i] = CHSV(HUE_AQUA,255,v);
  //FastLED.show();
  }
  FastLED.delay(32);
  v = v + brightness;
}