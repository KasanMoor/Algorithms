#include <iostream>
#include <vector>

using namespace std;

const int N = 6;

int main() 
{
   int G[N][N] = {
      { 0, 1, 0, 1, 1, 0 },
      { 1, 0, 1, 0, 1, 0 },
      { 0, 1, 0, 1, 1, 1 },
      { 1, 0, 1, 0, 1, 1 },
      { 1, 1, 1, 1, 0, 1 },
      { 0, 0, 1, 1, 1, 0 }
   };
   vector< vector<int> > permutationList;
   vector<int>::iterator it;
   //vector<int> permutation;
   //permutations.push_back( permutation );
   //permutations[0].push_back(0);
   //it = permutations.begin();

   vector<int> permutation;
   permutation.push_back(0);
   permutationList.push_back(permutation);
   for( int i=1; i<N; i++ ) {
      for( int j=0; j<permutationList.size
   }

   for( int i=0; i<permutationList.size(); i++ ) {
      for( int j=0; j<permutationList[i].size(); j++ ) {
         cout << permutationList[i][j] << endl;
      }
   }
}
