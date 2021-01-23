#include "FastLED.h"
#define NUM_LEDS 99
// Data pin that led data will be written out over
#define DATA_PIN 5
boolean loading;
CRGB leds[NUM_LEDS];// This is an array of leds.  One item for each led in your strip.

int bank_1_size = 10;  //Number of LEDs in bank 1
int bank_2_size = 10;  //Number of LEDs in bank 2
int c; //bank1 display
int d; //bank2 display
int offset = 25; //Number of LEDs between banks
int bank2; //bank 2 start locatio

void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
   // delay(50);
      Serial.begin(9600);
      FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      FastLED.setBrightness(8);
      loading= true;
}

// Main endless Loop
void loop() {



  
  int modeNum;

//check if there is infor on the serial port to read
if (Serial.available()>0){
modeNum=Serial.read();

}

 switch (modeNum) {
    case 1: white();  break;
    case 2: blue2(); break; 
    case 3:  green(); break;
    case 4: orange();  break;
    case 5: blue();  break;
   // case 6: glow(); break;
    case 7: green(); break;
    
   
  
  }
  // delay(1);  
   render();
  
  
}

void green(){

  if (loading) {
    FastLED.clear();
    loading = false;
  }
   
   for(int bank1 = 0; bank1 < NUM_LEDS; bank1 = bank1 + 1) {
      // Turn our current led on to white, then show the leds

 if (bank1 - offset <= -1)
 { bank2 = NUM_LEDS + bank1 - offset ;}

 else
 { bank2 = bank1 - offset ;}
 
      leds[bank1] = CRGB::ForestGreen; //colour of bank1
      leds[bank2] = CRGB::ForestGreen; //colour of bank 2

      // Show the leds 
      FastLED.show();

      // Wait a little bit
      delay(10);

      // Turn our current led back to black for the next loop around
    if (bank1 < bank_1_size) 
    { c = (bank1 + NUM_LEDS - bank_1_size );} 
    else 
    { c = (bank1 - bank_1_size );}
      leds[c] = CRGB::ForestGreen; //colour between bank1 & bank2
      //Color:LightSkyBlue;Indigo;Goldenrod;AntiqueWhite;
      
 if (bank2 < bank_2_size ) 
    { d = (bank2 + NUM_LEDS - bank_2_size );} 
    else 
    { d = (bank2 - bank_2_size   );}
      leds[d] = CRGB::Black; //colour between bank2 and bank 1
      
   }
  
  }
