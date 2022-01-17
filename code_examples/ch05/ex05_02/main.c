/* Cuando un nombre de arreglo se pasa a una función, lo que se pasa es la locali­dad del 
   elemento inicial. Dentro de la función que se llama, este argumento es una variable local, 
   y por lo tanto, un parámetro de nombre de arreglo es un apuntador, esto es, una variable 
   que contiene una dirección. Se puede utilizar este hecho para escribir otra versión de 
   strlen, que calcula la longitud de una cadena.

   Envía una cadena de caracteres y regresa la longitud de la misma, prototype_strlen */
#include <stdio.h>

int pr_strlen(char s[]); // prototipo de la función pr_strlen

// la función main empieza la ejecución del programa
int main()
{
   char s[] = "Hola Mundo!";
   printf("%d\n", pr_strlen(s));
   return 0;
}
// función que regresa la longitud de su argumento s de tipo cadena de caracteres
int pr_strlen(char *s)
{
   int n;

   for (n = 0; *s != '\0'; s++)
      n++;
   return n;
}