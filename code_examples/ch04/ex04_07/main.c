/* Convierte un número a una cadena de caracteres (lo inverso de
   atoi) solo que ahora usando recursividad funciones */
#include <stdio.h>

void printd(int n); // prototipo de función printd

// la función main empieza la ejecución del programa
int main()
{
   int n = -1985;

   printd(n);
   printf("\n");
   return 0;
}
// función que imprime n en decimal
void printd(int d)
{
   if (d < 0)
   {
      putchar('-');
      d = -d;
   }
   if (d / 10)
      printd(d / 10);
   putchar(d % 10 + '0');
}