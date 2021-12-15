/* Realiza conversión de entrada en formato libre desglozando
un flujo de caracteres en valores enteros, un entero por llamada */
#include <stdio.h>
#include "atoi.h"

#define MAXLINE 100

// la función main empieza la ejecución del programa
int main()
{
   int n, line[MAXLINE];

   for (n = 0; n < MAXLINE && getint(&line[n]) != EOF; n++)
      ;
   printf("Numeros enteros: ");
   for (int i = 0; i < n; i++)
      printf("%d ", line[i]);
   printf("\n");
   return 0;
}
