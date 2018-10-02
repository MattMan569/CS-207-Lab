/*
 * File: lab3_bonus.ino
 * Author: Matthew Polsom
 * SID: 200364039
 * GitHub: https://github.com/MattMan569/CS-207-Lab/tree/master/lab3
 * Date: 29th September, 2018
 * 
 * Course: CS 207 Lab
 * Lab Number: 3
 * 
 * Program Name: Controllable RGB LED
 * 
 * Program Description: This program features an RGB LED with three accompanying functions.
 *    The LED will change colours from red to green to blue then finally to red again.
 *    The first function will pause and unpause this transitional cycle.
 *    The second function will slow down the cycle, doubling the cycle's time with each execution.
 *    The third function will speed up the cycle, halving the cycle's time with each execution.
 * 
 * Setup: https://github.com/MattMan569/CS-207-Lab/blob/master/lab3_bonus/CS207L3_Bonus_Schematic.pdf
 */

#include "globals.h"

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing setup... ");

  // Pin setup
  pinMode(global::redPin, OUTPUT);
  pinMode(global::greenPin, OUTPUT);
  pinMode(global::bluePin, OUTPUT);
  pinMode(global::buttonNextPin, INPUT);
  pinMode(global::buttonSelectPin, INPUT);
  pinMode(global::functionLed0, OUTPUT);
  pinMode(global::functionLed1, OUTPUT);
  pinMode(global::functionLed2, OUTPUT);

  // Attach an interrupt for the button that changes the selected function
  attachInterrupt(digitalPinToInterrupt(global::buttonNextPin), changeSelectedFunction, FALLING);

  // Attach an interrupt for choosing and executing the selected function
  attachInterrupt(digitalPinToInterrupt(global::buttonSelectPin), chooseSelectedFunction, FALLING);

  // Initially highlight the first function
  digitalWrite(global::functionLed0, HIGH);
  
  Serial.print("Setup finished.\n\n");
  Serial.flush();
}

void loop()
{
  // Do nothing if the RGB LED is paused
  if (!global::paused)
  {
    rgbWrite(global::red, global::green, global::blue);
    rgbSet();
  }
  
  delay(global::delayTime);
}

// Set the RGB values and RGB mode
void rgbSet()
{
  // If the max RGB value has been reached switch to the next RGB mode,
  // else decrement and increment the appropriate RGB values
  switch (global::rgbMode)
  {
    // Red to green
    case 0:
      if (global::green == global::rgbMax)
        ++global::rgbMode %= global::numRgbModes;
      else
      {
        global::red--;
        global::green++;
      }
      break;
      
    // Green to blue
    case 1:
      if (global::blue == global::rgbMax)
        ++global::rgbMode %= global::numRgbModes;
      else
      {
        global::green--;
        global::blue++;
      }
      break;
      
    // Blue to red
    case 2:
      if (global::red == global::rgbMax)
        ++global::rgbMode %= global::numRgbModes;
      else
      {
        global::blue--;
        global::red++;
      }
      break;
      
    // Error
    default:
      Serial.println("Incorrect rgbSet switch value.");
      break;
  }
}

// Write the passed values to the RGB LED pins
void rgbWrite(byte red, byte green, byte blue)
{
  analogWrite(global::redPin, red);
  analogWrite(global::greenPin, green);
  analogWrite(global::bluePin, blue);
}

// Light the next function's LED and select the next function
void changeSelectedFunction()
{
  static unsigned long lastInterrupt = 0;
  unsigned long currentInterrupt = millis();

  // Check for debounces
  if ((lastInterrupt + global::debounceTime) < currentInterrupt)
  {
    // Switch the next function's LED to high and the current one's to LOW
    // then increment the selected function counter
    switch(global::selectedFunction)
    {
    case 0:
      digitalWrite(global::functionLed1, HIGH);
      digitalWrite(global::functionLed0, LOW);
      ++global::selectedFunction %= global::numFunctions;
      break;
    case 1:
      digitalWrite(global::functionLed2, HIGH);
      digitalWrite(global::functionLed1, LOW);
      ++global::selectedFunction %= global::numFunctions;
      break;
    case 2:
      digitalWrite(global::functionLed0, HIGH);
      digitalWrite(global::functionLed2, LOW);
      ++global::selectedFunction %= global::numFunctions;
      break;
    // Error
    default:
      Serial.println("Incorrect functionLedWrite switch value.");
      break;
    }

    lastInterrupt = millis();
  }
}

// Execute the functionality of the currently selected function
void chooseSelectedFunction()
{
  static unsigned long lastInterrupt = 0;
  unsigned long currentInterrupt = millis();

  // Check for debounces
  if ((lastInterrupt + global::debounceTime) < currentInterrupt)
  {
    // Execute the selected function
    switch(global::selectedFunction)
    {
      // Toggle the pause status of the RGB LED
      case 0:
        global::paused ^= true;
        break;
      // Double the delay time
      case 1:
        global::delayTime *= 2;
        break;
      // Halve the delay time
      case 2:
        if (global::delayTime != 1)
          global::delayTime /= 2;
        break;
      // Error
      default:
        Serial.println("Incorrect functionLedWrite switch value.");
        break;
    }

    lastInterrupt = millis();
  }
}
