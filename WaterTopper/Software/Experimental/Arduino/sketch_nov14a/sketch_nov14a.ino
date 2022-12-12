#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include <USB.h>

#define GFXFF 1
#define FF18 &FreeSans12pt7b

TFT_eSPI tft = TFT_eSPI(320, 240); // Invoke custom library

unsigned long drawTime = 0;


void setup(void)
{
  // USBSerial.begin();
  tft.init();
  tft.setRotation(2);
  tft.setFreeFont(FF18);

  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK);

  tft.drawNumber(8, 100, 100, 2);
  tft.drawString("Hello!", 200, 200, 2);

  // pinMode(21, OUTPUT);
  // digitalWrite(21, HIGH);
}

void loop()
{
  // if(digitalRead(46)) digitalWrite(14, HIGH);
  // else digitalWrite(14, LOW);
  delay(250);
  int a = 5;
  // USBSerial.println(digitalRead(5));
}
