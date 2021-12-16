#include <stdio.h>
#include <ctype.h>
#include "atof.h"

// función que obtiene el siguiente flotante de la entrada y lo asigna a *pn
int getfloat(float *pn)
{
   int c, sign;
   float power;

   while (isspace(c = getch())) // ignora espacios en blanco
      ;
   if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
   {
      ungetch(c); // no es un número
      return 0;
   }
   sign = (c == '-') ? -1 : 1;
   if (c == '+' || c == '-')
      c = getch();
   for (*pn = 0.0; isdigit(c); c = getch())
      *pn = 10.0 * *pn + (c - '0'); // parte entera
   if (c == '.')
      c = getch();
   for (power = 1.0; isdigit(c); c = getch())
   {
      *pn = 10.0 * *pn + (c - '0'); // parte fraccionaria
      power *= 10.0;
   }
   *pn *= sign / power; // número final
   if (c != EOF)
      ungetch(c);
   return c;
}