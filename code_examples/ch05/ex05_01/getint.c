#include <stdio.h>
#include <ctype.h>
#include "atoi.h"

// función que obtiene el siguiente entero de la entrada y lo asigna a *pn
int getint(int *pn)
{
   int c, sign;

   while (isspace(c = getch())) // ignora espacios en blanco
      ;
   if (!isdigit(c) && c != EOF && c != '+' && c != '-')
   {
      ungetch(c); // no es un número
      return 0;
   }
   sign = (c == '-' ? -1 : 1);
   if (c == '+' || c == '-')
      c = getch();
   for (*pn = 0; isdigit(c); c = getch())
      *pn = 10 * *pn + (c - '0');
   *pn *= sign;
   if (c != EOF)
      ungetch(c);
   return c;
}