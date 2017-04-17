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

vector<int> sort(vector<int> a) {
   //vector<int> b;
   //cout << "uhm" << endl;
   for(int i=0; i<a.size(); i++) {
      for(int j=1; j<a.size()-i; j++) {
         if(a[j]<a[j-1]) {
	    int temp = a[j-1];
	    a[j-1] = a[j];
	    a[j] = temp;
	 }
      }
   }
   return a;
}

vector<int> randInit(vector<int> A, int n) {
   for( int i=0; i<n; i++) {
      A.push_back((rand() % 10)+1);
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

int binarySearch( vector<int> a, int key, int min, int max ) {
   //cout << "min: " << min << " max: " << max << endl;
   if( min >= max )
      return 0;
   int split = (min+max)/2;
   if(key == a[split]) 
      return 1;
   else if( key < a[split] )
      return binarySearch(a, key, min, split-1);
   else if( key > a[split] )
      return binarySearch(a, key, split+1, max);
}
/*
int binarySearch( vector<int> a, int key ) {
   if(a.size() == 0);
      return 0;
   int split = a.size()/2;
   if(a[split] == key)
      return 1;
   if(key < a[split]) {
      vector<int> first;
      for(int i = 0; i<split; i++) {
         first.push_back(a[i]);
      }
      return binarySearch( first, key );
   }
   if(key > a[split]) {
      vector<int> second;
      for(int i=split; i<a.size(); i++) {
         second.push_back(a[i]);
      }
      return binarySearch( second, key );
   }
}
*/
vector<int> intersection( vector<int> a, vector<int> b ) {
   vector<int> intersection;
   for(int i=0; i<a.size(); i++) {
      int bs = binarySearch(b, a[i], 0, b.size());
      if(bs && !memberOf(intersection, a[i])) {
         intersection.push_back(a[i]);
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
   //cout << "A: "; printArray(A);
   A = sort(A);
   B = randInit(B, M);
   //cout << "B: "; printArray(B);
   B = sort(B);

   cout << "A: "; printArray(A);
   cout << "B: "; printArray(B);
   cout << "Presorted intersection..." << endl;

   vector<int> C = intersection(A, B);
   cout << "Intersection: "; printArray(C);
}
