#include <iostream>
#include <string>

using namespace std;

int TowerOfHanoi( int ndisks,
                  string fromPeg,
                  string toPeg,
                  string withPeg )
{
   if(ndisks == 1)
      cout << "moving disk from " << fromPeg << " to " << toPeg << endl;
   else {
      TowerOfHanoi( ndisks-1, fromPeg, withPeg, toPeg );
      cout << "moving disk from " << fromPeg << " to " << toPeg << endl;
      TowerOfHanoi( ndisks-1, withPeg, toPeg, fromPeg );
   }
   return 1;
}

int main()
{
   int ndisks;
   cout << "Enter number of disks: ";
   cin >> ndisks;
   string fromPeg = "A";
   string toPeg = "C";
   string withPeg = "B";

   TowerOfHanoi(ndisks, fromPeg, withPeg, toPeg);
   TowerOfHanoi(ndisks, withPeg, toPeg, fromPeg);
}
