#include <stdio.h>
#include <ctype.h>  // para función isdigit & islower
#include <string.h> // para función strlen
#include "calc.h"

// función que obtiene el siguiente operador u operando numérico
int getop(char s[])
{
   int i, c;
   static int lastc = 0; // variable estatica interna

   if (lastc == 0)
      c = getch();
   else
   {
      c = lastc;
      lastc = 0;
   }

   while ((s[0] = c) == ' ' || c == '\t')
      c = getch();
   s[1] = '\0';
   i = 0;
   if (islower(c))
   {
      while (islower(s[++i] = c = getch()))
         ;
      s[i] = '\0';
      if (c != EOF)
         lastc = c;
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
            lastc = c;
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
      lastc = c;
   return NUMBER;
}