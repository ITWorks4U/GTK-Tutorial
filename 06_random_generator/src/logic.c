/**
 * 	Contains the logic.
*/
#include "../header/random_generator.h"
#include <stdlib.h>
#include <time.h>

const guint32 createRandomNumber(void) {
	guint32 number = g_random_int();																					/*	returns a number n between {0, 1, 2, ..., 2.147.483.648}			*/
	number = number % 7;																								/*	do a modulo operation, so we have a number n between {0, 1, ..., 6}	*/
	
	return number;
}

const enum EColors selectRandomColorType(const guint32 randomNumber) {
	switch(randomNumber) {
		case 1:
			return YELLOW;
		case 2:
			return GREEN;
		case 3:
			return BLUE;
		case 4:
			return BROWN;
		case 5:
			return PURPLE;
		case 6:
			return PINK;
	}
	
	return RED;																											/*	color RED by default	*/
}

const gchar *createRandomWord(void) {
	gchar *randomWord = (gchar *) calloc(11, sizeof(gchar));	
	guint32 i, number;
	guint32 start = (guint32)('0');																						/*	starts with number 48 (ASCII: zero as number)	*/
	guint32 range = (guint32)('}') - 32;																				/*	ends with number 125 (ASCII: character })		*/
	glong seconds;

	time(&seconds);
	srand(seconds);

	for (i = 0; i < 11; i++) {
		number = ((rand() % range) + start);
		
		/*	required to filter invalid UTF-8 characters, otherwise a warning about gotten
		 * 	invalid characters will be printed to the console
		*/
		if ((number >= 48 && number <= 57) || (number >= 64 && number <= 90) || (number >= 97 && number <= 125)) {		/*	accept characters between {{0,1,...9}, {@, A, B, ..., Z}, {a, b, ..., }}} only	*/
			randomWord[i] = (gchar) number;
		} else {
			randomWord[i] = (gchar)('.');																				/*	any other number of range [48,125] left, which is a special character			*/
		}
	}

	randomWord[11] = '\0';
	return randomWord;	
}
