// Concatena la cadena t al final de la cadena, prototype_strcat
#include <stdio.h>

void pr_strcat(char s[], char t[]); // prototipo de la función pr_strcat

// la función main empieza la ejecución del programa
int main()
{
   char s[20] = "Hello";
   char t[] = " World";

   pr_strcat(s, t);
   printf("%s\n", s);
   return 0;
}
// función que concatena t al final de s, s debe ser suficientemente grande
void pr_strcat(char s[], char t[])
{
   int i, j;

   i = j = 0;
   while (s[i] != '\0') // encuentra el fin de s
      i++;
   while ((s[i++] = t[j++]) != '\0') // copia t
      ;
}