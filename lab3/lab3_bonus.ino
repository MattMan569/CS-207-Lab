/*
 * 
 */

// Debug only output
#define DEBUG false

// Global variables
namespace global
{
  // Pin definitions
  byte const redPin = 6;
  byte const greenPin = 5;
  byte const bluePin = 3;

  // Global RGB values
  // Set one of {red,green,blue} to 255, other two to 0
  unsigned int red = 255;
  unsigned int green = 0;
  unsigned int blue = 0;
  unsigned int const rgbMax = 255;
  unsigned int const rgbMin = 0;

  // Current phase of the RGB LED
  // 0: red decreasing, green increasing
  // 1: green decreasing, blue increasing
  // 2: blue decreasing, red increasing
  unsigned int rgbMode = 0;

  // Time to delay each loop
  unsigned int const delayTime = 1;
}

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing setup... ");

  // Pin setup
  pinMode(global::redPin, OUTPUT);
  pinMode(global::greenPin, OUTPUT);
  pinMode(global::bluePin, OUTPUT);

  Serial.print("Setup finished.\n\n");
  Serial.flush();
}

void loop()
{
  rgbWrite(global::red, global::green, global::blue);
  rgbSet();
  delay(global::delayTime);

#if DEBUG
  Serial.print("rgbMode: ");
  Serial.print(global::rgbMode);
  Serial.print("   red: ");
  Serial.print(global::red);
  Serial.print("   green: ");
  Serial.print(global::green);
  Serial.print("   blue: ");
  Serial.println(global::blue);
#endif
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
    {
      if (global::green == global::rgbMax)
      {
        ++global::rgbMode %= 3;
      }
      else
      {
        global::red--;
        global::green++;
      }

      break;
    }
    // Green to blue
    case 1:
    {
      if (global::blue == global::rgbMax)
      {
        ++global::rgbMode %= 3;
      }
      else
      {
        global::green--;
        global::blue++;
      }
      
      break;
    }
    // Blue to red
    case 2:
    {
      if (global::red == global::rgbMax)
      {
        ++global::rgbMode %= 3;
      }
      else
      {
        global::blue--;
        global::red++;
      }

      break;
    }
    // Error
    default:
    {
      Serial.println("Incorrect rgbSet switch value.");

      break;
    }
  }
}

// Write the passed values to the RGB LED pins
void rgbWrite(unsigned int red, unsigned int green, unsigned int blue)
{
  analogWrite(global::redPin, red);
  analogWrite(global::greenPin, green);
  analogWrite(global::bluePin, blue);
}
