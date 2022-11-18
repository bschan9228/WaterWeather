#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

#define GFXFF 1
#define FF18 &FreeSans12pt7b

TFT_eSPI tft = TFT_eSPI(320, 240); // Invoke custom library

unsigned long drawTime = 0;

void setup(void)
{
  tft.init();
  tft.setRotation(1);
  tft.setFreeFont(FF18);

  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK);

  tft.drawNumber(5, 100, 100, 2);
}

void loop()
{
}
