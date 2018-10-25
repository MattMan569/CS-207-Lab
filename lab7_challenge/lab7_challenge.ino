//LED Pin Variables
const byte ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; //An array to hold the pin each LED is connected to
const byte numLeds = (sizeof(ledPins) / sizeof(ledPins[0]));




void setup()
{
  for (byte i = 0; i < numLeds; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
}




void loop()
{
  const byte pattern1[] = {HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW};
  const byte pattern2[] = {LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH};
  const byte pattern3[] = {HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW};
  const byte pattern4[] = {LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH};
  const byte pattern5[] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
  const byte pattern6[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
  const byte pattern7[] = {HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW};
  const byte pattern8[] = {LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH};


  const byte *patterns[] = {pattern1, pattern2, pattern7, pattern8, pattern3, pattern4, pattern6, pattern5};
  const byte numPatternsUsed = (sizeof(patterns) / sizeof(patterns[0]));

  const int delayTime = 200;


  for (byte i = 0; i < numPatternsUsed; ++i)
  {
    makePattern(patterns[i], delayTime);
  }
}




/*
 * Function: makePattern
 * 
 * Input:
 *    pattern - a pointer to the pattern to be used
 *    delayTime - the amount of time to delay after each pattern is displayed
 * 
 * Output: void
 */
void makePattern(const byte pattern[], const unsigned int &delayTime)
{
  for (byte i = 0; i < numLeds; i++)
  {
    digitalWrite(ledPins[i], pattern[i]);
  }

  delay(delayTime);
}
