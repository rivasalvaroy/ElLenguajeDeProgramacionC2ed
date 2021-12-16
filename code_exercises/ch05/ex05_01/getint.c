#include <stdio.h>
#include <ctype.h>
#include "atoi.h"

// función que obtiene el siguiente entero de la entrada y lo asigna a *pn
int getint(int *pn)
{
   int c, d, sign;

   while (isspace(c = getch())) // ignora espacios en blanco
      ;
   if (!isdigit(c) && c != EOF && c != '+' && c != '-')
   {
      ungetch(c); // no es un número
      return 0;
   }
   sign = (c == '-') ? -1 : 1;
   if (c == '+' || c == '-')
   {
      d = c; // recuerda el signo
      if (!isdigit(c = getch()))
      {
         if (c != EOF)
            ungetch(c);
         ungetch(d);
         return d;
      }
   }
   for (*pn = 0; isdigit(c); c = getch())
      *pn = 10 * *pn + (c - '0');
   *pn *= sign;
   if (c != EOF)
      ungetch(c);
   return c;
}