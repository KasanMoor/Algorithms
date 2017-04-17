// Brandon Brewster
// CS395/MATH395-Spring2017-Assignment2-Question7

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

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

pointstruct findMin( vector<pointstruct> pointlist )
{
   int min = pointlist[0].x;
   pointstruct minpoint = pointlist[0];
   for( int i=1; i<pointlist.size(); i++ ) {
      if( pointlist[i].x < min ) {
         min = pointlist[i].x;
         minpoint = pointlist[i];
      }
   } 
   //return min;
   return minpoint;
}

pointstruct findMax( vector<pointstruct> pointlist )
{
   int max = pointlist[0].x;
   pointstruct maxpoint = pointlist[0];
   for( int i=1; i<pointlist.size(); i++ ) {
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
   newline.a = first.y - second.y;
   newline.b = second.x - first.x;
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

void printList( vector<pointstruct> pointList )
{
   for( int i=0; i<pointList.size(); i++ ) {
      cout << "(" << pointList[i].x << ", " << pointList[i].y << ")\n";
   }
}

vector< vector<pointstruct> > splitByLine( linestruct line, 
                                 vector<pointstruct> pointList )
{
   vector<pointstruct> left;
   vector<pointstruct> right;
   for( int i=0; i<pointList.size(); i++ ) {
      if( whichSide(line, pointList[i]) == -1 ) {
         left.push_back(pointList[i]);
	 //cout << "Point " << i << " is to the left" << endl;
      } else if( whichSide(line, pointList[i]) == 1 ) {
         right.push_back(pointList[i]);
	 //cout << "Point " << i << " is to the right" << endl;
      }
   }
   vector< vector<pointstruct> > sets;
   sets.push_back(left);
   sets.push_back(right);
   return sets;
}

int furthestPoint( linestruct line, 
                           vector<pointstruct> pointList )
{
   float furthestDistance = 0;
   int furthestPoint;
   for( int i=0; i<pointList.size(); i++ ) {
      if( distance( line, pointList[i] ) > furthestDistance {
         furthestDistance = distance( line, pointList[i] );
	 furthestPoint = i;
      }
   }
   return furthestPoint;
}

float triangleArea( pointstruct A,
                    pointstruct B,
		    pointstruct C, )
{
   return 0.5*abs( (A.x - A.c)*(B.y-A.y) - (A.x - B.x)*(C.y-A.y) );
}

vector<pointstruct> isOutsideTriangle( pointstruct pointT1,
                                       pointstruct pointT2,
				       pointstruct pointT3,
				       vector<pointstruct> pointList 
				     )
{
   vector<pointstruct> isOutside;
   for( int i=0; i<pointList.size(); i++ ) {
      float A1 = triangleArea( pointList[i], pointT1, pointT2 );
      float A2 = trianlgeArea( pointList[i], pointT2, pointT3 );
      float A3 = triangleArea( point[i], pointT3, pointT1 );
      float A  = triangleArea( point[i], pointT2, pointT3 );
      if( A1+A2+A3 == A ) {
         isOutside.push_back(pointList[i]);
      }
   }
   return isOutside;
}

vector<pointstruct> quickHull( linestruct line, 
                               vector<pointstruct> pointList )
{
   //find point with max distance
   int furthestI = furthestPoint( line, pointList );
   //throw out points inside triangle 
   //!!!!this is still includinng the firthest point
   pointList = isOutside( line.point1, 
                          line.point2, 
			  pointList[furthesti],
			  pointList );
   //seperate remaining by left and right of max point 
   //recurse on left and right
}

vector<pointstruct> quickHull( vector<pointstruct> pointList )
{
   vector<pointstruct> hullPoints;
   pointstruct minx = findMin(pointList);
   pointstruct maxx = findMax(pointList);
   linestruct line = generateLine( minx, maxx );
   vector< vector<pointstruct> > sets = splitByLine( line, pointList );
   cout << "left: " << endl; printList( sets[0] );
   cout << "right: " << endl; printList( sets[1] );
   //quickHull( line, sets[0] );
   //quickHull( line, sets[1] );
   //hullPoints.push_back(minx);
   //hullPoints.push_back(maxx);

   

   return hullPoints;
}

int main() 
{
   vector<pointstruct> pointList;
   pointstruct point;
   point.x = 5; point.y = 5; point.isExtreme = 0;
   pointList.push_back(point);
   point.x = 4; point.y = 3; point.isExtreme = 0;
   pointList.push_back(point);
   point.x = 2; point.y = 3; point.isExtreme = 0;
   pointList.push_back(point);
   point.x = 6; point.y = 1; point.isExtreme = 0;
   pointList.push_back(point);
   point.x = 1; point.y = 4; point.isExtreme = 0;
   pointList.push_back(point);
   point.x = 2; point.y = 2; point.isExtreme = 0;
   pointList.push_back(point);

   cout << "initial list: " << endl; printList( pointList );
   vector<pointstruct> hullPoints = quickHull( pointList );
   //printList( hullPoints );
   


   //quickHull( pointList );

   for( int i=0; i<n; i++ ) {
      if( pointList[i].isExtreme == 1 ) {
         cout << "point is HULL: " <<pointList[i].x << " " << pointList[i].y << endl;
      }
   }
}
