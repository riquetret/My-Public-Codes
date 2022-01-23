#include <stdio.h>
#include <string.h>
/*
FUNCTION: Good_Reading
Author: Made by Henrique Soares Costa, github.com/RIQUETRET
Inputs: your vector or variable (*ptr), size of your vector 
(size_vectors, if size equals one, then reads to a variable),
and your type ('i'=int,'f'=float,'d'=double,'s'=string, if none then reads a char)
Outputs: None
Return: none

Objective: Reads stdin according to your entry, if some error occurs, then 
Displays an error message and asks again for the keyboard input
*/
int good_reading (void *ptr, int size_vectors, char type) {
	int k = 1;
	switch (type)
	{
		case 'i': 																	// let's read an integer
			for (k = 0; k < size_vectors; k ++) {									// k to iterate in a possible vector
				printf ("\nPlease write info %d:", k + 1); 							// asks for information
				while (scanf ("%d", ((int *) ptr) + k)!= 1) {						// If the scanf find something wrong again piece (scanf returns EOF or 0)
				printf ("\nError try again: "); 									// Displays user error
				clean_buffer(); 													// Clean keypad garbage
				} clean_buffer (); 													// Clean keypad garbage
			} //END for (k = 0; k < size_vectors; k ++)
		break;
		case 'f': 																	// let's read a float
			for (k = 0; k < size_vectors; k ++) {									// k to iterate in a possible vector
				printf ("\nPlease write info %d:", k + 1); 							// asks for information
				while (scanf ("%f", ((float *) ptr) + k)!= 1) {						// If the scanf find something wrong again piece (scanf returns EOF or 0)
				printf ("\nError try again: "); 									// Displays user error
				clean_buffer(); 													// Clean keypad garbage
				} clean_buffer (); 													// Clean keypad garbage
			} //END for (k = 0; k < size_vectors; k ++)
		break;
		case 'd': 																	// let's read a double
			for (k = 0; k < size_vectors; k ++) {									// k to iterate in a possible vector
				printf ("\nPlease write info %d:", k + 1); 							// asks for information
				while (scanf ("%lf", ((double *) ptr) + k)!= 1) {					// If the scanf find something wrong again piece (scanf returns EOF or 0)
				printf ("\nError try again: "); 									// Displays user error
				clean_buffer(); 													// Clean keypad garbage
				} clean_buffer (); 													// Clean keypad garbage
			} //END for (k = 0; k < size_vectors; k ++)
		break;
		case 's': 																	// let's read a string
			printf ("\nPlease insert your text:"); 									// Ask the user the text
			while (fgets ((char *) ptr, size_vectors, stdin) == NULL) {				// if I could not read we null
			printf ("\nError try again: "); 										// Displays user error
			clean_buffer (); 														// Clean keypad garbage
			} clean_buffer (); 														// Clean keypad garbage
			*((((char *) ptr) + strcspn ((char *) ptr, "\n"))) = 0; 				// Removes possible \n of vector
		break;
		default: 																	// let's read a char
			for (k = 0; k < size_vectors; k ++) {									// k to iterate in a possible vector
				printf ("\nPlease write info %d:", k + 1); 							// asks for information
				while (scanf ("%c", ((char *) ptr) + k)!= 1) {						// If the scanf find something wrong again piece (scanf returns EOF or 0)
				printf ("\nError try again:"); 										// Displays user error
				clean_buffer(); 													// Clean keypad garbage
				} clean_buffer (); 													// Clean keypad garbage
			} //END for (k = 0; k < size_vectors; k ++)
		break;
	}
	return K;
}

/*
Function: clean_buffer
Author: Based on Other People, Modified by Henrique.
Inputs: stdin
Outputs: None
Return: none

Objective: To consume additional characters present in stdin.
If the function finds an EOF it
Reset the stdin for future readings
*/

void clean_buffer () {
    char ch = 0; 																	// declares char for reading
    do {
    ch = fgetc (stdin); 															// reads character by character to clean stdin
    } while (ch!= '\n' && ch!= EOF); 												// If a line break was found or an EOF stops
    if(ch == EOF) clearerr (stdin); 												// If an EOF was found, reset Stdin
}