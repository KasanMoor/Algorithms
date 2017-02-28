#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
   int n;
   srand( time(NULL) );

   cout << "Enigma Algorithm, enter value for n: ";
   cin >> n;
   int A[n][n];
   for( int i=0; i<n; i++ ) {
      for( int j=0; j<n; j++ ) {
         A[i][j] = rand() % 100;
         cout << A[i][j] << ' ';
      }
      cout << endl;
   }
   
   for( int i=0; i<n-1; i++ ) {
      for( int j=i+1; j<n; j++ ) {
         if( A[i][j] != A[j][i] ) {
            cout << "Not symmetric" << endl;
            return 0;
         }
      }
   }
   cout << "Symmetric" << endl;
   return 1;
}
