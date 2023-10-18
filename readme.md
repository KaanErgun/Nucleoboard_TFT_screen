# Rotating Triangle on TFT Display with ST P-Nucleo-WB55

This project is designed for the ST P-Nucleo-WB55 board. It displays a triangle on a TFT screen and rotates it around its center.

## Code Explanation

The code uses the `TFT_eSPI` library to interact with the TFT display. The main components of the code include:

1. **Initialization**: The TFT screen is initialized, and its backlight is turned on.
2. **Triangle Drawing**: A function named `drawRotatedTriangle` is defined to draw a triangle rotated by a specified angle. This function calculates the vertices of the triangle based on the given angle and then draws it on the TFT screen.
3. **Main Loop**: In the main loop, the triangle is continuously rotated from 0 to 360 degrees.

## :warning: Important Note :warning:

Before running the code, ensure that the `.pio\libdeps\nucleo_wb55rg_p\TFT_eSPI\User_Setup.h` file is upgraded by replacing it with the backup file located at:

readme\User_setup.h.bak

This step is crucial for the correct configuration and functioning of the TFT display with the provided code.

## Dependencies

- `TFT_eSPI` library: Used for controlling the TFT display.

## License

This project is open-source and available under the MIT License.
