#include <iostream>

using namespace std;

int main()
{
   int m; 
   int n;
   int r;
   cout << "Enter 2 non negative not both zero integers seperated by space: ";
   cin >> m >> n;
 //  cout << m << n << endl;
   while( n != 0 ) {
      r = m % n;
      m = n;
      n = r;
   }
   cout << m << endl;
}
