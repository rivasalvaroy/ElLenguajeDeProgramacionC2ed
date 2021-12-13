// quicksort, un algoritmo de ordenamien­to desarrollado en 1962 por C. A. R. Hoare
// Defina una macro swap(t,x,y)
#include <stdio.h>
// definicion de la macro swap
#define swap(t, x, y) \
   {                  \
      int temp;       \
      temp = t[x];    \
      t[x] = t[y];    \
      t[y] = temp;    \
   }

void qsort(int v[], int var1, int var2); // prototipo de la función qsort

// la función main empieza la ejecución del programa
int main()
{
   int arry[] = {11, 1, 10, 4, 6, 5, 7, 9, 8, 2, 3};
   int n = sizeof(arry) / sizeof(*arry); // indirección
   qsort(arry, 0, n - 1);

   for (int i = 0; i < 11; i++)
      printf("%d ", arry[i]);
   printf("\n");
   return 0;
}
// función que ordena v[left]...v[right] en orden ascendente
void qsort(int v[], int left, int right)
{
   int i, last;

   if (left >= right) // no hace nada si el arreglo contine menos de dos elementos
      return;
   swap(v, left, (left + right) / 2);  // mueve el elemento de partición
   last = left;                        // a v[0];
   for (i = left + 1; i <= right; i++) // partición
      if (v[i] < v[left])
         swap(v, last, i);
   swap(v, left, last); // regrese el elemento de partición
   qsort(v, left, last - 1);
   qsort(v, last + 1, right);
}
