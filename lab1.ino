#define SERIAL_INPUT true

// Pin used to control the LED and piezo buzzer
int const led = 7;
int const piezo = 8;

// Define a standard unit of time
int timeUnit = 50;

// Define a dot, dash, letter space, and word space
int const dot = timeUnit;       // One unit of time
int const dash = 3 * timeUnit;  // Three units of time
int const ls = 3 * timeUnit;    // Three units of time
int const ws = 7 * timeUnit;    // Seven units of time

// Define the frequency for the piezo to operate at
int const piezoFrequency = 600;

// Message to be displayed in morse code
String const message = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";




// The setup function runs once when you press reset or power the board
void setup()
{
  // Initialize the serial
  Serial.begin(9600);
  Serial.write("Initializing setup... ");
  
  // Initialize the LED and piezo pins as outputs.
  pinMode(led, OUTPUT);
  pinMode(piezo, OUTPUT);

  Serial.write("Setup finished.");
  Serial.write('\n');
  Serial.flush();
}




// The loop function runs over and over again forever
void loop()
{
  /*
  // Convert the message defined above into Morse code
  // then read it
  readMorseCodeMessage(latinMessageToMorseCode(message));
  */

#if SERIAL_INPUT
  // Wait for user input
  while(!Serial.available()) ;

  // Read user input from the serial
  String input = "";
  input = Serial.readString();

  // Remove the extraneous \n from the input
  input.remove(input.length() -1);

  // Convert the message defined above into Morse code
  // then read it
  readMorseCodeMessage(latinMessageToMorseCode(input));
#else
  // Convert the message defined above into Morse code
  // then read it
  readMorseCodeMessage(latinMessageToMorseCode(message));
#endif

  Serial.write('\n');
  delay(2 * ws);
  Serial.flush();
}




// Take a character as input and return the corresponding
// Morse code if it is a supported latin alphanumeric character,
// return nothing if it is not supported.
String latinCharacterToMorseCode(char c)
{
  if (c == 'a' || c == 'A') return ".-";
  else if (c == 'b' || c == 'B') return "-...";
  else if (c == 'c' || c == 'C') return "-.-.";
  else if (c == 'd' || c == 'D') return "-..";
  else if (c == 'e' || c == 'E') return ".";
  else if (c == 'f' || c == 'F') return "..-.";
  else if (c == 'g' || c == 'G') return "--.";
  else if (c == 'h' || c == 'H') return "....";
  else if (c == 'i' || c == 'I') return "..";
  else if (c == 'j' || c == 'J') return ".---";
  else if (c == 'k' || c == 'K') return "-.-";
  else if (c == 'l' || c == 'L') return ".-..";
  else if (c == 'm' || c == 'M') return "--";
  else if (c == 'n' || c == 'N') return "-.";
  else if (c == 'o' || c == 'O') return "---";
  else if (c == 'p' || c == 'P') return ".--.";
  else if (c == 'q' || c == 'Q') return "--.-";
  else if (c == 'r' || c == 'R') return ".-.";
  else if (c == 's' || c == 'S') return "...";
  else if (c == 't' || c == 'T') return "-";
  else if (c == 'u' || c == 'U') return "..-";
  else if (c == 'v' || c == 'V') return "...-";
  else if (c == 'w' || c == 'W') return ".--";
  else if (c == 'x' || c == 'X') return "-..-";
  else if (c == 'y' || c == 'Y') return "-.--";
  else if (c == 'z' || c == 'Z') return "--..";
  else if (c == '1') return ".----";
  else if (c == '2') return "..---";
  else if (c == '3') return "...--";
  else if (c == '4') return "....-";
  else if (c == '5') return ".....";
  else if (c == '6') return "-....";
  else if (c == '7') return "--...";
  else if (c == '8') return "---..";
  else if (c == '9') return "----.";
  else if (c == '0') return "-----";
  else if (c == ' ') return " "; // Space between words, interpreted as 7 units
  
  // Ignore invalid inputs
  else
  {
    Serial.write("WARNING (latinCharacterToMorseCode): unsupported input. Unsupported input was: ");
    Serial.write(c);
    Serial.write('\n');

    return "";
  }
}




// Convert a whole latin character message into a Morse code message
String latinMessageToMorseCode(String message)
{
  String morseCode = "";

  // Convert each latin character into Morse code
  for (unsigned int i = 0; i < message.length(); i++)
  {
    // Append the converted letter to the morse code message
    morseCode += latinCharacterToMorseCode(message[i]);

    // Append a letter space designator so long as the next character is not a space
    // and the current character is neither a space nor the end of the string
    if ((i + 1) != message.length() && message[i] != ' ' && message[i + 1] != ' ')
      morseCode += "l";
  }

  Serial.write("Morse code: ");
  Serial.print(morseCode);

  return morseCode;
}




// Given a single character of Morse code take the appropriate action,
// playing the code or delaying
void readMorseCode(char c)
{
  // Toggle the LED for the required units of time if
  // the character is a dot or dash, delay for the required
  // units of time if it is a letter or word space
  if (c == '.') playMorseCode(dot);
  else if (c == '-') playMorseCode(dash);
  else if (c == 'l') delay(ls);
  else if (c == ' ') delay(ws);
  else
  {
    Serial.write("ERROR (readMorseCode): invalid input. Invalid input was: ");
    Serial.write(c);
    Serial.write('\n');
  }
}




// Read a whole Morse code message and apply a delay between 
// letter when applicable
void readMorseCodeMessage(String morseCode)
{
  // Read the message one character at a time
  for (unsigned int i = 0; i < morseCode.length(); i++)
  {
    readMorseCode(morseCode[i]);

    // Only apply a unit of time between letters when the end of the message is not reached,
    // and neither the current character nor the next character are a letter or word space
    if ((i + 1) != morseCode.length() && morseCode[i] != 'l' && morseCode[i + 1] != 'l'
        && morseCode[i] != ' ' && morseCode[i + 1] != ' ')
      delay(timeUnit);
  }
}




// Function for turning the LED on for the specified time duration
void playMorseCode(int duration)
{
  digitalWrite(led, HIGH);
  tone(piezo, piezoFrequency, duration);
  delay(duration);
  digitalWrite(led, LOW);
}
