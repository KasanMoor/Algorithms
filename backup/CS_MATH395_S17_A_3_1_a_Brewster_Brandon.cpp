/* Brandon Brewster
 * CS395/MATH395-Spring2017-Assignment3-Question1
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <stdio.h>

using namespace std;

const int N = 10;
const int M = 10;

vector<int> randInit(vector<int> A, int n) {
   for( int i=0; i<n; i++) {
      A.push_back(rand() % 10);
   }
   return A;
}

void printArray(vector<int> A) {
   for( int i=0; i<A.size(); i++) {
      cout << A[i] << " ";
   }
   cout << endl;
}

int memberOf(vector<int> a, int key) {
   for(int i=0; i<a.size(); i++) {
      if( a[i] == key )
         return 1;
   }
   return 0;
}

vector<int> intersection( vector<int> a, vector<int> b ) {
   vector<int> intersection;
   for(int i=0; i<a.size(); i++) {
      for(int j=0; j<b.size(); j++) {
         if(a[i] == b[j] && !memberOf(intersection, a[i])) {
	    intersection.push_back(a[i]);
	 }
      }
   }
   return intersection;
}

int main()
{
   srand(time(NULL));
   vector<int> A;
   vector<int> B;
   A = randInit(A, N);
   B = randInit(B, M);

   cout << "A: "; printArray(A);
   cout << "B: "; printArray(B);
   cout << "Brute force intersection..." << endl;

   vector<int> C = intersection(A, B);
   cout << "Intersection: "; printArray(C);
}
