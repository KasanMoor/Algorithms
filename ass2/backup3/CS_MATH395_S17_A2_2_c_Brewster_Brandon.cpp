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

void selectionsort( int a[], int size ) 
{
   int j;
   int min;
   for( int i=0; i<size; i++ ) {
      min = i;
      for( j=i; j<size; j++ ) {
	 //cout << "comparing: " << a[j] << " " << a[min];
         if( a[j] < a[min] ) {
	    min = j;
	    //cout << "; Min is now " << a[min];
	 }
	 //cout << endl;
      }
      //cout << "swapping: " << a[min] << " " << a[i] << endl;
      int temp = a[min];
      a[min] = a[i];
      a[i] = temp;
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
   selectionsort( array, size );
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
