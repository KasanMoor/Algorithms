#include <iostream>
#include <vector>

using namespace std;

const int N = 6;

void printList( vector<int> list )
{
   for( int i=0; i<list.size(); i++ ) {
      cout << list[i] << " ";
   }
   cout << endl;
}

int max( vector<int> list )
{
   if( list.size() == 1 ) {
      return list[0];
   }
   vector<int> left;
   vector<int> right;
   for( int i=0; i<list.size(); i++ ) {
      if( i%2 == 0 )
         left.push_back(list[i]);
      else
         right.push_back(list[i]);
   }
   int leftmin = max( left );
   int rightmin = max( right );
   if( leftmin < rightmin )
      return rightmin;
   else
      return leftmin;
}

int min( vector<int> list )
{
   if( list.size() == 1 ) {
      return list[0];
   }
   vector<int> left;
   vector<int> right;
   for( int i=0; i<list.size(); i++ ) {
      if( i%2 == 0 )
         left.push_back(list[i]);
      else
         right.push_back(list[i]);
   }
   int leftmin = min( left );
   int rightmin = min( right );
   if( leftmin > rightmin )
      return rightmin;
   else
      return leftmin;
}

int main()
{
   vector<int> list;
   for( int i=0; i<N; i++ ) {
      list.push_back(i);
   }
   printList( list );
   int minimum = min( list );
   int maximum = max( list );
   cout << "Min: " << minimum << endl
        << "Max: " << maximum << endl;
   //int max( list );
   //printList( list );
}
