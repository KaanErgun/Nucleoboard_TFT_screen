#include <TFT_eSPI.h>
#include <math.h>

TFT_eSPI tft = TFT_eSPI();

#define CENTER_X (tft.width() / 2)
#define CENTER_Y (tft.height() / 2)
#define TRIANGLE_SIZE 50  // Half size of the triangle

int16_t prev_x1, prev_y1, prev_x2, prev_y2, prev_x3, prev_y3;

// Function to draw a triangle rotated by a specified angle
void drawRotatedTriangle(float angleDegrees) {
  float angleRadians = angleDegrees * (M_PI / 180.0);  // Convert angle from degrees to radians

  // Calculate the three points of the triangle
  int16_t x1 = CENTER_X + TRIANGLE_SIZE * sin(angleRadians);
  int16_t y1 = CENTER_Y - TRIANGLE_SIZE * cos(angleRadians);

  int16_t x2 = CENTER_X + TRIANGLE_SIZE * sin(angleRadians + 2.0 * M_PI / 3.0);
  int16_t y2 = CENTER_Y - TRIANGLE_SIZE * cos(angleRadians + 2.0 * M_PI / 3.0);

  int16_t x3 = CENTER_X + TRIANGLE_SIZE * sin(angleRadians + 4.0 * M_PI / 3.0);
  int16_t y3 = CENTER_Y - TRIANGLE_SIZE * cos(angleRadians + 4.0 * M_PI / 3.0);

  // Erase the previous triangle
  tft.fillTriangle(CENTER_X, CENTER_Y, prev_x1, prev_y1, prev_x2, prev_y2, TFT_BLACK);
  tft.fillTriangle(CENTER_X, CENTER_Y, prev_x2, prev_y2, prev_x3, prev_y3, TFT_BLACK);
  
  // Draw the new triangle
  tft.fillTriangle(CENTER_X, CENTER_Y, x1, y1, x2, y2, TFT_WHITE);
  tft.fillTriangle(CENTER_X, CENTER_Y, x2, y2, x3, y3, TFT_WHITE);

  // Update the previous triangle points
  prev_x1 = x1; prev_y1 = y1;
  prev_x2 = x2; prev_y2 = y2;
  prev_x3 = x3; prev_y3 = y3;
}

void setup() {
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);  // Turn on the backlight

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  // Initialize previous triangle points
  prev_x1 = prev_x2 = prev_x3 = CENTER_X;
  prev_y1 = prev_y2 = prev_y3 = CENTER_Y;
}

void loop() {
  for (float angle = 0; angle < 360; angle += 5) {  // Rotate every 5 degrees
    drawRotatedTriangle(angle);
    delay(100);  // Delay to adjust rotation speed
  }
}
