#include <FastLED.h>

#define morning_LEDZ1 2
#define morning_LEDZ2 3

#define day_LEDZ1 4
#define day_LEDZ2 5

#define evening_LEDZ1 6
#define evening_LEDZ2 7

#define night_LEDZ1 8
#define night_LEDZ2 9

#define batteries_LEDZ 10
#define overUse_LEDZ 11


#define d1 12
#define d2 13
#define d3 13

//number of LED's in strip
#define NUM_LEDZ 10
CRGB morning_LED1_ARRAY[3];
CRGB morning_LED2_ARRAY[NUM_LEDZ];

CRGB day_LED1_ARRAY[NUM_LEDZ];
CRGB day_LED2_ARRAY[NUM_LEDZ];

CRGB evening_LED1_ARRAY[NUM_LEDZ];
CRGB evening_LED2_ARRAY[NUM_LEDZ];

CRGB night_LED1_ARRAY[NUM_LEDZ];
CRGB night_LED2_ARRAY[NUM_LEDZ];

CRGB batteries_LED_ARRAY[NUM_LEDZ];
CRGB overUse_LED_ARRAY[NUM_LEDZ];

CRGB a1[NUM_LEDZ];
CRGB a2[NUM_LEDZ];
CRGB a3[NUM_LEDZ];


void setup() {
  FastLED.addLeds<WS2812B, morning_LEDZ1, GRB>(morning_LED1_ARRAY, 3);
  FastLED.addLeds<WS2812B, morning_LEDZ2, GRB>(morning_LED1_ARRAY, NUM_LEDZ);
  FastLED.addLeds<WS2812B, day_LEDZ1, GRB>(day_LED1_ARRAY, NUM_LEDZ);
  FastLED.addLeds<WS2812B, day_LEDZ2, GRB>(day_LED2_ARRAY, NUM_LEDZ);
  FastLED.addLeds<WS2812B, evening_LEDZ1, GRB>(evening_LED1_ARRAY, NUM_LEDZ);
  FastLED.addLeds<WS2812B, evening_LEDZ2, GRB>(evening_LED2_ARRAY, NUM_LEDZ);
  FastLED.addLeds<WS2812B, night_LEDZ1, GRB>(night_LED1_ARRAY, NUM_LEDZ);
  FastLED.addLeds<WS2812B, night_LEDZ2, GRB>(night_LED2_ARRAY, NUM_LEDZ);
  FastLED.addLeds<WS2812B, batteries_LEDZ, GRB>(batteries_LED_ARRAY, NUM_LEDZ);
  FastLED.addLeds<WS2812B, overUse_LEDZ, GRB>(overUse_LED_ARRAY, NUM_LEDZ);
  FastLED.addLeds<WS2812B, d1, GRB>(a1, NUM_LEDZ);
  FastLED.addLeds<WS2812B, d2, GRB>(a2, NUM_LEDZ);
  FastLED.addLeds<WS2812B, d3, GRB>(a3, NUM_LEDZ);
  FastLED.setBrightness(50);
}

void loop() {
  for(int i=0; i<NUM_LEDZ; i++){
  
  morning_LED2_ARRAY[i] =CRGB(6, 128, 37);
  day_LED1_ARRAY[i]=CRGB(6, 128, 37);
  day_LED2_ARRAY[i]=CRGB(6, 128, 37);
  evening_LED1_ARRAY[i]=CRGB(6, 128, 37);
  evening_LED2_ARRAY[i]=CRGB(6, 128, 37);
  night_LED1_ARRAY[i]=CRGB(6, 128, 37);
  night_LED2_ARRAY[i]=CRGB(6, 128, 37);
  batteries_LED_ARRAY[i]=CRGB(6, 128, 37);
  overUse_LED_ARRAY[i]=CRGB(6, 128, 37);
  a1[i]=CRGB(6, 128, 37);
  a2[i]=CRGB(6, 128, 37);
  a3[i]=CRGB(6, 128, 37);
  
}

}
