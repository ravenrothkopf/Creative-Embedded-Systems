#include <Adafruit_GFX.h>
#include <TFT_eSPI.h>
#include <Adafruit_ST7789.h> 
#include <Pangodream_18650_CL.h> 

TFT_eSPI tft = TFT_eSPI(135, 240); 

// Define constants for colors
#define YELLOW 0xFFE8
#define ORANGE 0xFDA7
#define PURPLE 0xB47F
#define BLUE   0xAE3F
#define GREEN  0xB6F1
#define PINK   0xE49F
#define RED    0xEF91
#define LIGHT_YELLOW  0xFFD7
#define LIGHT_ORANGE  0xFF35
#define LIGHT_PURPLE  0xDE5F
#define LIGHT_BLUE    0xCF9F
#define LIGHT_GREEN   0xE77A
#define LIGHT_PINK    0xFE9C
#define LIGHT_RED     0xFEDB
#define PINK_BG       0xF538
#define BATTERY_GREEN 0x07C0

#define ADC_PIN 34
#define CONV_FACTOR 1.8
#define READS 20
Pangodream_18650_CL BL(ADC_PIN, CONV_FACTOR, READS);

// Define heart messages and colors
const char *heartMessages[][2] = {
  {"I LUV", "YOU"}, 
  {"SAY", "YES"}, 
  {"HUG", "ME<3"}, 
  {"BE", "MINE"}, 
  {"TEXT", "ME:)"}, 
  {"OMG", "LOL"}, 
  {"TRUE", "LOVE"},
  {"XOXO", "HUGS"},
  {"MISS", "YOU"},
  {"CUTIE", "PIE"},
  {"SWEET", "PEA"},
  {"CRAZY", "4 U"},
  {"FRND", "ZONE"},
  {"YOU", "ROCK"},
  {"SWEET", "HEART"}
};
uint16_t heartColors[] = {YELLOW, ORANGE, PURPLE, BLUE, GREEN, PINK, 
                          LIGHT_YELLOW, LIGHT_ORANGE, LIGHT_PURPLE, 
                          LIGHT_BLUE, LIGHT_GREEN, LIGHT_PINK, RED, LIGHT_RED};
uint16_t messageColors[] = {RED, TFT_BLACK};

// Global variables for text positions
uint16_t x1, textPosY1, x2, y2;

unsigned long previousMillis = 0; 
const long interval = 5000; 
bool showBattery = false; 

void displayBattery(){
  tft.setTextColor(BATTERY_GREEN);
  tft.drawFloat(BL.getBatteryChargeLevel(), 3, 150, 0, 1);
}

void setup() {
  tft.init();
  tft.setRotation(3);
  // Display battery on right builtin press
  attachInterrupt(35, displayBattery, FALLING);
 
  // Set up fonts and text properties
  tft.setTextSize(2); 
  // tft.setFreeFont(&FreeMono20pt7b);

  uint16_t w1, h1, w2, h2;

  uint16_t heartCenterX = tft.width() / 2;
  uint16_t heartCenterY = tft.height() / 2 - 10; 

  w1 = tft.width() / 2; 
  h1 = tft.height() / 4; 
  w2 = tft.width() / 2; 
  h2 = tft.height() / 4; 
  
  x1 = heartCenterX - w1 / 2 + 18;
  x2 = heartCenterX - w2 / 2 + 17; 
  textPosY1 = heartCenterY - 5; 
  y2 = heartCenterY + 12; 

  // Set screen Back Light brightness
  pinMode(TFT_BL, OUTPUT);
  ledcSetup(0, 5000, 8); // 0-15, 5000, 8
  ledcAttachPin(TFT_BL, 0); // TFT_BL, 0 - 15
  ledcWrite(0, 100); // 0-15, 0-255 (with 8 bit resolution); 0=totally dark;255=totally shiny
}

void loop() {
  unsigned long currentMillis = millis(); 

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Pick a random message and color
    int messageIndex = random(0, 14); 
    const char *message1 = heartMessages[messageIndex][0];
    const char *message2 = heartMessages[messageIndex][1];
    uint16_t heartColor = heartColors[random(0, 13)]; 
    uint16_t textColor = messageColors[random(0, 1)]; 
    
    // Display heart and messages
    tft.fillScreen(TFT_BLACK);
    drawHeart(heartColor);
    drawMessage(message1, message2, textColor);
    
    // Deep sleep for 5 seconds
    esp_deep_sleep(5000000);
  }
}

void drawHeart(uint16_t color){
  // Outline
  tft.fillCircle(78, 59, 33, PINK_BG);
  tft.fillCircle(119, 56, 31, PINK_BG);
  tft.fillTriangle(61, 88, 100, 120, 140, 80, PINK_BG);

  // Main heart
  tft.fillCircle(80, 60, 30, color);
  tft.fillCircle(120, 60, 30, color);
  tft.fillTriangle(65, 85, 100, 120, 142, 80, color);
}

void drawMessage(const char *m1, const char *m2, uint16_t textColor){
  // tft.setCursor(x1, textPosY1);
  tft.setTextColor(TFT_RED);
  // tft.setFreeFont(MYFONT);
  tft.drawString(m1, x1, textPosY1);

  tft.setCursor(x2, y2);
  tft.print(m2);
}
