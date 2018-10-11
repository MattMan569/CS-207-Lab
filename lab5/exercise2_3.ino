/*    
 * Analog to Volts Function Demo
 * Created Oct 2011 by Alex Clarke.
 */

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
  
  reading = analogRead(A0);
  
  volts = AnalogToVolts(reading);
  celsius = VoltsToCelsius(volts);
  fahrenheit = CelsiusToFahrenheit(celsius);

  if (celsius > 26.0)
  {
    MotorOn();
  }
  else
  {
    MotorOff();
  }

  Serial.print("volts: ");
  Serial.print(volts);
  Serial.print("   C: ");
  Serial.print(celsius);
  Serial.print("   F: ");
  Serial.println(fahrenheit);
}

// Function Definition
float AnalogToVolts(int reading)
{
  float volts;
  volts = reading/1023.0 * 5.0;  //Perform conversion
  return volts; //Return result
}

float VoltsToCelsius(float volts)
{
  return (volts * 100 - 50);
}

float CelsiusToFahrenheit(float celsius)
{
  return (celsius * 9 / 5 + 32);
}

void MotorOn()
{
  digitalWrite(motorPin, HIGH);
}

void MotorOff()
{
  digitalWrite(motorPin, LOW);
}
