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

void selectionsort( int a[] ) 
{
   int j;
   int min;
   for( int i=0; i<n; i++ ) {
      min = i;
      for( j=i; j<n; j++ ) {
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

int main() 
{
   int array[n] = {20, 6, 8, 4, 26, 38, 35, 55, 1, 10 };
   printArray( array );
   selectionsort( array );
   printArray( array );
}
