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

int partition( int a[], int low, int hi )
{
      /*cout << "partitioning; low: " << low 
           << " high: " << hi 
	   << " pivot: " << a[hi]
	   << endl;*/
      int pivot = a[hi];
      int i = low-1;
      for( int j=low; j<hi; j++ ) {
         //cout << "Comparing: "
	   //   << a[j] << " " << pivot << endl;
         if( a[j] <= pivot ) {
	    //cout << "Swapping: " 
	      //   << a[i+1] << " " << a[j] << endl;
            i++;
	    int temp = a[i];
	    a[i] = a[j];
   	    a[j] = temp;
            //printArray( a );
         }
      }
      int temp = a[i+1];
      a[i+1] = a[hi];
      a[hi] = temp;
      return i+1;
}
void quicksort( int a[], int low, int hi ) 
{
   if( low < hi ) {
      int p = partition( a, low, hi );
      //cout << "quicksort; low: " << low << " hi: " << p-1 << endl;
      quicksort( a, low, p-1 );
      //cout << "quicksort; low: " << p+1 << " hi: " << hi << endl;
      quicksort( a, p+1, hi );
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
   quicksort( array, 0, size-1 );
   int stop_s=clock();
   //printArray( array );
   cout << "Shellsort time on size " << size 
        << ": " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

int main() 
{
   doOnSize( 100 );
   doOnSize( 1000 );
   doOnSize( 10000 );
}
