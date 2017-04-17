// Brandon Brewster
// CS395/MATH395-Spring2017-Assignment2-Question2

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int n = 10;

void printArray( int array[] )
{
   for( int i=0; i<n; i++ ) {
      cout << array[i] << " ";
   }
   cout << endl;
}

void shellsort( int a[], int size )
{
   const int numGaps = 3;
   int gaps[numGaps] = {5, 3, 1};
   for( int g=0; g<numGaps; g++ ) {
      int gap = gaps[g];
      for( int i=gap; i<size; i++ ) {
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

int* generateArray( int size )
{
   srand( time(NULL) );
   int* array = new int[size];
   for( int i=0; i<size; i++ ) {
      array[i] = rand() % size;
   }
   return array;
}

void doOnSize( int size )
{
   int* array = generateArray(size);
   //printArray( array );
   int start_s = clock();
   shellsort( array, size );
   int stop_s=clock();
   cout << "Shellsort time on size " << size 
        << ": " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

int main() 
{
   doOnSize( 100 );
   doOnSize( 1000 );
   doOnSize( 10000 );
}
