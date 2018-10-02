/*
 * File: globals.h
 * Author: Matthew Polsom
 * 
 * Purpose: Contains all global variables and definitions
 */

// Global variables
namespace global
{
  // Pin definitions
  byte const redPin = 6;
  byte const greenPin = 5;
  byte const bluePin = 11;
  byte const buttonNextPin = 2;     // Select next function
  byte const buttonSelectPin = 3;   // Choose selected function
  byte const functionLed0 = 10;
  byte const functionLed1 = 9;
  byte const functionLed2 = 8;

  // Global RGB values
  // Set one of {red,green,blue} to 255, other two to 0
  byte red = 255;
  byte green = 0;
  byte blue = 0;
  byte const rgbMax = 255;

  // Current phase of the RGB LED
  // 0: red decreasing, green increasing
  // 1: green decreasing, blue increasing
  // 2: blue decreasing, red increasing
  byte rgbMode = 0;

  // Number of RGB LED modes
  byte const numRgbModes = 3;

  // Time to delay each loop
  volatile unsigned int delayTime = 1;

  // Currently selected RGB LED altering functionality
  // 0: pause the RGB LED
  // 1: double the delay time
  // 2: halve the delay time
  volatile byte selectedFunction = 0;

  // Number of RGB LED altering functionalities
  byte const numFunctions = 3;

  // The RGB LED does not change colours when paused
  volatile bool paused = false;

  // Amount of time before the next input is not considered a debounce
  unsigned long debounceTime = 200;
}
