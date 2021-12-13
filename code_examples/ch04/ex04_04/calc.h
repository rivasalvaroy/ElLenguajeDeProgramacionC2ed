#define NUMBER '0' // señal de que un número se encontro
#define NAME 'n'   // señal de que un nombre se encontro

int getop(char[]);    // obtiene el siguiente operador u operando numérico
void push(double);    // introducir en la pila
double pop(void);     // extraer de la pila
void clear(void);     // limpiar pila
void mathfnc(char[]); // revisa el string s para funciones matemáticas
int getch(void);      // obtiene un (posiblemente ya regresado) carácter
void ungetch(int);    // regresa carácter a la entrada
