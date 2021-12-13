/* Escriba una versión recursiva de la función reverse(s),
   que invier­te la cadena s en su lugar */
#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void itoa(int n, char s[]);
void reverse(char s2[]);

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
// función que convierte n a caracteres en s
void itoa(int n, char s[])
{
   int i, sign;

   if ((sign = n) < 0)
      n = -n; // vuelve a ser positivo
   i = 0;
   do // genera dígitos en orden inverso
   {
      s[i++] = n % 10 + '0'; // toma el siguiente dígito
   } while ((n /= 10) > 0);  // borralo
   if (sign < 0)
      s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}
// función que invierte la cadena s en el mismo lugar
void reverse(char s[])
{
   void reverser(char s[], int i, int len);

   reverser(s, 0, strlen(s));
}
// función que invierte la cadena s en el mismo lugar, recursiva
void reverser(char s[], int i, int len)
{
   int c, j;

   j = len - (i + 1);
   if (i < j)
   {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
      reverser(s, ++i, len);
   }
}