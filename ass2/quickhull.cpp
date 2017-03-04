#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int n = 6;

struct pointstruct {
   int x;
   int y;
   int isExtreme;
};

struct linestruct {
   int a;
   int b;
   int c;
   pointstruct point1;
   pointstruct point2;
};

pointstruct findMin( pointstruct pointlist[] )
{
   int min = pointlist[0].x;
   pointstruct minpoint = pointlist[0];
   for( int i=1; i<n; i++ ) {
      if( pointlist[i].x < min ) {
         min = pointlist[i].x;
         minpoint = pointlist[i];
      }
   } 
   //return min;
   return minpoint;
}

pointstruct findMax( pointstruct pointlist[] )
{
   int max = pointlist[0].x;
   pointstruct maxpoint = pointlist[0];
   for( int i=1; i<n; i++ ) {
      if( pointlist[i].x > max ) {
         max = pointlist[i].x;
	 maxpoint = pointlist[i];
      }
   } 
   //return max;
   return maxpoint;
}

linestruct generateLine( pointstruct first, pointstruct second )
{
   struct linestruct newline;
   newline.a = second.y - first.y;
   newline.b = first.x - second.x;
   newline.c = first.x*second.y - second.x*first.y;
   newline.point1 = first;
   newline.point2 = second;
   return newline;
}

double distance( linestruct line, pointstruct point )
{
   double top = abs( line.a*point.x + line.b*point.y + line.c );
   double bot = sqrt( pow( line.a, 2 ) + pow( line.b, 2 ) );
   return top/bot;
}

double whichSide( linestruct line, pointstruct point )
{
   double direction = (line.point2.x - line.point1.x)*(point.y - line.point1.y) - 
                      (line.point2.y - line.point1.y)*(point.x - line.point1.x);
   if( direction < 0 )
      return -1;
   if( direction > 0 )
      return 1;
   else
      return 0;
}

void quickHull( int direction, linestruct line, pointstruct pointList[] )
{
   int found = 0;
   pointstruct furthest = {0};
   double furthestDistance;
   for( int i=0; i<n; i++ ) {
      if( whichSide(line, pointList[i] ) == direction ) {
         if( found ==0 ) {
	    furthestDistance = distance( line, pointList[i] );
	    furthest = pointList[i];
	    found = 1;
	 }
	 else if( distance( line, pointList[i] ) > furthestDistance ) {
	    furthestDistance = distance( line, pointList[i] );
	    furthest = pointList[i];
	 }
      }
   }
   if( found == 1 ) {
      linestruct left = generateLine( line.first, furthest );
      linestruct right = generateLine( furthest, line.second );
      quickhull( -1, left, pointList );
      quickhull( 1, right, pointList );
   }
}

void quickHull( pointstruct pointList[] )
{
   pointstruct min = findMin( pointList );
   pointstruct max = findMax( pointList );
   linestruct line = generateLine( min, max );
   quickhull( -1, line, pointList );
   quickhull( 1, line, pointList );
}


int main() 
{
   pointstruct pointList[5];
   pointList[0].x = 5; pointList[0].y = 5; pointList[0].isExtreme = 0;
   pointList[1].x = 4; pointList[1].y = 3; pointList[1].isExtreme = 0;
   pointList[2].x = 2; pointList[2].y = 3; pointList[2].isExtreme = 0;
   pointList[3].x = 6; pointList[3].y = 1; pointList[3].isExtreme = 0;
   pointList[4].x = 1; pointList[4].y = 4; pointList[4].isExtreme = 0;
   pointList[5].x = 2; pointList[5].y = 2; pointList[5].isExtreme = 0;

   //int minx = findMin( pointList );
   //int maxx = findMax( pointList );
   linestruct line = generateLine( pointList[4], pointList[3] );
   cout << "distance to 3: "  << distance( line, pointList[3] ) << endl;
   cout << "distance to 2: "  << distance( line, pointList[2] ) << endl;
   cout << "side of 0: "  << whichSide( line, pointList[0] ) << endl;
   cout << "side of 1: "  << whichSide( line, pointList[1] ) << endl;
   cout << "side of 2: "  << whichSide( line, pointList[2] ) << endl;
   cout << "side of 3: "  << whichSide( line, pointList[3] ) << endl;
   cout << "side of 4: "  << whichSide( line, pointList[4] ) << endl;

   line = generateLine( pointList[0], pointList[3] );
   cout << "side of 1 from 0, 3: "  << whichSide( line, pointList[1] ) << endl;
   line = generateLine( pointList[0], pointList[4] );
   cout << "side of 1 from 0, 4: "  << whichSide( line, pointList[1] ) << endl;




/*
   int a;
   int b;
   int c;
   int result;
   for( int i=0; i<5; i++ ) {
      for( int j=i+1; j<5; j++ ) {
         a = pointList[j].y - pointList[i].y;
         b = pointList[i].x - pointList[j].x;
         c = pointList[i].x*pointList[j].y - pointList[j].x*pointList[i].y;
         cout << "point 1: " <<pointList[i].x << " " << pointList[i].y << endl;
         cout << "point 2: " <<pointList[j].x << " " << pointList[j].y << endl;
         cout << "a: " << a << " b: " << b << " c: " << c << endl;
         result = checkAgainstOthers(a, b, c, pointList);
         if( result == 1 ) {
            pointList[i].isExtreme = 1;
            pointList[j].isExtreme = 1;
         }
         cout << result << endl;
      }
   }

   for( int i=0; i<5; i++ ) {
      if( pointList[i].isExtreme == 1 ) {
         cout << "point is HULL: " <<pointList[i].x << " " << pointList[i].y << endl;
      }
   }
   */
}
