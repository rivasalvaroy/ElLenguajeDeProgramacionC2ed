/* Escriba getfloat, la analogía de punto flotante de getint
¿Qué tipo regresa getfloat como su valor de función? int */
#include <stdio.h>
#include "atof.h"

#define MAXLINE 100

// la función main empieza la ejecución del programa
int main()
{
   int n;
   float line[MAXLINE];

   for (n = 0; n < MAXLINE && getfloat(&line[n]) != EOF; n++)
      ;
   printf("Numeros enteros: ");
   for (int i = 0; i < n; i++)
      printf("%.2f ", line[i]);
   printf("\n");
   return 0;
}