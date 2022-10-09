#include <Arduino.h>
#include <FastLED.h>

const int pinButton = 23;
int ButtonState = 99;
int HueValue = HUE_PURPLE;

#define NUM_LEDS 60
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

int i = 0, h = 0, s = 0, v = 0;
int direction = 1;
int brightness = 1;

void setup()
{
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(pinButton, INPUT);
  Serial.begin(9600);
}

void loop()
{

  // put your main code here, to run repeatedly:\  // Turn the LED on, then pause
  // leds[0] = CRGB::Red;
  // fill_solid(&(leds[0]),NUM_LEDS,CRGB::Red);
  // leds[0].setHue(224);

  int stateButton = digitalRead(pinButton);

  if (stateButton == 0)
  {
    Serial.println(stateButton);

    if (ButtonState != stateButton)
    {
      if (HueValue == HUE_PURPLE)
      {
        HueValue = HUE_AQUA;
        Serial.println("Switch to AQUA");
      }
      else
      {
        HueValue = HUE_PURPLE;
        Serial.println("Switch to PURPLE");
      }
      ButtonState = stateButton;
    }
  }
  else
  {
    h++;
    if (v <= 100)
      brightness = 1;
    else if (v >= 150)
      brightness = -1;
    Serial.println(HueValue);
    for (i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CHSV(HueValue, 255, v);
      // FastLED.show();
    }
    v = v + brightness;
    ButtonState = stateButton;

  }
  FastLED.delay(32);
}