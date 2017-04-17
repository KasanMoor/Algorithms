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

int main() 
{
   int array[n] = {20, 6, 8, 4, 26, 38, 35, 55, 1, 10 };
   printArray( array );
   quicksort( array, 0, n-1 );
   printArray( array );
}
