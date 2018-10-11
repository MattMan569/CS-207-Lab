/*
 * Program Name: exercise2.ino
 * Description: This program turns on a fan when the temperature read from
 * a temperature sensor is above 26 degrees Celsius. The temperature is printed
 * in both Celsius and Fahrenheit.
 * 
 * Setup: temperature sensor to A0
 *        for motor setup see: http://www.cs.uregina.ca/Links/class-info/207/Lab5/ §1.1
 * 
 * Date: 11th Oct. 2018
 * 
 * Name: Matthew Polsom
 */

// Pin to transistor base, opens motor circuit
int const motorPin = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  int reading;
  float volts, celsius, fahrenheit;

  // Read the raw temperature sensor value
  reading = analogRead(A0);

  // Convert the raw value to volts
  volts = AnalogToVolts(reading);

  // Convert the voltage to celsius
  celsius = VoltsToCelsius(volts);

  // Convert celsius to fahrenheit
  fahrenheit = CelsiusToFahrenheit(celsius);

  // Turn the fan on above 26 degrees celsius,
  // otherwise turn it off
  if (celsius > 26.0)
  {
    MotorOn();
  }
  else
  {
    MotorOff();
  }

  // Print the voltag and temperature in celsius and fahrenheit
  Serial.print("volts: ");
  Serial.print(volts);
  Serial.print("   C: ");
  Serial.print(celsius);
  Serial.print("   F: ");
  Serial.println(fahrenheit);
}

// Convert the raw reading to voltage
float AnalogToVolts(int reading)
{
  float volts;
  volts = reading/1023.0 * 5.0;  //Perform conversion
  return volts; //Return result
}

// Convert the voltage to celsius
float VoltsToCelsius(float volts)
{
  return (volts * 100 - 50);
}

// Convert celsius to fahrenheit
float CelsiusToFahrenheit(float celsius)
{
  return (celsius * 9 / 5 + 32);
}

// Turn the motor on
void MotorOn()
{
  digitalWrite(motorPin, HIGH);
}

// Turn the motor off
void MotorOff()
{
  digitalWrite(motorPin, LOW);
}
