#include <iostream>

using namespace std;

struct point {
   int x;
   int y;
   int isExtreme;
};

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
