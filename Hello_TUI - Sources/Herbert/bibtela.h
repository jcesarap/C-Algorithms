#ifndef _BIBTELA
#define _BIBTELA

/*
* Includes
*/
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>
#include <stddef.h>


typedef struct Screen {
	int x;
	int y
} Screen;

/*
* Function prototypes
*/
void init_screen(int x, int y);
void end_screen(void);
void clear_screen(void);
void xygoto(int x, int y);
int xyprint(int x, int y, const char* str);
void xyscanf(int x, int y, char* str);

void xyhline(int x, int y1, int y2, const char *ch);
void xyvline(int y, int x1, int x2, const char *ch);
void xywindow(int x1, int y1, int x2, int y2, int border);

#endif
