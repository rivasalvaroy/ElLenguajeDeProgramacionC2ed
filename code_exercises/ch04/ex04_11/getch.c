#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100
// variables estaticas externas para getch
static char buf[BUFSIZE];
static int bufp = 0;

// función que obtiene un (posiblemente ya regresado) caracter
int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}
