/* Calculadora polaca inversa
   while (siguiente operador u operando no es fin de archivó)
   if (número)
      introducirlo
   else if (operador)
      extraer operandos
      hacer operaciones
      introducir el resultado
   else if (nueva línea)
      extrae e imprime el tope de la pila
   else
      error
*/
#include <stdio.h>
#include <stdlib.h> // para función atof

#define MAXOP 100  // máximo tamaño de operando u operador
#define NUMBER '0' // señal de que un numero se encontro

int getop(char[]); // prototipo de la función getop - obtiene el siguiente operador u operando numérico
void push(double); // prototipo de la función push - introducir en la pila
double pop(void);  // prototipo de la función pop - extraer de la pila

// la función main empieza la ejecución del programa
int main()
{
   int type;
   double op2;
   char s[MAXOP];

   while ((type = getop(s)) != EOF)
   {
      switch (type)
      {
      case NUMBER:
         push(atof(s));
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
      case '\n':
         printf("\t%.8g\n", pop());
         break;
      default:
         printf("error: comando desconocido %s\n", s);
         break;
      }
   }
   return 0;
}

#define MAXVAL 100 // máxima profundidad de la pila val
// variables externas para push y pop
int sp = 0;         // siguiente posición libre en la pila
double val[MAXVAL]; // valores de la pila

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

#include <ctype.h> // para isdigit

int getch(void);   // prototipo de la función getch, obtiene un (posiblemente ya regresado) carácter
void ungetch(int); // prototipo de la función ungetch, regresa carácter a la entrada

// función que obtiene el siguiente operador u operando numérico
int getop(char s[])
{
   int i, c;

   while ((s[0] = c = getch()) == ' ' || c == '\t')
      ;
   s[1] = '\0';
   if (!isdigit(c) && c != '.')
      return c; // no es numero
   i = 0;
   if (isdigit(c)) // reune la parte entera
      while (isdigit(s[++i] = c = getch()))
         ;
   if (c == '.') // reune la parte fraccionaria
      while (isdigit(s[++i] = c = getch()))
         ;
   s[i] = '\0';
   if (c != EOF)
      ungetch(c);
   return NUMBER;
}

#define BUFSIZE 100
// variables externas para getch y ungetch
char buf[BUFSIZE]; // buffer para ungetch
int bufp = 0;

// función que obtiene un (posiblemente ya regresado) carácter
int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}
// función que regresa carácter a la entrada
void ungetch(int c)
{
   if (bufp >= BUFSIZE)
      printf("ungetch: demasiados caracteres\n");
   else
      buf[bufp++] = c;
}
