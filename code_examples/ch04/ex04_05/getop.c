#include <stdio.h>
#include <ctype.h>  // para función isdigit & islower
#include <string.h> // para función strlen
#include "calc.h"

// función que obtiene el siguiente operador u operando numérico
int getop(char s[])
{
   int i, c;

   while ((s[0] = c = getch()) == ' ' || c == '\t')
      ;
   s[1] = '\0';
   i = 0;
   if (islower(c))
   {
      while (islower(s[++i] = c = getch()))
         ;
      ;
      s[i] = '\0';
      if (c != EOF)
         ungetch(c); // fue un char demasiado lejos
      if (strlen(s) > 1)
         return NAME;
      else
         return s[0]; // puede ser un comando
   }

   if (!isdigit(c) && c != '.' && c != '-')
      return c; // no es número
   if (c == '-')
   {
      if (isdigit(c = getch()) || c == '.')
         s[++i] = c; // número negativo
      else
      {
         if (c != EOF)
            ungetch(c);
         return '-'; // signo menos
      }
   }
   if (isdigit(c)) // reúne la parte entera
      while (isdigit(s[++i] = c = getch()))
         ;
   if (c == '.') // reúne la parte fraccionaria
      while (isdigit(s[++i] = c = getch()))
         ;
   s[i] = '\0';
   if (c != EOF)
      ungetch(c);
   return NUMBER;
}