/* 
 Playing with pots.
 Written 23 Aug 2011 by Alex Clarke
 */

//constants for this sketch
const int ledPin = 10;
const int potPin = A0;

// variables for this sketch
int pot_value;
int frequency;

void setup()
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
}



void loop()
{
  //read voltage from the potentiometer
  pot_value = analogRead(potPin);
  Serial.println(pot_value);

  if(pot_value < 600)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
