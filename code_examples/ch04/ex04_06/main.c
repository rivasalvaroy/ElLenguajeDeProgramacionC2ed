// Calculadora polaca inversa - uso de variables static y make file
#include <stdio.h>
#include <stdlib.h> // para función atof
#include <math.h>   // para función fmod
#include "calc.h"

#define MAXOP 100 // máximo tamaño de operando u operador

// la función main empieza la ejecución del programa
int main()
{
   int i, type, var = 0;
   double op1, op2, v;
   char s[MAXOP];
   double variable[26];

   for (i = 0; i < 26; i++)
      variable[i] = 0.0;
   while ((type = getop(s)) != EOF)
   {
      switch (type)
      {
      case NUMBER:
         push(atof(s));
         break;
      case NAME:
         mathfnc(s);
         break;
      case '+':
         push(pop() + pop());
         break;
      case '*':
         push(pop() * pop());
         break;
      case '-':
         op2 = pop();
         push(pop() - op2);
         break;
      case '/':
         op2 = pop();
         if (op2 != 0.0)
            push(pop() / op2);
         else
            printf("error: divisor cero\n");
         break;
      case '%':
         op2 = pop();
         if (op2 != 0.0)
            push(fmod(pop(), op2));
         else
            printf("error: divisor cero\n");
         break;
      case '?': // imprime el elemento al tope de la pila
         op2 = pop();
         printf("\t%.8g\n", op2);
         push(op2);
         break;
      case 'c': // limpia la pila
         clear();
         break;
      case 'd': // duplica el elemento al tope de la pila
         op2 = pop();
         push(op2);
         push(op2);
         break;
      case 's': // intercambia los dos elementos al tope de la pila
         op1 = pop();
         op2 = pop();
         push(op1);
         push(op2);
         break;
      case '=':
         pop();
         if (var >= 'A' && var <= 'Z')
         {
            variable[var - 'A'] = pop();
            push(variable[var - 'A']);
         }
         else
            printf("error: nombre de variable no encontrado");
         break;
      case '\n':
         v = pop();
         printf("\t%.8g\n", v);
         break;
      default:
         if (type >= 'A' && type <= 'Z')
            push(variable[type - 'A']);
         else if (type == 'v')
            push(v);
         else
            printf("error: comando desconocido %s\n", s);
         break;
      }
      var = type;
   }
   return 0;
}