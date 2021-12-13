#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 // máxima profundidad de la pila val
// variables static externas para push y pop
static int sp = 0;         // siguiente posición libre en la pila
static double val[MAXVAL]; // valores de la pila

// función que introduce f a la pila
void push(double f)
{
   if (sp < MAXVAL)
      val[sp++] = f;
   else
      printf("error: pila llena, no puedo efectuar push %g\n", f);
}
// función que extrae y regresa el valor superior de la pila
double pop(void)
{
   if (sp > 0)
      return val[--sp];
   else
   {
      printf("error: pila vacia\n");
      return 0.0;
   }
}
// función que limpia la pila
void clear(void)
{
   sp = 0;
}