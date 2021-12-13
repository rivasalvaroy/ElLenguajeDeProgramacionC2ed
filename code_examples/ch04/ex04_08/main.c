// Quicksort, un algoritmo de ordenamien­to desarrollado en 1962 por C. A. R. Hoare.
#include <stdio.h>

void qsort(int v[], int var1, int var2); // prototipo de la función qsort

// la función main empieza la ejecución del programa
int main()
{
   int arry[] = {11, 1, 10, 4, 6, 5, 7, 9, 8, 2, 3};
   int n = sizeof(arry) / sizeof(*arry); // indirección
   qsort(arry, 0, n - 1);

   for (int i = 0; i < n; i++)
      printf("%d ", arry[i]);
   printf("\n");
   return 0;
}
// función que ordena v[left]...v[right] en orden ascendente
void qsort(int v[], int left, int right)
{
   int i, last;
   void swap(int v[], int i, int j); // prototipo de la función swap

   if (left >= right) // no hace nada si el arreglo contine menos de dos elementos
      return;
   swap(v, left, (left + right) / 2);  // mueve el elemento de partición
   last = left;                        // a v[0];
   for (i = left + 1; i <= right; i++) // partición
      if (v[i] < v[left])
         swap(v, last, i);
   swap(v, left, last); // regresa el elemento de partición
   qsort(v, left, last - 1);
   qsort(v, last + 1, right);
}
// función que intercambia v[i] y v [j]
void swap(int v[], int i, int j)
{
   int temp;

   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}
/* Dado un arreglo, un elemento se selecciona y los otros se particionan en dos 
   subconjuntos —aquellos menores que el elemento de la partición y aquellos mayores 
   o iguales a él. El mismo proceso se aplica después recursivamente a los dos 
   subconjuntos. Cuando un subconjunto tiene menos de dos elementos no necesita ya de
   ningún ordenamiento; esto detie­ne la recursividad. */