/* Adapte las ideas de|printd| al escribir la versión recursiva 
   del programa itoa; esto es, convierta un entero en una cadena llamando a una 
   rutina recursiva */
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

void itoa(int n, char s[]); // prototipo de la función itoa

// la función main empieza la ejecución del programa
int main()
{
   char cad[MAXLINE];
   int n;

   n = -1985;
   itoa(n, cad);
   printf("%s\n", cad);
   return 0;
}
// función que convierte entero n a cadena de caracteres en s
void itoa(int n, char s[])
{
   static int i;

   if (n / 10)
      itoa(n / 10, s);
   else
   {
      i = 0;
      if (n < 0)
         s[i++] = '-';
   }
   s[i++] = abs(n) % 10 + '0';
   s[i] = '\0';
}
