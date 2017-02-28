#include <iostream>

using namespace std;

int isRing( int nodeDegree[] ) {
   for( int i=0; i<5; i++ ) {
      if( nodeDegree[i] != 2 )
         return 0;
   }
   return 1;
}

int isStar( int nodeDegree[] ) {
   int centerFound = 0;
   for( int i=0; i<5; i++ ) {
      if( nodeDegree[i] == 4 )
         centerFound += 1;
      else if( nodeDegree[i] != 1 )
         return 0;
   }
   if( centerFound == 1 )
      return 1;
   else
      return 0;
}

int isMesh( int nodeDegree[] ) {
   for( int i=0; i<5; i++ ) {
      if( nodeDegree[i] != 4 )
         return 0;
   }
   return 1;
}

void analyze( int nodeDegree[] ) {
   cout << "Matrix is: " << endl;
   cout << "Ring: " << isRing( nodeDegree ) << endl;
   cout << "Star: " << isStar( nodeDegree ) << endl;
   cout << "Mesh: " << isMesh( nodeDegree ) << endl;
}

int main()
{
   int ring[5][5] = {
      {0, 1, 0, 0, 1},
      {1, 0, 1, 0, 0},
      {0, 1, 0, 1, 0},
      {0, 0, 1, 0, 1},
      {1, 0, 0, 1, 0},
   };

   int star[5][5] = {
      {0, 1, 1, 1, 1},
      {1, 0, 0, 0, 0},
      {1, 0, 0, 0, 0},
      {1, 0, 0, 0, 0},
      {1, 0, 0, 0, 0},
   };

   int mesh[5][5] = {
      {0, 1, 1, 1, 1},
      {1, 0, 1, 1, 1},
      {1, 1, 0, 1, 1},
      {1, 1, 1, 0, 1},
      {1, 1, 1, 1, 0},
   };
   
   int nodeDegreeRing[5] = {0};
   int nodeDegreeStar[5] = {0};
   int nodeDegreeMesh[5] = {0};
   for( int i=0; i<5; i++ ) {
      for( int j=0; j<5; j++ ) {
         nodeDegreeRing[i] += ring[i][j];
         nodeDegreeStar[i] += star[i][j];
         nodeDegreeMesh[i] += mesh[i][j];
      }
   }
   analyze( nodeDegreeRing );
   analyze( nodeDegreeStar );
   analyze( nodeDegreeMesh );
}
