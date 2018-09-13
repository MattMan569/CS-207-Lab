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




    #include <iostream>
     
#define MORSE_CODE \
X(A, ".-") \
X(B, "-...") \
X(C, "-.-.") \
X(D, "-..") \
X(E, ".") \
X(F, "..-.") \
X(G, "--.") \
X(H, "....") \
X(I, "..") \
X(J, ".---") \
X(K, "-.-") \
X(L, ".-..") \
X(M, "--") \
X(N, "-.") \
X(O, "---") \
X(P, ".--.") \
X(Q, "--.-") \
X(R, ".-.") \
X(S, "...") \
X(T, "-") \
X(U, "..-") \
X(V, "...-") \
X(W, ".--") \
X(X, "-..-") \
X(Y, "-.--") \
X(Z, "--..") \
X(SL, "   ") \
X(SW, "       ")

#define X(latin, morse) latin,
enum LatinCharacter// : size_t
{
    MORSE_CODE
};
#undef X

#define X(latin, morse) morse,
char const * morseCode[] =
{
    MORSE_CODE
};
#undef X
     
int main()
{
	std::cout << "Enum value: " << LatinCharacter::F << std::endl;
	std::cout << "Morse code: " << morseCode[LatinCharacter::F] << std::endl;
	
	LatinCharacter lc = C;
	std::cout << "Enum value: " << lc << std::endl;
	std::cout << "Morse code: " << morseCode[lc] << std::endl;
	
	return 0;
}
