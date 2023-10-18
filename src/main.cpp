// Include necessary libraries
#include <TFT_eSPI.h>
#include <math.h>

// Initialize the TFT screen
TFT_eSPI tft = TFT_eSPI();

// Define center of the screen
#define CENTER_X (tft.width() / 2)
#define CENTER_Y (tft.height() / 2)
#define TRIANGLE_SIZE 50  // Half size of the triangle

// Variables to store the previous triangle's vertices
int16_t prev_x1, prev_y1, prev_x2, prev_y2, prev_x3, prev_y3;

// Function to draw a triangle rotated by a specified angle
void drawRotatedTriangle(float angleDegrees) {
  // Convert angle from degrees to radians
  float angleRadians = angleDegrees * (M_PI / 180.0);  

  // Calculate the three points of the triangle using trigonometry
  int16_t x1 = CENTER_X + TRIANGLE_SIZE * sin(angleRadians);
  int16_t y1 = CENTER_Y - TRIANGLE_SIZE * cos(angleRadians);

  int16_t x2 = CENTER_X + TRIANGLE_SIZE * sin(angleRadians + 2.0 * M_PI / 3.0);
  int16_t y2 = CENTER_Y - TRIANGLE_SIZE * cos(angleRadians + 2.0 * M_PI / 3.0);

  int16_t x3 = CENTER_X + TRIANGLE_SIZE * sin(angleRadians + 4.0 * M_PI / 3.0);
  int16_t y3 = CENTER_Y - TRIANGLE_SIZE * cos(angleRadians + 4.0 * M_PI / 3.0);

  // Erase the previous triangle by drawing over it with the background color
  tft.fillTriangle(CENTER_X, CENTER_Y, prev_x1, prev_y1, prev_x2, prev_y2, TFT_BLACK);
  tft.fillTriangle(CENTER_X, CENTER_Y, prev_x2, prev_y2, prev_x3, prev_y3, TFT_BLACK);
  
  // Draw the new triangle
  tft.fillTriangle(CENTER_X, CENTER_Y, x1, y1, x2, y2, TFT_WHITE);
  tft.fillTriangle(CENTER_X, CENTER_Y, x2, y2, x3, y3, TFT_WHITE);

  // Update the previous triangle points for the next iteration
  prev_x1 = x1; prev_y1 = y1;
  prev_x2 = x2; prev_y2 = y2;
  prev_x3 = x3; prev_y3 = y3;
}

// Setup function runs once when the device starts
void setup() {
  // Set the TFT backlight pin as OUTPUT and turn it on
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);  

  // Initialize the TFT screen
  tft.init();
  // Set the screen rotation
  tft.setRotation(1);
  // Fill the screen with black color
  tft.fillScreen(TFT_BLACK);

  // Initialize previous triangle points to the center of the screen
  prev_x1 = prev_x2 = prev_x3 = CENTER_X;
  prev_y1 = prev_y2 = prev_y3 = CENTER_Y;
}

// Loop function runs continuously
void loop() {
  // Rotate the triangle from 0 to 360 degrees, incrementing by 5 degrees each time
  for (float angle = 0; angle < 360; angle += 5) {  
    drawRotatedTriangle(angle);
    // Delay to adjust rotation speed and make the rotation visible
    delay(100);  
  }
}
