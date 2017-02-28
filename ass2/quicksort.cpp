#include <iostream>

using namespace std;

const int n = 10;

void printArray( int array[] )
{
   for( int i=0; i<n; i++ ) {
      cout << array[i] << " ";
   }
   cout << endl;
}

void quicksort( int a[], low, hi ) 
{
   p = partition( a, low, hi );
   quicksort( a, low, p-1 );
   quicksort( a, p+1, hi );
}

int partition( int a[], low, hi )
{
   int pivot = a[hi];
   i = low-1;
   for( int j=low; j<hi; j++ ) {
      if( a[j] < pivot ) {
         i++;

      }
   }
}

int main() 
{
   int array[n] = {20, 6, 8, 4, 26, 38, 35, 55, 1, 10 };
   printArray( array );
   quicksort( array );
   printArray( array );
}
