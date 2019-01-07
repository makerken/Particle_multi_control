// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

// this devices ID must match in the .html

// change to your LED strip details
#define PIXEL_PIN D2
#define PIXEL_COUNT 240
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

bool pwr = false;
int color24bit = 24000;
int hueSlider = 1160;
int brightnessSlider = 31;

char myJSON[70] = "";

void setup() {
    
    strip.begin();
    
    Particle.variable("json", myJSON);
    Particle.function("room", control);

    strip.show(); // Initialize all pixels to 'off'

}

void loop() {
    
    delay(2000);
    
    sprintf( myJSON, "{\"p\":%d,\"sh\":%d,\"sb\":%d}", pwr, hueSlider, brightnessSlider);
        
}

int control( String value ) {
    
    // accepts format 1_23563_663_234, power_24bitColor_hue_brightness
    
    String roomControl[4];
    String delimiter = "_";
    int j = 0;
    int i = 0;
    
    for (i = 0; i < value.length(); i++) {
        
        if (value[i] == *delimiter) {
            j++;
        } else {
            roomControl[j] += value[i];
        }
        
    }
    
    pwr = roomControl[0].toInt();
    color24bit = roomControl[1].toInt();
    hueSlider = roomControl[2].toInt();
    brightnessSlider = roomControl[3].toInt();
  
    if(pwr == true) {
        for(i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, color24bit);
        }
    } else {
        for(i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, 0);
        }
    }
    
    strip.show();

    return 1;
    
}