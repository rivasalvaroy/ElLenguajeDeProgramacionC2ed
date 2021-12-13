#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100
// variables externas para getch y ungetch
char buf[BUFSIZE]; // buffer para ungetch
int bufp = 0;

// función que obtiene un (posiblemente ya regresado) carácter
int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}
// función que regresa carácter a la entrada
void ungetch(int c)
{
   if (bufp >= BUFSIZE)
      printf("ungetch: demasiados caracteres\n");
   else
      buf[bufp++] = c;
}