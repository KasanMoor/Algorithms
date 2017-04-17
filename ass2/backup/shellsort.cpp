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

void shellsort( int a[] )
{
   const int numGaps = 3;
   int gaps[numGaps] = {5, 3, 1};
   for( int g=0; g<numGaps; g++ ) {
      int gap = gaps[g];
      for( int i=gap; i<n; i++ ) {
         for( int j=i; j>=gap; j-=gap ) {
	    if( a[j] < a[j-gap] ) {
	       int temp = a[j];
	       a[j] = a[j-gap];
	       a[j-gap] = temp;
	    }
	 }
      }
   }
}

void insertionsort( int array[] )
{
   for( int i=1; i<n; i++ ) {
      for( int j=i; j>0; j-- ) {
         if( array[j] < array [j-1] ) {
	    int temp = array[j];
	    array[j] = array[j-1];
	    array[j-1] = temp;
	 }
      }
   }
}

int main() 
{
   int array[n] = {20, 6, 8, 4, 26, 38, 35, 55, 1, 10 };
   printArray( array );
   shellsort( array );
   //insertionsort( array );
   printArray( array );
}
