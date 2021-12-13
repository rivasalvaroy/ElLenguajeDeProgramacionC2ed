// Defina una macro swap(t,x,y)
#include <stdio.h>
// definición de la macro swap
#define swap(t, x, y) \
   {                  \
      t _z;           \
      _z = y;         \
      y = x;          \
      x = _z;         \
   }

// la función main empieza la ejecución del programa
int main()
{
   static int x = 13;
   static int y = 14;

   printf("before swap\n");
   printf("x : %d\n", x);
   printf("y : %d\n", y);
   swap(int, x, y);
   printf("after swap\n");
   printf("x : %d\n", x);
   printf("y : %d\n", y);
   return 0;
}