void blue(){


     if (loading) {
    FastLED.clear();
    loading = false;
  }
   for(int bank1 = 0; bank1 < NUM_LEDS; bank1 = bank1 + 1) {
      // Turn our current led on to white, then show the leds

 if (bank1 - offset <= -1)
 { bank2 = NUM_LEDS + bank1 - offset ;}

 else
 { bank2 = bank1 - offset ;}
 
      leds[bank1] = CRGB::LightSkyBlue; //colour of bank1
      leds[bank2] = CRGB::LightSkyBlue; //colour of bank 2

      // Show the leds 
      FastLED.show();

      // Wait a little bit
      delay(10);

      // Turn our current led back to black for the next loop around
    if (bank1 < bank_1_size) 
    { c = (bank1 + NUM_LEDS - bank_1_size );} 
    else 
    { c = (bank1 - bank_1_size );}
      leds[c] = CRGB::LightSkyBlue; //colour between bank1 & bank2
      //Color:LightSkyBlue;Indigo;Goldenrod;AntiqueWhite;
      
 if (bank2 < bank_2_size ) 
    { d = (bank2 + NUM_LEDS - bank_2_size );} 
    else 
    { d = (bank2 - bank_2_size   );}
      leds[d] = CRGB::Black; //colour between bank2 and bank 1
       
   }
}

   
void white(){

     if (loading) {
    FastLED.clear();
    loading = false;
  }
   for(int bank1 = 0; bank1 < NUM_LEDS; bank1 = bank1 + 1) {
      // Turn our current led on to white, then show the leds

 if (bank1 - offset <= -1)
 { bank2 = NUM_LEDS + bank1 - offset ;}

 else
 { bank2 = bank1 - offset ;}
 
      leds[bank1] = CRGB::White; //colour of bank1
      leds[bank2] = CRGB::White; //colour of bank 2

      // Show the leds 
      FastLED.show();

      // Wait a little bit
      delay(10);

      // Turn our current led back to black for the next loop around
    if (bank1 < bank_1_size) 
    { c = (bank1 + NUM_LEDS - bank_1_size );} 
    else 
    { c = (bank1 - bank_1_size );}
      leds[c] = CRGB::White; //colour between bank1 & bank2
      //Color:LightSkyBlue;Indigo;Goldenrod;AntiqueWhite;
      
 if (bank2 < bank_2_size ) 
    { d = (bank2 + NUM_LEDS - bank_2_size );} 
    else 
    { d = (bank2 - bank_2_size   );}
      leds[d] = CRGB::Black; //colour between bank2 and bank 1
       
   }
}
void orange(){
     if (loading) {
    FastLED.clear();
    loading = false;
  }
   for(int bank1 = 0; bank1 < NUM_LEDS; bank1 = bank1 + 1) {
      // Turn our current led on to white, then show the leds

 if (bank1 - offset <= -1)
 { bank2 = NUM_LEDS + bank1 - offset ;}

 else
 { bank2 = bank1 - offset ;}
 
      leds[bank1] = CRGB::OrangeRed; //colour of bank1
      leds[bank2] = CRGB::OrangeRed; //colour of bank 2

      // Show the leds 
      FastLED.show();

      // Wait a little bit
      delay(10);

      // Turn our current led back to black for the next loop around
    if (bank1 < bank_1_size) 
    { c = (bank1 + NUM_LEDS - bank_1_size );} 
    else 
    { c = (bank1 - bank_1_size );}
      leds[c] = CRGB::OrangeRed; //colour between bank1 & bank2
      //Color:LightSkyBlue;Indigo;Goldenrod;AntiqueWhite;
      
 if (bank2 < bank_2_size ) 
    { d = (bank2 + NUM_LEDS - bank_2_size );} 
    else 
    { d = (bank2 - bank_2_size   );}
      leds[d] = CRGB::Black; //colour between bank2 and bank 1
       
   }
}
void blue2(){
    if (loading) {
    FastLED.clear();
    loading = false;
  }
   
   for(int bank1 = 0; bank1 < NUM_LEDS; bank1 = bank1 + 1) {
      // Turn our current led on to white, then show the leds

 if (bank1 - offset <= -1)
 { bank2 = NUM_LEDS + bank1 - offset ;}

 else
 { bank2 = bank1 - offset ;}
 
      leds[bank1] = CRGB::MidnightBlue; //colour of bank1
      leds[bank2] = CRGB::MidnightBlue; //colour of bank 2

      // Show the leds 
      FastLED.show();

      // Wait a little bit
      delay(10);

      // Turn our current led back to black for the next loop around
    if (bank1 < bank_1_size) 
    { c = (bank1 + NUM_LEDS - bank_1_size );} 
    else 
    { c = (bank1 - bank_1_size );}
      leds[c] = CRGB::MidnightBlue; //colour between bank1 & bank2
      //Color:LightSkyBlue;Indigo;Goldenrod;AntiqueWhite;
      
 if (bank2 < bank_2_size ) 
    { d = (bank2 + NUM_LEDS - bank_2_size );} 
    else 
    { d = (bank2 - bank_2_size   );}
      leds[d] = CRGB::Black; //colour between bank2 and bank 1
       
   }  
}


void render(){

for (int i=0;i<99;i++){
  leds[i] = CRGB::Black;
  }

}
