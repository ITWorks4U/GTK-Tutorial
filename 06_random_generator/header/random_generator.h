#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <gtk/gtk.h>

/*	---	contains the widgets	---	*/
struct SRandomStuff {
	GtkButton *button_random_number;
	GtkEntry *output_random_number;
	
	GtkButton *button_label_color;
	GtkLabel *label_color;
};

/*	---	contains colors to use	---	*/
enum EColors {
	RED = 0,
	YELLOW,
	GREEN,
	BLUE,
	BROWN,
	PURPLE,
	PINK
};

/*	---	function prototypes		---	*/
const guint32 createRandomNumber(void);																					/*	guint32 := typedef unsigned int guint32	(GTK wiki)	*/
const enum EColors selectRandomColorType(const guint32 randomNumber);
const char *createRandomWord(void);

/*	---	required definitions	---	*/
#define	COLOR_RED		"red"
#define	COLOR_YELLOW	"yellow"
#define	COLOR_GREEN		"green"
#define	COLOR_BLUE		"blue"
#define	COLOR_BROWN		"brown"
#define	COLOR_PURPLE	"purple"
#define	COLOR_PINK		"pink"

#endif
