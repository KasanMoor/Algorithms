#include <iostream>
#include <vector>

using namespace std;

const int N = 6;

vector< vector<int> > generateSubset( int n );
int printSubsets( vector< vector<int> > subsetList );
vector< vector<int> > clique( int G[N][N], int k );

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
   
   int k;
   cout << "Size of clique to search for: ";
   cin >> k;
   vector< vector<int> > cliqueList = clique( G, k );
   printSubsets( cliqueList );
}

vector< vector<int> > clique( int G[N][N], int k )
{
   vector< vector<int> > subsetList = generateSubset( N );
   vector< vector<int> > cliqueSubsets;
   //printSubsets( subsetList );
   for( int i=0; i<subsetList.size(); i++ ) {
      int isClique = 1;
      for( int j=0; j<subsetList[i].size(); j++ ) {
         for( int k=1; k<subsetList[i].size(); k++ ) {
	    if( G[subsetList[i][j]][subsetList[i][k]] == 0 && k!=j ) {
	       isClique = 0;
	    }
	 }
      }
      if( isClique == 1 && subsetList[i].size() > 1 )
         cliqueSubsets.push_back(subsetList[i]);
   }
   //printSubsets( cliqueSubsets );
   vector< vector<int> > sizeKCliques;
   for( int i=0; i<cliqueSubsets.size(); i++ ) {
      if( cliqueSubsets[i].size() == k ) {
         sizeKCliques.push_back( cliqueSubsets[i] );
      }
   }
   return sizeKCliques;
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

int printSubsets( vector< vector<int> > subsetList )
{
   if( subsetList.size() == 0 ) {
      cout << "No subsets found" << endl;
      return 0;
   }
   for( int i=0; i<subsetList.size(); i++ ) {
      for( int j=0; j<subsetList[i].size(); j++ ) {
         cout << subsetList[i][j] << " ";
      }
      cout << endl;
   }
   return 1;
}
