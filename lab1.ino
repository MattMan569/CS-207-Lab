int led = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize the led pin as an output.
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(led, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}



char const * const message = "hello";
	for (int i = 0; message[i] != '\0'; i++)
	{
		std::cout << latinToMorse(message[i]) << std::endl;
	}



// Take a character as input and return the corresponding
// Morse code if it is a supported latin alphanumeric character,
// return nothing if it is not supported.
char const * const latinToMorse(char c)
{
	if (c == 'a' || c == 'A') return ".-";
	else if (c =='b' || c =='B') return "-...";
	else if (c == 'c' || c == 'C') return "-.-.";
	else if (c == 'd' || c == 'D') return "-..";
	else if (c == 'e' || c == 'E') return ".";
	else if (c == 'f' || c == 'F') return "..-.";
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
	
	// Ignore invalid inputs
	else return "";
}
