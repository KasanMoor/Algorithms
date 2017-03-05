#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > generateSubset( int n );
void printSubsets( vector< vector<int> > subsetList );

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
   vector< vector<int> > subsetList = generateSubset( N );
   vector< vector<int> > cliqueSubsets;
   //printSubsets( subsetList );
   for( int i=0; i<subsetList.size(); i++ ) {
      int isClique = 1;
      for( int j=0; j<subsetList[i].size(); j++ ) {
         for( int k=1; k<subsetList[i].size(); k++ ) {
	    if( G[subsetList[i][j]][subsetList[i][k]] == 0 )
	       isClique = 0;
	 }
      }
      if( isClique && subsetList[i].size() > 1 )
         cliqueSubsets.push_back(subsetList[i]);
   }
   printSubsets( cliqueSubsets );
}

vector< vector<int> > generateSubset( int n ) 
{
   vector< vector<int> > subsetList;
   vector<int> subset;
   subset.push_back(0);
   subsetList.push_back( subset );
   for( int i=1; i<n; i++ ) {
      int size = subsetList.size();
      vector<int> subset;
      subset.push_back(i);
      subsetList.push_back( subset );
      for( int j=0; j<size; j++ ) {
         vector<int> subset = subsetList[j];
	 subset.push_back(i);
         subsetList.push_back( subset );
      }
   }
   return subsetList;
}

void printSubsets( vector< vector<int> > subsetList )
{
   for( int i=0; i<subsetList.size(); i++ ) {
      for( int j=0; j<subsetList[i].size(); j++ ) {
         cout << subsetList[i][j] << " ";
      }
      cout << endl;
   }
}
