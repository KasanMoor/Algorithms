#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int n = 5;

struct pointstruct {
   int x;
   int y;
   int isExtreme;
};

struct linestruct {
   int a;
   int b;
   int c;
};

int findMin( int pointlist[] )
{
   int min = pointlist[0].x;
   for( int i=1; i<n; i++ ) {
      if( pointlist[i].x < min )
         min = pointlist[i].x;
   } 
   return min;
}

int findMax( int pointlist[] )
{
   int max = pointlist[0].x;
   for( int i=1; i<n; i++ ) {
      if( pointlist[i].x > max )
         max = pointlist[i].x;
   } 
   return max;
}

linestruct generateLine( point first, point second )
{
   struct linestruct newline;
   newline.a = second.y - first.y;
   newline.b = first.x - second.x;
   newline.c = first.x*second.y - second.x*first.y;
   return newline;
}

double distance( linestruct line, pointstruct point )
{
   double top = abs( line.a*point.x + line.b*point.y + line.c );
   double bot = sqrt( pow( line.a, 2 ) + pow( line.b, 2 ) );
   return top/bot;
}

int checkAgainstOthers( int a, int b, int c, point* pointList )
{
   int direction = -1;
   int comparison;
   for( int i=0; i<5; i++ ) {
         comparison = a*pointList[i].x + b*pointList[i].y - c;
         cout << comparison << endl;
         if( comparison > 0 && direction == -1 )
            direction = 1;
         else if( comparison < 0 && direction == -1 )
            direction = 0;
         if( comparison > 0 && direction == 0 )
            return 0;
         else if( comparison < 0 && direction == 1 )
            return 0;
   }
   return 1;
   
}

int main() 
{
   point pointList[5];
   pointList[0].x = 5; pointList[0].y = 5; pointList[0].isExtreme = 0;
   pointList[1].x = 4; pointList[1].y = 3; pointList[1].isExtreme = 0;
   pointList[2].x = 2; pointList[2].y = 3; pointList[2].isExtreme = 0;
   pointList[3].x = 6; pointList[3].y = 1; pointList[3].isExtreme = 0;
   pointList[4].x = 1; pointList[4].y = 4; pointList[4].isExtreme = 0;

   int minx = findMin( pointList );
   int maxx = findMax( pointList );


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
}
