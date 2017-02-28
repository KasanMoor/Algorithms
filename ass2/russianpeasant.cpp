#include <iostream>

using namespace std;

int main()
{
   int x; 
   int y;
   cout << "Enter two integers: ";
   cin >> x >> y;
   
   int sum = 0;
   while( x>1 ){
      cout << x << " " << y << endl;
      if( x%2 == 1 ) {
         cout << "adding: " << y << endl;
         sum += y;
      }
      x /= 2;
      y *= 2;
   }
   if( x == 1 ) {
      sum += y;
      cout << "adding: " << y << endl;
   }
   cout << sum << endl;
}
