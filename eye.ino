#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "all_frames.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Delay giữa frame (~80-100 FPS thực tế)
#define FRAME_DELAY 10

void setup() {
  Serial.begin(115200);

  // Tăng tốc I2C
  Wire.begin(21,22);
  Wire.setClock(800000);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }

  display.clearDisplay();
  display.display();

  Serial.println("OLED ready");
}

void loop() {

  for(int i = 0; i < TOTAL_FRAMES; i++) {

    display.clearDisplay();

    display.drawBitmap(
      0,
      0,
      frames[i],
      FRAME_WIDTH,
      FRAME_HEIGHT,
      SSD1306_WHITE
    );

    display.display();

    delay(FRAME_DELAY);
  }
}