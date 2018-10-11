/*    
 * Analog to Volts Function Demo
 * Created Oct 2011 by Alex Clarke.
 */

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int reading;
  float volts, normal;
  
  reading = analogRead(A0);
  
  volts = AnalogToVolts(reading);  //Function call
  normal = VoltsToNormal(volts);

  Serial.print(volts);
  Serial.print("\t\t");
  Serial.println(normal);
}

// Function Definition
float AnalogToVolts(int reading)
{
  float volts;
  volts = reading/1023.0 * 5.0;  //Perform conversion
  return volts; //Return result
}

float VoltsToNormal(float volts)
{
  float normal;
  normal = volts / 5.0;
  return normal;
}
