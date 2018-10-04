/* 
  Author: Alex Clarke
  Modified by: Matthew Polsom 4th October, 2018
  Course: CS 207 Lab
  Lab Number: 4
  GitHub: https://github.com/MattMan569/CS-207-Lab
 */

//constants for this sketch
const int ledPin = 10;
const int photoResistorPin = A0;

// variables for this sketch
int photoResistorValue;
int frequency;

void setup()
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
}



void loop()
{
  //read voltage from the potentiometer
  photoResistorValue = analogRead(photoResistorPin);
  Serial.println(photoResistorValue);

  // LED turns on when it is dark, off when bright
  if(photoResistorValue < 600)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
