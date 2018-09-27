/*
 * File: lab3.ino
 * Author: Matthew Polsom
 * Github: https://github.com/MattMan569/CS-207-Lab/tree/master/lab3
 * Date: 20th September, 2018
 * 
 * Course: CS 207 Lab
 * Lab Number: 3
 * 
 * Program Name: LED Buttons
 * 
 * Program Description: This program switches two LEDs between on and off. Only one LED
 *   is on at once. Button 1 turns LED 1 on and LED 2 off, and vice versa for button 2.
 *
 * Setup: Schematic available at https://github.com/MattMan569/CS-207-Lab/blob/master/lab3/CS207L3_Schematic.pdf
 */

// Global variables
namespace global
{
  // Pin definitions
  int const buttonPinOne = 2;
  int const buttonPinTwo = 3;
  int const ledPinOne = 11;
  int const ledPinTwo = 12;
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing setup... ");

  // Pin setup
  pinMode(global::buttonPinOne, INPUT);
  pinMode(global::buttonPinTwo, INPUT);
  pinMode(global::ledPinOne, OUTPUT);
  pinMode(global::ledPinTwo, OUTPUT);

  // Set the initial state of the board to LED 1 high and LED 2 low
  digitalWrite(global::ledPinOne, HIGH);
  digitalWrite(global::ledPinTwo, LOW);
  
  Serial.println("Setup finished.\n");
  Serial.flush();
}

void loop()
{
  checkButtons();
}

// Check the current state of the buttons
void checkButtons()
{
  // The buttons are wired in a pull-up circuit
  // Button 1 turns LED 1 on and LED 2 off,
  // vice versa for button 2
  if(digitalRead(global::buttonPinOne))
  {
    digitalWrite(global::ledPinOne, HIGH);
    digitalWrite(global::ledPinTwo, LOW);
  }
  if(!digitalRead(global::buttonPinTwo))
  {
    digitalWrite(global::ledPinOne, LOW);
    digitalWrite(global::ledPinTwo, HIGH);
  }
}
