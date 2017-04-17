CS_MATH395_S17_A2_2_a_Brewster_Brandon.cpp                                                          0000666 0001750 0001750 00000002707 13057462537 017160  0                                                                                                    ustar   kasan                           kasan                                                                                                                                                                                                                  // Brandon Brewster
// CS395/MATH395-Spring2017-Assignment2-Question2

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int n = 10;

void printArray( int array[] )
{
   for( int i=0; i<n; i++ ) {
      cout << array[i] << " ";
   }
   cout << endl;
}

void shellsort( int a[], int size )
{
   const int numGaps = 3;
   int gaps[numGaps] = {5, 3, 1};
   for( int g=0; g<numGaps; g++ ) {
      int gap = gaps[g];
      for( int i=gap; i<size; i++ ) {
         for( int j=i; j>=gap; j-=gap ) {
	    if( a[j] < a[j-gap] ) {
	       int temp = a[j];
	       a[j] = a[j-gap];
	       a[j-gap] = temp;
	    }
	 }
      }
   }
}

void insertionsort( int array[], int size )
{
   for( int i=1; i<size; i++ ) {
      for( int j=i; j>0; j-- ) {
         if( array[j] < array [j-1] ) {
	    int temp = array[j];
	    array[j] = array[j-1];
	    array[j-1] = temp;
	 }
      }
   }
}

int* generateArray( int size )
{
   srand( time(NULL) );
   int* array = new int[size];
   for( int i=0; i<size; i++ ) {
      array[i] = rand() % size;
   }
   return array;
}

void doOnSize( int size )
{
   int* array = generateArray(size);
   //printArray( array );
   int start_s = clock();
   insertionsort( array, size );
   int stop_s=clock();
   cout << "Shellsort time on size " << size 
        << ": " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

int main() 
{
   doOnSize( 100 );
   doOnSize( 1000 );
   doOnSize( 10000 );
}
                                                         CS_MATH395_S17_A2_2_b_Brewster_Brandon.cpp                                                          0000666 0001750 0001750 00000002666 13057462555 017165  0                                                                                                    ustar   kasan                           kasan                                                                                                                                                                                                                  // Brandon Brewster
// CS395/MATH395-Spring2017-Assignment2-Question2

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int n = 10;

void printArray( int array[] )
{
   for( int i=0; i<n; i++ ) {
      cout << array[i] << " ";
   }
   cout << endl;
}

void shellsort( int a[], int size )
{
   const int numGaps = 3;
   int gaps[numGaps] = {5, 3, 1};
   for( int g=0; g<numGaps; g++ ) {
      int gap = gaps[g];
      for( int i=gap; i<size; i++ ) {
         for( int j=i; j>=gap; j-=gap ) {
	    if( a[j] < a[j-gap] ) {
	       int temp = a[j];
	       a[j] = a[j-gap];
	       a[j-gap] = temp;
	    }
	 }
      }
   }
}

void insertionsort( int array[] )
{
   for( int i=1; i<n; i++ ) {
      for( int j=i; j>0; j-- ) {
         if( array[j] < array [j-1] ) {
	    int temp = array[j];
	    array[j] = array[j-1];
	    array[j-1] = temp;
	 }
      }
   }
}

int* generateArray( int size )
{
   srand( time(NULL) );
   int* array = new int[size];
   for( int i=0; i<size; i++ ) {
      array[i] = rand() % size;
   }
   return array;
}

void doOnSize( int size )
{
   int* array = generateArray(size);
   //printArray( array );
   int start_s = clock();
   shellsort( array, size );
   int stop_s=clock();
   cout << "Shellsort time on size " << size 
        << ": " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

int main() 
{
   doOnSize( 100 );
   doOnSize( 1000 );
   doOnSize( 10000 );
}
                                                                          CS_MATH395_S17_A2_2_c_Brewster_Brandon.cpp                                                          0000666 0001750 0001750 00000002435 13057462573 017160  0                                                                                                    ustar   kasan                           kasan                                                                                                                                                                                                                  // Brandon Brewster
// CS395/MATH395-Spring2017-Assignment2-Question2

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int n = 10;

void printArray( int array[] )
{
   for( int i=0; i<n; i++ ) {
      cout << array[i] << " ";
   }
   cout << endl;
}

void selectionsort( int a[], int size ) 
{
   int j;
   int min;
   for( int i=0; i<size; i++ ) {
      min = i;
      for( j=i; j<size; j++ ) {
	 //cout << "comparing: " << a[j] << " " << a[min];
         if( a[j] < a[min] ) {
	    min = j;
	    //cout << "; Min is now " << a[min];
	 }
	 //cout << endl;
      }
      //cout << "swapping: " << a[min] << " " << a[i] << endl;
      int temp = a[min];
      a[min] = a[i];
      a[i] = temp;
   }
}

int* generateArray( int size )
{
   srand( time(NULL) );
   int* array = new int[size];
   for( int i=0; i<size; i++ ) {
      array[i] = rand() % size;
   }
   return array;
}

void doOnSize( int size )
{
   int* array = generateArray(size);
   //printArray( array );
   int start_s = clock();
   selectionsort( array, size );
   int stop_s=clock();
   cout << "Shellsort time on size " << size 
        << ": " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

int main() 
{
   doOnSize( 100 );
   doOnSize( 1000 );
   doOnSize( 10000 );
}
                                                                                                                                                                                                                                   CS_MATH395_S17_A2_2_d_Brewster_Brandon.cpp                                                          0000666 0001750 0001750 00000003460 13057462611 017151  0                                                                                                    ustar   kasan                           kasan                                                                                                                                                                                                                  // Brandon Brewster
// CS395/MATH395-Spring2017-Assignment2-Question2

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int n = 10;

void printArray( int array[] )
{
   for( int i=0; i<n; i++ ) {
      cout << array[i] << " ";
   }
   cout << endl;
}

int partition( int a[], int low, int hi )
{
      /*cout << "partitioning; low: " << low 
           << " high: " << hi 
	   << " pivot: " << a[hi]
	   << endl;*/
      int pivot = a[hi];
      int i = low-1;
      for( int j=low; j<hi; j++ ) {
         //cout << "Comparing: "
	   //   << a[j] << " " << pivot << endl;
         if( a[j] <= pivot ) {
	    //cout << "Swapping: " 
	      //   << a[i+1] << " " << a[j] << endl;
            i++;
	    int temp = a[i];
	    a[i] = a[j];
   	    a[j] = temp;
            //printArray( a );
         }
      }
      int temp = a[i+1];
      a[i+1] = a[hi];
      a[hi] = temp;
      return i+1;
}
void quicksort( int a[], int low, int hi ) 
{
   if( low < hi ) {
      int p = partition( a, low, hi );
      //cout << "quicksort; low: " << low << " hi: " << p-1 << endl;
      quicksort( a, low, p-1 );
      //cout << "quicksort; low: " << p+1 << " hi: " << hi << endl;
      quicksort( a, p+1, hi );
   }
}

int* generateArray( int size )
{
   srand( time(NULL) );
   int* array = new int[size];
   for( int i=0; i<size; i++ ) {
      array[i] = rand() % size;
   }
   return array;
}

void doOnSize( int size )
{
   int* array = generateArray(size);
   //printArray( array );
   int start_s = clock();
   quicksort( array, 0, size-1 );
   int stop_s=clock();
   //printArray( array );
   cout << "Shellsort time on size " << size 
        << ": " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

int main() 
{
   doOnSize( 100 );
   doOnSize( 1000 );
   doOnSize( 10000 );
}
                                                                                                                                                                                                                CS_MATH395_S17_A2_5_Brewster_Brandon.cpp                                                            0000666 0001750 0001750 00000000661 13057462635 016657  0                                                                                                    ustar   kasan                           kasan                                                                                                                                                                                                                  #include <iostream>

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
                                                                               CS_MATH395_S17_A2_6_c_Brewster_Brandon.cpp                                                          0000666 0001750 0001750 00000002510 13057462665 017160  0                                                                                                    ustar   kasan                           kasan                                                                                                                                                                                                                  #include <iostream>
#include <vector>

using namespace std;

const int N = 6;

void printList( vector<int> list )
{
   for( int i=0; i<list.size(); i++ ) {
      cout << list[i] << " ";
   }
   cout << endl;
}

int max( vector<int> list )
{
   if( list.size() == 1 ) {
      return list[0];
   }
   vector<int> left;
   vector<int> right;
   for( int i=0; i<list.size(); i++ ) {
      if( i%2 == 0 )
         left.push_back(list[i]);
      else
         right.push_back(list[i]);
   }
   int leftmin = max( left );
   int rightmin = max( right );
   if( leftmin < rightmin )
      return rightmin;
   else
      return leftmin;
}

int min( vector<int> list )
{
   if( list.size() == 1 ) {
      return list[0];
   }
   vector<int> left;
   vector<int> right;
   for( int i=0; i<list.size(); i++ ) {
      if( i%2 == 0 )
         left.push_back(list[i]);
      else
         right.push_back(list[i]);
   }
   int leftmin = min( left );
   int rightmin = min( right );
   if( leftmin > rightmin )
      return rightmin;
   else
      return leftmin;
}

int main()
{
   vector<int> list;
   for( int i=0; i<N; i++ ) {
      list.push_back(i);
   }
   printList( list );
   int minimum = min( list );
   int maximum = max( list );
   cout << "Min: " << minimum << endl
        << "Max: " << maximum << endl;
   //int max( list );
   //printList( list );
}
                                                                                                                                                                                        CS_MATH395_S17_A2_7_Brewster_Brandon.cpp                                                            0000666 0001750 0001750 00000013311 13057462713 016652  0                                                                                                    ustar   kasan                           kasan                                                                                                                                                                                                                  // Brandon Brewster
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
                                                                                                                                                                                                                                                                                                                       CS_MATH395_S17_A2_Brewster_Brandon.pdf                                                              0000777 0001750 0001750 00000457020 13057463121 016421  0                                                                                                    ustar   kasan                           kasan                                                                                                                                                                                                                  %PDF-1.5
%����
7 0 obj
<<
/Length 755       
/Filter /FlateDecode
>>
stream
xڅU�n�0}�W�QjUߴ�6���F_�!pl'��I�[�~�$�Na`(P1yxtHɜl	'����6]\R1�q�C�n���\��'L���A����7^����Ҟ���Qī������<�i�ҁ�/��ɹ��h�g���Abp}�Y C����F�]�1��|)8�<��4�	�r�B��� ���D�%�{��:�q1n~Y���AyNo�^��0�x�Қ^�Stye7�Vc��ͳuZT'�*�9vw>?�,y�oB^�ŉ�C��.&�ƀ�dyV<��AH�b��!��0���4��Y(F��y�G��y�􄊘���;����àt�x_DL��f�h�	rmU\��^H˓�'���Cy�AJb�M�P���k�>hw���1 ?y"�  ݝ�ݤ`�bˡ$t����_ZkU�W������F�QY��rw��4��d�����d9����bV�O$f�d@�A�]�	�KkF�TA_f��h�"Uw�H-�`��ww	�;3��-^�a�-�o�}�l�x	�LW��Us(�f�9���	�(�mD�윿9�kی� �:�sj�L��Uo��!��Y�t�82����B�7}sn�(�,�z�����5���<�k]�Ct��3�������}'��IN�s��xvDM��]��8�Sm��3��w�N�%Q"dBj�׋�B�P�"���l�(b��NB6n\?Ԃ|l��o���>�'�7��M��Xgd4_������
endstream
endobj
4 0 obj
<<
/Type /XObject
/Subtype /Image
/Width 355
/Height 114
/BitsPerComponent 8
/Length 20690
/ColorSpace /DeviceRGB
/Filter /DCTDecode
>>
stream
���� JFIF  ` `  ���Exif  MM *    ;      J�i      R��      r�      >    �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         Brandon  �     d    �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           B r a n d o n   ��
`http://ns.adobe.com/xap/1.0/ <?xpacket begin='﻿' id='W5M0MpCehiHzreSzNTczkc9d'?>
<x:xmpmeta xmlns:x="adobe:ns:meta/"><rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"><rdf:Description rdf:about="uuid:faf5bdd5-ba3d-11da-ad31-d33d75182f1b" xmlns:dc="http://purl.org/dc/elements/1.1/"/><rdf:Description rdf:about="uuid:faf5bdd5-ba3d-11da-ad31-d33d75182f1b" xmlns:dc="http://purl.org/dc/elements/1.1/"><dc:creator><rdf:Seq xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"><rdf:li>Brandon</rdf:li></rdf:Seq>
			</dc:creator></rdf:Description></rdf:RDF></x:xmpmeta>
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                            <?xpacket end='w'?>�� C 

		
'!%"."%()+,+ /3/*2'*+*�� C
	
***************************************************��  rc" ��           	
�� �   } !1AQa"q2���#B��R��$3br�	
%&'()*456789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz���������������������������������������������������������������������������        	
�� �  w !1AQaq"2�B����	#3R�br�
$4�%�&'()*56789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz��������������������������������������������������������������������������   ? �w�P^h�j�L�0�^��Ā<�?�Dq��oc��� �+�>o��M@4�<q���[�#͗p	�:�94�� �~�qf�[Kk�Q<�d�I%,U�y� �0F3��}7��Zdv=3N�M9ݬ�$cv�T �O$������+_?��� �ʗ�������w}bi�Ui���\, �f��<>�7��'�mU�{�y]�I!�^[x��,�2q�6����'ħE�-��b/����c*�go���r�z�i^5�ҭ��M;O��Mf6��$��ۘ`8S�<�$g�01���,i�����|�a��̋mn���2�/����9 �Os��hm���6�K���P�K%��̦(����Ŵ�	g7���/m'��+r�C3@[�˝�����-�cm�m<s��c���\4������Yc�;���p^�m��cA|�[[It�[��{��7�����EO*! ��U�F���GB��u���u�ZL/a�73����2���a|����z�>8��;W���{�7�K{�D�X�ܹlHf$eMGe�+�;�N���N�m/$�!,ŷ ! ������=�3-�-Z��[�=.�{Hs�\En�`d�����e�iw��4�dWKr��f�d�B>̈�K�8W!�͵y�>$�y$��E�x��O��C���Ϧ�6WS��e�[w\+a�#r�_N)�����qu2m��e��f���qϳ[K}�-�����=j�^�g����ȼ7N�Y������R��� Oz���X_[=���{�����,E[9F�˞��R[k:���5��w����#��A���(�j�����jz�8���G�^��1Ѷ����xz����n�ݪjkp�{�a�@�����^A��Vέ�x~�J�*;y$�Vߟ:F�F8 ��ӳ��4�%�����z*%�R��.�2&�6�N}�(�o������ �At�[���Moj��`xe6���Z`�6��8�qS���a���=��������B�����v����Fj���R�N���*_߳��Xޠm� ���t�'�t�|+��Z�Kh���M%�I .�Dk6T�9�^ t���l��ޭ%�ޭ�c��K�C+o72����g��X\k:�Ӥ����"�6�#,�]B����=$V��t�ۤwX3� g��#4��Ia�0F�%��lk2�W�����gc�y]����s�ݣ���P64�KQ�}���� 2�6��B���	�?'#�Ko��q������W���g��_�ݰ0{��=�Y�o�MѮt��]:�.�Y噧� �~�t�9�t�y����ۋMB�ID�;�0yr+�Ln���I({5�N���zf���f�Z��OK��3���#ep8���`Q�|=��Ӭ�.uַ��8�hVȾ�$��x���=�p,�O{e6�$Q@N�X��V��9s��y=�V�|m�ZCopZ�o1��nDS�?7����Zz_^� ���_Oĝ|���W����y��t�p��x��o1|�{px�U/�C���^E�ZE���^y�����)��-���K�}*�u'�I�g��9���8�@O�j�έ�x~�J�*;y$�Vߟ:F�F8 �{k���k� _#g��	�Ķ�����Ѥ��-�l@�\��8� ��T6>����M=�"�XX���`��b�`烃�'ڍ+ƷzU����i�2���{���A�s
y'����F*�>%:.�l��}���T�#;|͇ �#�4�[	y�l<-ׅ�Y�{�Z@�ab. 9�������O�O�KM3T�����Wɷ��{�Q��5��{T�{h�C$�;g�#:"��:]���0���c*�gh��8�����W�_��.��][,�fiZ�W=�r�l~'#�`]x~�,5-j�(��/&�@���^h�� �Z�Û�kK���_P��c��B�IQ�J��`G�98�v�V�=.<���I�`��l H� ( {�����PX_�V:�v�Ż�U�rT�\�����&��_ր]��#���������.5=�����j�����7֮�_o5�.��M�mCٚ=��v���(a����Y6-��-mmm-�R�3΄���6���|�/�Q��2?���e{�i��[��1�̭��T�r3�7g���� _��W��O��=��n�i��	%ŵ�I�B�g4�Z�er��t���N��h�0�B�����v˩��9R�����|9M�Կn�PH�33�w%��I=�������h`�Ե�ȣ�+H��#�+� !x<�s� �EP���ɥ�Y}���h������m��=�����w�촨a򣷒I�m��l �c�( {������K4}KX�g�7�������!�f,�n�c'�ǭ�%�����S[ڱ�XM�~j��ͻ�1�U(<DˣŦ�i�Z�6�ͳ\y��o傘�r23��?SO�|H�n�s�b��)t�,�>� m��e `�9�:t�{W�6�2二B]g�cS( �.��9�l�q��E����t��RkK�]��c��L�)�ɑv啱���7ĉ���:w�.�r�@,����ܿvP:Ӝ֯�|b�n��Ǫ[Y�ld*��D�43e� pFKc*H�pEw�F��l���?m������퐧���=�KC�qy��w ��.-�=��v���(#��������ku��d�i�}̺|����<A�,�
A9�FN8�H|G� �lu*�QKb� g{�2�A�J������8$�Ч���ѻ#���ƒ�(QE�U��ݶ���k:���7v�7���د�Ȟ`�2q��<Xz]��x]�ou�ȳ�1�� b�~T��6r8�Ku�5��Ey-�������+�34�������;e1����'MՃ��}ؼ�N���a�����kJ�ŗ��gG�q����7�M��֥{m-�FI �G�9� 4�p1���ֶ����Z�쮁�W�7�����Ц�Ty҂<�X�lN+��q��)�M�i�Q,�/�+N��F2�%Pp8s�r�<E�J��� J��c��-��ʯc���"�g'��	5�41�7dq������I�xV��=2+�Q�o�pM�Kk�G�����M̤p�����j��� \��������b���m���
�bXoV�4�j}�J�Ӽ)�jjz4w�u�7�r\`D�����q(9� �3�+�&wm�f$�P�� j����Ѯt����K��߹�q���J�K�� ���Cn-��R�5�����mj&fpY�:�����kIu��.����mV�Sm��� ��n�c�gJ2��i��m���sl�j��`�7\��������&��\��غu�] ��3O�@r��@8�NsCBΕoj��fC�Q�K��A�je �ߕ'<���3R������Mis���,p�	�P�792.ܲ�0������4��N��ӮR��Y�}� ۗ�� ��@:s�����SM�4x�Kk3��R�H��&l���leI��N�(��O�^���?�]�>V|�����g�ih/5�6�����ųA��Ю�T�y`�=`rqY�_�n��l�-?O��O�����7g�3e� �H'<�H����� �W���X�)l_��pfW�1�Pc�r3��g�:�1�7dq������Uo��q������W���g��_�ݰ0{��=�\�j���YiSi�������w>`��
Wr��OCВ8Q�Zڹ��xV��=2+�Q�o�pM�Kk�G�����M̤p�����vX�	�)F׍��� �����>��>�csqa��Ws��-�s��[K��&�Y�ܻ���$�懾�����Ea�h�,�̳�H��Kp ���/�x8<}�CB�sy�ivW@�+���`��hSi*<�AX,�6'��x�芒X�vB�0�;�i��X��O,�r�z�mҠ��Ҭu���w�2���1ȹ����M?xoC��#į�����:K.F̟@�'ң��+�ͤ�׺���Q���O�oT�]ز�NFOQ�y"=+ƷzU����i�2���{���A�s
y'����F2.�Y���=>D�EfҴl��&B	�?�Q���Zh��������mb������Y�*��c$���m�3X�|3^-B�'�%��y���������}�+���L�<Zm��e��n\�5ǚ��X)��##8l��4�~'���F�(�'G,m�+|ۜ���<�أ�:hc�A�+���ck���Tj�*�5������mՄ�T���q�9��g� ��I�j�z��hwZ�~D��;1pdV �c�=�(��K�v~��m<j:����I{8b�.QK�e��8#
���;S��#`t��g\t��2[$_f�#d`����T=G�䊚��t�[D���ņ�]Ύd����l1,7�`�λ��/t�;��WG �c!���h�t�썕���+͹Qo��.r�l8�p9�Q��ڇٴ��?������ϖ-�C���m��=��t��s��chw7�Fk˻+��a���$Q���\m �p���V������V���@�$-s&ȃ)U #9��v�Fy���3�}M���� [	EPEPEPEPEPEPEPuei�j�޹m}���n�s�j�<���[�ڠ���F��'�ۅ��R�_�M��.��][.�4�ҵ�4�\࿗*���q��s�OL{V���#:?�xOO���巼��dD�Rn���`��G��9��2:䎣���+�?���ZU�ۢɎ��֕	�!K�y�)��X�z�osN�g��i����k1�.�g��{/��F��8#9q���{W[�O�<G�G�Zj�����̛"�eT0 ��ư]�I�b��,�rI�4?�@[k�lv^�ׅ�M���WQ��������fB�d�Wӭl�>"��X���E�91_��ҡ9�/��g���^k�NO$��:Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@Q@���j�-Z�����ux��G�Ȏ5\��pq�  �Ecxg��X[ɨ�G�9b�Kt dy��3�@�&���CO�.,�+im`��'�T,�	$����8 F�s������L��G�i�I�;���$�aۊ�)�X��1�o�K��_��R�~_��>����M=�"�XX���`��b�`烃�'ڦ�d�-��/~�+�i$:k�o�%�#fN:�9>������e���E�a�_3LeR����6�T�\խ+ƷzU����i�2���{���A�s
y'����F35~E�3��w֚O��<7���m���z�We�ܸ ��v�M���_&�I`�}���	d�Y����^ض���,���c���E���<��n[Hfh+a�9s��y=�]E��m��-��}4�Alc��������b6Bk,q�s0ݎ�ͱ=�h/���cki.�kq�{�����rH��D$�
��֨�^��I��7&���݆Vp�L"O��8�OZ����Gj�XX�{f�Io}(����-��	Č���escgci����ͥ�S$%����$��5:ا��e���^XK{g���i|ˈ�ݣL����/��.�C�&�L��n^q{,�L��A�ّ	p�'
�1���5�ĖbO$����]i��t�������u�̷�n�k�l1$nV���>����n.�M����}��ߘ.!��kc	o�e��0�p9�[�����א����"+";����ܪX�	�U`��+�g����v�q4[���g(��s���KmgS��f��n��b�U❕���?wۥ ��]�t�5mOR�'zh�C�ܾUF:6����W�OX]�_m�;�MMnO}�67@pw���?w���ռ��iP��Go$�J���H���P �=�Zv~=��t䰾���OED��WXe�&D݆�IϷ�-�z�� �u���.��q�]~)��Xڬ��?5L������*}����:a��'��T3}�`�(X��v2.Ӑx �H�R��JY�׶cA�%K���sp �����c�9��D�.��t�6�R�muI��I$و�`"&ʜ'9���������Ӣ�դ��ղlc�Щr�em�f�R>P����#`t��g\t��2[$_f�#d`����T=G��֞.��;t����K����f��I,1��$�ܭ�Mf]���]���v�+��w1��ێy��_��Ɲij<��<3]Ba��Y�ؾhPb�~A9���w�m��7��Q�������,�٫��{� f �}��+?M�"i�5Ν���\��<�4���/ݔ���t�5��5��6�qai�ZI(�Gs�.@�w)���=	#��f����xoL�4�ׂ�P�I�b��f5�dl�s�l
4���w�u��κ���G�
��$�¼�;���'����l�Ѥ�(	��}��6�.ws�'�*կ��+Hm�R-�5܍Ȋc2��������OK����Z������=�����_�O42.�b./4��/�n �j���h`�Ե�ȣ�+H��#�+� !x<�s� �E>�ŲX�Io�X.��I ���b3�8_3g� ���P�ռ��iP��Go$�J���H���P �=�R�m{Ô���l�_�2x��^�W��4�5巍��ˑ�'`�J��±�xa�����U�VKp�l���_,�px�Q�x��J���4�>�]5��Op��3na��O$�T����]'ħE�-��b/����c*�go���r�z��a/2͇����k2�}"�H,,E�� 37��X9���	���)i�j��6��J�6��Ou�4��/j��mHbĞGl�#�gDT��K�ц߳LeR���yg �#�55�������e�t�e���+\#J�.U�����}l���C���^E�ZE���^y�����+[B�sy�ivW@�+���`��hSi*<�AX,�6'��j�v�g����4�>t��	� �s�qV ��*�*�Q��x�{�*�A�J������8$�� �����_�`�t��_T��eƧ��ԁ�m]߼�~Q��������浥�])��o�3C�����T�<��=`rk&�ŷ�e������[C�yЕb�����o���c�0y�G�0tج�t�>�+r� f3���V;���.FrF��>�?������9�i���M��5�a!d���i<�_��F��#�Vl�X���:�ֺ��h^{{.�u?��*]���گ� ɷz��m��	��fw.�1�'���@��|?m��yr�i�r�ey�/��n�����4��/�������C�X6���������[�����>Tv�I4��>t���q� �s�=���a�o�k�����a��38,ŝ��d�x�����x_�k{V6��)���B� y�~1�3����tx���6�Q�ܹ�k�5Z��S�FFp���i�o�MѮt��]:�.�Y噧� �~�t�9��BΕoj��fC�Q�K��A�je �ߕ'<���3R������Mis���,p�	�P�792.ܲ�0������4��N��ӮR��Y�}� ۗ�� ��@:s�����SM�4x�Kk3��R�H��&l���leI��N�(��O�^���?�]�>V|�����g�ih/5�6�����ųA��Ю�T�y`�=`rqY�_�n��l�-?O��O�����7g�3e� �H'<�H����� �W���X�)l_��pfW�1�Pc�r3��g�:�1�7dq������QE
(��=�J��[����gU7wF����T�<;�cY�FN7��+K��o�!���{ �52�R�ʓ�F�G�n�F�?��%���� �Aw3E|�f�[{a���^Gl�8U=?���I��}O��}�i�2L6ᝲ�0} ��i[����L�� ? Ҵ}&� I���ԯm���� (�g8D�Y�6�����о�kZ]��7���� �4���J�:PG�8���c���;}4��M:�%���%i����[d�#�}N[���PX_�V:�v�Ż�U�rT�\�����&�f�;�F�6��{�4�
�\ǦE�=���	��m|��X�x)����9>��V����>��>�csqa��Ws��-�s��[K��&�MA�iV�w�5BMOF��n��&��K�l��0��% 0 Fy�%s$���,ĝ�~ `�WV�5ΚB4W7	q#�;� `9�1���Tiu�����mŢXA���Zƣ=��/�Xm�D��1g@�w<=mi.����Ս����m��P���mߌq��A�&]-6�M��a�.m���V�,�둑�6y��~��D�tk�;�N�K�yfi��n_�( ��hb�Yҭ�_����c��1	u��1�L���瑳��j]�6���b�uI�.uv?e�A0
��&EۖV�p3Tt�&��\��غu�] ��3O�@r��@8�NsZ��i����mfa���_I��D͖P�-��#q�	��	�������g�˺��ϓ�B��7L��-��泦��|���h4���J�4��,�lN+?K�֓�ŧ��2��;�\\F��l��)�	8 �!��J��4�E-������9*r.Fr~l��GB��;�F�6��{���7��Q�������,�٫��{� f �}��+��]?^k-*m6���P��Q0���\�J�S��zG�>�B�W44�
�\ǦE�=���	��m|��X�x)����9>����3�(��V����]s���'�,nn,7}��ts%�N~P+a�a�[�3;�rY������������<-ׅ�Y�{�Z@�ab. 9�������O�hh_o5�.���}Cٌ{M
m%G�(#����ⱴ��RK.�_FG~�1�K3�I��T�\�A�-�T�U����n�Ux��9#9?6pI����M�(~V�#��x���^[x�GIe�ٓ� ��Tz�tٴ�:�Uז��3��I�m�
��P����=$G�x��J���4�>�]5��Op��3na��O$�T����E֫=ޕg�ȑ���V����A9����:��4M�cS�t�-�V��0!�]�:R�d�=v��7�k�`k�e�_$�ıZo3?��26W�����s�x��G�M��l�m˛f��U���1��dg�~������Sh�E�卾�o�s�;���yMb0H=Ev�Ӭm|{��SE[Ƹ���r\-�����0��;G 6 <�����=�]�T�-�KU�Ȟx�f ��� s�|緥isn������GT6���/gVa���)v�XgaU�9�ju��l�aq��N���Kd����l���u
�#'��<�SO�uΟkh�`������+��̖�9�@`��%��lY�z���gc8C�����d ��~�t�����{�Eb��*-�X���[�.<��5r�P�6�yg�;Y��y�źHv�������N�;/K��������V���f��{�[���vB�!n2xV�+��ֶt�b�rX�v"�����iP�႗��3�S߯5�I''�h��(��(��(��(��(��(��(�P��}�h���_���o��%�Ŝg��UT������j/	Y=՝�ަ�wz���a[o20��'���\��¶'ҥ�񞣥x�n��f�kx�ՊȦg�!�<c���6�3��[v{��6v����m��|�0V��z�	�k[������eG�Q^K���X�	�)F׍��� ��Aa�h�,�̳�H��Kp ���/�x8<}��fgr�K3�{���<FtEI,t�!}a�4�U,��'�p9R=sX�o3m/����uǇ��f���uϕ�'l�=~n��Z�xwJ��/��z,o���o�\�ʭ#daz������]��)���˧�5���n�c�P#9�FN8��x������l$������E��	f-��	�eN8�-���OK��M|�T�������`��b�`烃�'ڮ�_o5�.���}Cٌ{M
m%G�(#�������6��kM2��	�f��1�K3�3a��R=sM��[t�,/��F;m�����9*r.Fr~l��H8�o/�E��֡�0H�٫�"<�����v튭a�h�,�̳�H��Kp ���/�x8<}����5��6�qai�ZI(�Gs�.@�w)���=	#��K�x�芒X�vB�0�;�i��X��O,�r�z��;���wN���u�5Mo�C_Y�p���F*T����� �3�Wc�&�C���c�'�9و;�"� �9��GG�u�ݟ�-o[O��mo��^���E˔R�|��«`s����{�
�[�)�i6��|��=�n��Qi�.���m�77��w:9��'?(�İޭ�j]/�׺\6@XX]Oa#����n�G��0႐Ny ���t�����t,i�����|�bHo5s"�@�{�2�/����9 �Od���t�ִ	�ˆi5	�Ad��2:)���6���p3X��(���G�8��i� el6�.ws�'�*֓�{�%l�,4�������7g��`�d�	��P����#c��PN�$�4P7�QE(�� (�� (�� (�� (�� (�� (�� (�� (�� (�� (�� (�� (�� �Mw�P^h�j�L�0�^��Ā<�?�Dq��oc��� �+�>o��M@4�<q���[�#͗p	�:�94�� �~�qf�[Kk�Q<�d�I%,U�y� �0F3��}7��Zdv=3N�M9ݬ�$cv�T �O$������+_?��� �ʗ�������w}bi�Ui���\, �f��<>�7��'�mU�{�y]�I!�^[x��,�2q�6����'ħE�-��b/����c*�go���r�z�i^5�ҭ��M;O��Mf6��$��ۘ`8S�<�$g�01���,i�����|�a��̋mn���2�/����9 �Os��hm���6�K���P�K%��̦(����Ŵ�	g7���/m'��+r�C3@[�˝�����-�cm�m<s��c���\4������Yc�;���p^�m��cA|�[[It�[��{��7�����EO*! ��U�F���GB��u���u�ZL/a�73����2���a|����z�>8��;W���{�7�K{�D�X�ܹlHf$eMGe�+�;�N���N�m/$�!,ŷ ! ������=�3-�-Z��[�=.�{Hs�\En�`d�����e�iw��4�dWKr��f�d�B>̈�K�8W!�͵y�>$�y$��E�x��O��C���Ϧ�6WS��e�[w\+a�#r�_N)�����qu2m��e��f���qϳ[K}�-�����=j�^�g����ȼ7N�Y������R��� Oz���X_[=���{�����,E[9F�˞��R[k:���5��w����#��A���(�j�����jz�8���G�^��1Ѷ����xz����n�ݪjkp�{�a�@�����^A��Vέ�x~�J�*;y$�Vߟ:F�F8 ��ӳ��4�%�����z*%�R��.�2&�6�N}�(�o������ �At�[���Moj��`xe6���Z`�6��8�qS���a���=��������B�����v����Fj���R�N���*_߳��Xޠm� ���t�'�t�|+��Z�Kh���M%�I .�Dk6T�9�^ t���l��ޭ%�ޭ�c��K�C+o72����g��X\k:�Ӥ����"�6�#,�]B����=$V��t�ۤwX3� g��#4��Ia�0F�%��lk2�W�����gc�y]����s�ݣ���P64�KQ�}���� 2�6��B���	�?'#�Ko��q������W���g��_�ݰ0{��=�Y�o�MѮt��]:�.�Y噧� �~�t�9�t�y����ۋMB�ID�;�0yr+�Ln���I({5�N���zf���f�Z��OK��3���#ep8���`Q�|=��Ӭ�.uַ��8�hVȾ�$��x���=�p,�O{e6�$Q@N�X��V��9s��y=�V�|m�ZCopZ�o1��nDS�?7����Zz_^� ���_Oĝ|���W����y��t�p��x��o1|�{px�U/�C���^E�ZE���^y�����)��-���K�}*�u'�I�g��9���8�@O�j�έ�x~�J�*;y$�Vߟ:F�F8 �{k���k� _#g��	�Ķ�����Ѥ��-�l@�\��8� ��T6>����M=�"�XX���`��b�`烃�'ڍ+ƷzU����i�2���{���A�s
y'����F*�>%:.�l��}���T�#;|͇ �#�4�[	y�l<-ׅ�Y�{�Z@�ab. 9�������O�O�KM3T�����Wɷ��{�Q��5��{T�{h�C$�;g�#:"��:]���0���c*�gh��8�����W�_��.��][,�fiZ�W=�r�l~'#�`]x~�,5-j�(��/&�@���^h�� �Z�Û�kK���_P��c��B�IQ�J��`G�98�v�V�=.<���I�`��l H� ( {�����PX_�V:�v�Ż�U�rT�\�����&��_ր]��#���������.5=�����j�����7֮�_o5�.��M�mCٚ=��v���(a����Y6-��-mmm-�R�3΄���6���|�/�Q��2?���e{�i��[��1�̭��T�r3�7g���� _��W��O��=��n�i��	%ŵ�I�B�g4�Z�er��t���N��h�0�B�����v˩��9R�����|9M�Կn�PH�33�w%��I=����QE QE QE QE QE QE _׿�dԿ��_��
(�*� ^�Η��肊(���(��(��(��(��(��(��(��(��(��(��(��(��(��(��(��(��(��(��(��(��(���
endstream
endobj
17 0 obj
<<
/Length 667       
/Filter /FlateDecode
>>
stream
x�uT�n�0��+x$�J!��B�C�.hO-`���E�"��j���;i;E
�p�̛�3�b'�����}�ή?��0]�uW��V�V��.Zk�z#~ȯ�XyT��o�N9��-�O]�k��;a��t+��"/MQ�5�WU�y+�ʍ\������@�Q7�p�}B������ X?Tj	A5Y?��Mo@�����+ʊL)�x %�������]�p��{"MQ��+�[Mڅ��;<\@�ۀu���ʆ�XǊ*"�y���f�#�.�l��ڗ��m�⁺�����k03�3�a���~�գn�����98��e��|�5�tY]��q;���
sۀ�xT��c�#@[��T������ۋb�<1�>Y(��-�h�S��WT�Z�1��ia.��=�}���a+q�V��y�VG
ͽ�i��rxK����"γ�> ���nb�[e�xF�"5O?�i	x��ѿ���~vRA�kUVҏ���4y���mN�/���y;|p�L�)��׮���H ��'(�q��v�Ҵ���B���� �q�<-��|���¥[�z�����ާu�����t�	.�>�3��@�5ES5b���3�K�"A�6E�HW'���ъ�s�~�M�9����?{AKm���ﯥ�d��U]�
endstream
endobj
14 0 obj
<<
/Type /XObject
/Subtype /Image
/Width 402
/Height 260
/BitsPerComponent 8
/Length 43325
/ColorSpace /DeviceRGB
/Filter /DCTDecode
>>
stream
���� JFIF  ` `  ���Exif  MM *    ;      J�i      R��      ��      >    �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         Brandon  �      ��      ���    97  ��    97  �     �    �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         2017:03:06 22:58:49 2017:03:06 22:58:49   B r a n d o n   ��http://ns.adobe.com/xap/1.0/ <?xpacket begin='﻿' id='W5M0MpCehiHzreSzNTczkc9d'?>
<x:xmpmeta xmlns:x="adobe:ns:meta/"><rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"><rdf:Description rdf:about="uuid:faf5bdd5-ba3d-11da-ad31-d33d75182f1b" xmlns:dc="http://purl.org/dc/elements/1.1/"/><rdf:Description rdf:about="uuid:faf5bdd5-ba3d-11da-ad31-d33d75182f1b" xmlns:xmp="http://ns.adobe.com/xap/1.0/"><xmp:CreateDate>2017-03-06T22:58:49.966</xmp:CreateDate></rdf:Description><rdf:Description rdf:about="uuid:faf5bdd5-ba3d-11da-ad31-d33d75182f1b" xmlns:dc="http://purl.org/dc/elements/1.1/"><dc:creator><rdf:Seq xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"><rdf:li>Brandon</rdf:li></rdf:Seq>
			</dc:creator></rdf:Description></rdf:RDF></x:xmpmeta>
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                            <?xpacket end='w'?>�� C 

		
'!%"."%()+,+ /3/*2'*+*�� C
	
***************************************************�� �" ��           	
�� �   } !1AQa"q2���#B��R��$3br�	
%&'()*456789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz���������������������������������������������������������������������������        	
�� �  w !1AQaq"2�B����	#3R�br�
$4�%�&'()*56789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz��������������������������������������������������������������������������   ? ��s���]�q���qy=���*GG)�6�u,q�V%��5mR%�I�Cs��F[�B���� �W�x��Z\xoQ��Z���O���Z7C��r��s� �<?�ç��M��L�1]6�W��|�&v�>U���F���/�������8��#�����u���E�V�eV���!\nڮ��2:��7�:��o�XA��yh����>Z3���Z�&���i?fզ���2��l�tO,�'2o�����9���<Y�hV�k�k"����q����5�O�D���£�u��՘6~�/��om��p�/s4�IY�f?(��ZZG��f��侴�n�Q,���)a	$,����;Y��>U��ӼQeiy�yd�ஐ�4�Urۥ.6���+���"O�jk�Mb���\Y@�E�2B�ظ�˱���G�zY�'���G�+q%��ޭ,:�ٹX�a�S:��o�yq����>�P�����^�M$}�4+�<�f@;z�8���!Y���wZ�yr�Ks�E�[�2Fp�L�0�9F��G�,lt=.�k�P%����"�M���f
����j�lS��8J�4_E�X�O�O��ʶ�?6%����o:p���·�nml���#��e��IF8����`�v��@�v�������nd�m����	$y�����_n2�4�_��������{w���[��[Xl�D��l��W�rr}3T��Lk�t�Kxv�5���>o�>y���ֵ���+kKSmgsif��[L�Q$W.&`C䜐pG� ��:��^\_���٦�� ~� $9Q��J��xY���j��������5)ݞ6���ڛy�D|.��O���Mw�>�1���8 �v8���Ҷ4�i�XР�Ɗ��.&��%&R�n��9S���:_אu���3�Nӯ<%�����D���bp��͙�w�MҼ#��PE6�o	I��/:�(L�F[`v��F@��e��mt^�{�Md�6�l���j�nRI�d�x����vM'�|<��I�s��H��;�0-$�dH�9�#������<��������&W."Ss��>����I����;���c啚���c��8Ď?�w0�z(���e�h�I�\j-x׺R(�Z��4�|�����+d z�f��s�iQ[4�^Y\\\4�v�iYJr��(����@�BG𮩩�G)��ƱyW�2_ky��� � @�S[�6���ɬ�y`���2_An��7�g�?H�4H<9�Zj7����U��EB�oq�Kg��Pi���'����Y.�ȻP�m͸�*U��1��ߊϾ��ȴ�
����1^�%2,�Ɓ��X�\�\���PXx�z��vv
�\ ѻ\ę���X���gL�=��υ��)������_�t���y���hi�6�m-l���m്���b�36>o�N����5���^��{�Kh!Gt���0�d��C�/����(д�o����ȖV6�4� ��Q �Yʎ���WAm�#�,�2�^��=�˦M�B�<�q�s&���I(�G|V$������Ӭ��qwpn/p�m	�ę����#�^�^��)��Zo�u]Z�ΰ�9n�Ѯ#I%�2|�f&?�қm��B�M�z�h��ʭsyB�ݵ]�ldt�+��4-
�My�d[�Y]�<�:�f���H�C�=��Ts��9tMK��~ͫMqeo��4�0X�Nd�?)%r;�}D�{_�zo��[ElK{��`2v�v���A犷�x~�\�[����G,�[\ǄB�y��=��$v��k�e��-uy�/�cfɧD�a��s&���QG#�.��h����6z����a��o�� �4&e*V8��Ө���d�Z\7�yq~dK+f�f��I����@,�GC�})l<1�jvB���^7��+O<�F[�F`�c��jI��m��e.������FП,I��Y�2>e�+sI񝽮��[��a{�oX��G��,�V!V���q������� 9�O���f���*^y�K��o��_q���sҖ�����f.l��b�0�Ə6���ј4�� d���S�i�$�T�y$��:a
q��T6'8��x՝3�V��.�l�2Y]ifE�uѭn˂�շH��`X�	Z��W����ǃd���˸b�{ail$\�D`33���@�=�!]� ��I�x{�����\Msr��K�<~T�l�R��eAm�/ ��i���(�=��l%j�Z\7�yq~dK+f�f��I����@,�GC�}*O���}���O�y;<��?��zt�~�r]B����i�rn���7�R6��bL���q��/qC���"��z��:���B`��K�c,e��@f�/�z�����f���1#LT���a����Vtk�
��:���ޢ�:�"��:G�M��2�9ǠǽM�x������K�h���j�ͺR�o<�{�t2-|?�]�oAm�,�o!��T���G��)�յ;!ugl��򕧍m�-�0i1��5��k�]���mZk��3+fɧD����s&���I(��ޭ�>3��д�v��/t��������r���*ѐX�2:����Ӽ�j�1^X٫[��8�y�H��s���OaVa�]��]]n�P���5���$���a��{�xˡh�֯<7z|��ҧ�;)R��6�c�T�:��?�'�u�� �����f�v*��1��ߊ�R;)�'�곬���&�p���2�[� � @�j;j���\��#$���{��}�{�F`�c��<u��5��k�N���QK�AH��#�&��T���cެ�!ѕt;�H_-�6��hc�!�2偏�b���Z��~�/��om��p�/s4�IY�f?(��U�|?�]�oAm�,�o!��T���G��+j�Ŷ�j^���o���$�"5_�t�� '>��)�&���i?fզ���2��l�tO,�'2o�����9�z6V���a�m_S�K�;dd�w��qrO��yh�Lt�A玵&���sU�����Z�g1��ObG���e�r{
��|C�*�w���[�m�x��rC"e���+p29��C�&�HҢ�i������i�
�2�� ���S{��4>�����Պpa�&��2 \䖐a�l#wz�+~�T�g���N�5���w��,ێ¥X3�;�{�Xu��@��(��<=gl&��k۸R���[�[!2���v�6�=�<`��@�
����1^�%2,�Ɓ��X�\�\���ZV����� j3>��H�o��Kj�e���v2�=Ld��;�?�66���H&�<�:���җ2y���i[����2��(�#*����d.���}�R��ʹe��f&?���Ӵ��	j��;���8q:��<�q�fA ���Vޙ�Kk}N��{�4�!�=��.]X<�Z2�GC�5��j:>�-u�A.�%@�E�n���x�2�s�A�z͚��4�:��Z���/�NN�' \lِ@=w~Z����ޛ���[�^���@ݱ]�ld}�y�tk�
��:���ޢ�:�"��:G�M��2�9ǠǽM�k�e��-uy�/�cfɧD�a��s&���QG#��nfXx[W������$���G����Z3�>Py�I�x?\�lb���V���q<�����.�oE�´���ʺ�/��Db��41܅�șr���1
��k?P�	��4���h/,�..D;B����9m��=á4>�����Պpa�&��2 \䖐a�l#wz�+~�T�g���N�5���w��,ێ¥X3�;�{�Xu��C���m�υ�Y���w��d��<.��%�o��z��D�o	�z��#�1	��!/����� 9 1�~��i�xZmU��܋�u��,ێ¥YY��A=���k�
��:���ޢ�:�"��:G�M��2�9Ǡǽvd2��~#Ԭ����W�����$�$�8f����H�־�o i`�\uDy�I%)��h�Lw�t:g�t�+;��赼�9T\љ��t�p=�:��Ƕ�E$���6s���kv̯+H�t�6�8$t=h~^�����	���a�m_S�K�;dd�w��qrO��yh�Lt�A玵��]�۫�WY���FU��5!|�� ���,�D˖?��8V�dsO��{�f��?\��ὶ�C�o ��H�$0Ef�`��ӎEbW[g��H�/�\C7�J�K��ͺV��C�ɱ���z\ҵ���w����VİW���!P7lW`[tx�:$SxOS�gY�1�L0�	}�e���� ����^�,tak��q��6M:'�3|��7ş���9��B��Χew��Π��Cd���p���Nq�1�M��a�GS�k�3f��26�H��,Ll� �J[jڝ����W���J�Ə6і�ј4�� d��^h1xb[I��[�� Ixl��Z59H�2�#sq���u4����Ze�N��f��h�{[���u`�h�,G\���kv��q�xcP�N�
�g
�-K�S*ǖ<�$�ỗvv��'��QЬ�V�R��R�R�a"$�"*�92�l��01�����z��	]V=:o�PՒG����ʥT�F�
��![ d�S���������TԄ���;C*���t���B� ����_��m�M&��K��Jb~�j��_�}�	_pe
�������ٺp�����ZG��EXo��Hį�2�bxÌr $�v�����[tz.�-��u�a�J��.��,�G��c�����6����ڿ�%e{_$/���}��Lw�Y�*�ԧn�W��%uX��e��CVI��;C*�R@ip(+�l��\��<<R�׍����pEw:W����=&��K��Ҙ�mh�"�
�����+�c�&������Y���\�`q�ri��O밖ڑ�E QE QE QE QE QE QE QE QE QE QE����j����)}yr-ŭ��AIûH�X��0{�_^^�wJ�t���v��Y�@̎�,a�.v�v���+]{O�� �5�R�$u7�t��O��|�;y�2Fxꆟ�K�M$�F�QA�iK��<�{ⴭ�Y[���Q�_��a�[S�Vv��� )Zx���2�Z3��SXi�u焵[��_��8�LN@�ٳ �z��+oL񥵾��@ӽ��d��kxX.�B���#����5ꖺ�ޠ�z��o"�7H�I�`�W9Ǡǽf�J�v�y�-V��t��''S��.6l� ��
�k��B�M�zh��`�syB�nخ��2>�<�Z:5��k�N���QK�AH��#�&��T���cަе�2�F�����1��dӢx�0��9�|Y�I(��ގ�3,<-��visgl��n�U�#�I���-�I��(<�֤Ӽ�j�1^YY�[��8�I�H��s���OaZZo�te]�R�{��Ao�B�dL�`c����nG5��x���TV�4�W"�ZFVR��6�c��К�M�����	�0�_A .rKH0ݶ��s��c�i��b}'X���`��{xm�aR���A=��
:� ]���[�6���ɬ�y`���2_An��7�g�Ac�E7��=Vu����s���X�y���?OԴ�<-6���wnEغ�khm�aR���� ��T�5��k�N���QK�AH��#�&��T���cއ��a�?�VP]��+�pF�sdT3`FO|�Uk_	�7�4�Z.:�<񤒔��4f&;��3ƺu���R�tZ�X��.	������m8��jq��I"��it��9�{yWF��fW��S�F�:�?/?�[k�� ��װ𶯩٥͝�2I��W��9'����f&:|���Z�w.��ՎN+��|C�*�w���[�m�x��rC"e���+p29��Q��3l��_����Z!��7�^�$i��"��0~P	��"�+���m�Z���!��%r�%ȍW��+?�ϡ����rGsR=.iZ�P��~ނ�+bX+��C���+�-���<U�)�'�곬���&�p���2�[� � @�j���i�:0��渿�y���&���>I̛���IE���}�Z�gS����R�PDR!�GH�I�|�U'8����P��֣��5ՙ�tDyP�$U\�&6p� g�-��5mN�]Y�+����i�G�h�yh�L�\ӯ4�1-��z����� ��6Qʭ��`�T�������:�O���t-2ݧ{�3z�4z=��`\��y
�d#����h`q5�c��<1�j�R�e��f��ܩ�c�r��q� �p�˻;uc����|?��VZ�i�]j)q�@���H��\�T�v��SG@�It_�����èj�#�[GheR�H#nea���2p)�W��X�]^�o�jBSik��@B˺V
��![ d�U�/�v��&�ou%�O�1?f�EX�¾����2�bxÎ�MIe���8_�}�|�#�Y��7�s$bW�B�<a�9 i�_���ŭ��+����m.�e��5!)����ʠ!e�+ea���2p+��E�%��.���:iQt��ye�h�9<�q��l� �����/��O��{k4U�� d�J��(V'�8� Mr}>��Q�Q�W����k��[/�<���ju+C>���+�ǧC-����H�V��T��Hہ@YXd+`�
�+�Ҽwmm��6�r_�&�ěkDQ�W���X�0��	5ZX�np���L�J�^6*�{�ڒ�w���y1�W.�d����^ڔ�}�(� ��( ��( ��( ��( ��( ��( ��( ��( ��(��<=gl&��k۸R���[�[!2���v�6�=�<`��@�
����1^�%2,�Ɓ��X�\�\���ZV����� j3>��H�o��Kj�e���v2�=Ld��;�?�66���H&�<�:���җ2y���i[����2��(�#*����d.���}�R��ʹe��f&?���Ӵ��	j��;���8q:��<�q�fA ���Vޙ�Kk}N��{�4�!�=��.]X<�Z2�GC�5��j:>�-u�A.�%@�E�n���x�2�s�A�z͚��4�:��Z���/�NN�' \lِ@=w~Z����ޛ���[�^���@ݱ]�ld}�y�tk�
��:���ޢ�:�"��:G�M��2�9ǠǽM�k�e��-uy�/�cfɧD�a��s&���QG#��nfXx[W������$���G����Z3�>Py�I�x?\�lb���V���q<�����.�oE�´���ʺ�/��Db��41܅�șr���1
��k?P�	��4���h/,�..D;B����9m��=á4>�����Պpa�&��2 \䖐a�l#wz�+~�T�g���N�5���w��,ێ¥X3�;�{�Xu��C���m�υ�Y���w��d��<.��%�o��z��D�o	�z��#�1	��!/����� 9 1�~��i�xZmU��܋�u��,ێ¥YY��A=���k�
��:���ޢ�:�"��:G�M��2�9Ǡǽvd2��~#Ԭ����W�����$�$�8f����H�־�o i`�\uDy�I%)��h�Lw�t:g�t�+;��赼�9T\љ��t�p=�:��Ƕ�E$���6s���kv̯+H�t�6�8$t=h~^�����	���a�m_S�K�;dd�w��qrO��yh�Lt�A玵��]�۫�WY���FU��5!|�� ���,�D˖?��8V�dsO��{�f��?\��ὶ�C�o ��H�$0Ef�`��ӎEbW[g��H�/�\C7�J�K��ͺV��C�ɱ���z\ҵ���w����VİW���!P7lW`[tx�:$SxOS�gY�1�L0�	}�e���� ����^�,tak��q��6M:'�3|��7ş���9��B��Χew��Π��Cd���p���Nq�1�M��a�GS�k�3f��26�H��,Ll� �J[jڝ����W���J�Ə6і�ј4�� d��^h1xb[I��[�� Ixl��Z59H�2�#sq���u4����Ze�N��f��h�{[���u`�h�,G\���kv��q�xcP�N�
�g
�-K�S*ǖ<�$�ỗvv��'��QЬ�V�R��R�R�a"$�"*�92�l��01�����z��	]V=:o�PՒG����ʥT�F�
��![ d�S���������TԄ���;C*���t���B� ����_��m�M&��K��Jb~�j��_�}�	_pe
�������ٺp�����ZG��EXo��Hį�2�bxÌr $�v�����[�W��X�]^�o�jBSik��@B˺V
��![ d�Q�xߵ�������%6���T,��`��,�2�Nh�|A��7N�_C>�+H��h�����P�Oq�@�,� �����/��O��{k4U�� d�J��(V'�8� M/Q�tz.�-��u�a�J��.��,�G��c�����6����ڿ�%e{_$/���}��Lw�Y����ݺ�>�����u(V[8Vah�]ʙV<��'-�9'�&]�Rk:E��=д��)Z c�n4.�9G-�7/Ԟ�t+-U�Ԯ��ԠXH��$H�ʮL�[;q�g��z/�-����4K9ⶰ��C0f2+}�%����N����	t��O�$:/�WU�N�[�a�5d�쭣�2�U$������V�8�K�3�*�xث)�GWu����K���۾�����TC|��,�X0
Č�r0I�U'�.m59�?�� iJ���@_'%�3<���h{��v� �mMM7��]x{�b�j	�Ka���r�w(E� �p�qU�/�둋t�=RH�+ak���[!a�����d��zO�4�{=K�%ށ$�V��_���1�ĂB�F)�^��Z�z�=���~ηWX�0���2fR�� �ON����������C��MGSԯ!���"���eQ���W�`k
�����B����uy�B��a���ɔ�3���k�',N1��Q�:Q@Q@Q@Q@Q@Q@Q@���io.���帼��I��#�#��śF:�8�+����	����!��^m�-�`�c��k��<_`-.<7��p�-su���TH�f-���9F�9��x_Ş�a������&w���o+��V;n�*��xg#J�ė������R�~_��[x{P��~ޢ�+l��\�C��7mW`[�v��WV�� �@ۼ�k��Iv��-�I��A��m_�촟�j�\_��[�6M:'�|��7�O�IE��{,д+]5絑nmew����y��'�"i����Q�:��fj�?��|7�ֈ`����b������zqȭ-#�ֳi��_Zj�r\(�G�����I~Fݝ��r�*����(����EpWHyp��mҗy�����'��5��&�[F�.,�Y"��!`�\le��^�h#н,����������V�J�ܬq�0Щ��N�7� �<�8�W��g�X�MVh/uH�������O3 �BV����K��Q<�n%�Ң�M��#8G&N�l�Um#Ɩ6:�k5ި�K��D���s�rd��5N�)��%u�/���,t�'�'�}U�[Q���}|�7��	8V��a[�76�R�C��]�2��$�#H�Y}�F;WQ�x�I�t{y���2}��h�T�<�gpv�\}?����]NR�I����o���-�6}�@�6nm��99>��uv�5��[��;M��W�7�<���kZ�������������U�-�F(�+�0!�NH8#��~EK���./̉ecl�Lѐ	?u���xϥZ�<,ڏ�n�_�yrE����^|�����U��s�M�բ>[X��ou���i�Di� z�d|��[W���,hPcEs�L�Jd�)o7`Y���q�?���:� _י�a�iמ�owI`"p�u18y�f̂���^�u�"�O������w&]�-�;�w# U�2�ö��e=榲jU6X��5I7)$�2H<{�e�&�¾hm���9�Z�Vs�y�A2$x�����K�[}g�Mb��Oko+�)��^r�{�B�����~���sU�����Z�g1��ObG���e�r{
ղ״h$Ѯ5�k�)v���YD>a`S�b� =k3P�	��4���h/,�..D;B����9m��_���	g�#�WT��lcX���q/����y�r  u���ws�d�c��]��B/���vIi��3ޟ�j$�-5�H]�*��VI"�I7��̥��A���4�KL���h���v�]��f��f�v*�Θ�r	��g�@��Z_^^�wJ�t���v��Y�@̎�,a�.v�v���,<�=J��;x. hݮbL�J��`@,��Ԋ��x������K�h���j�ͺR�o<�{�4�i���Q��6�Z��Qy1]��7�N��ZvW���]}j/jrY��%���f��K�}���q��hZ\7�yq~dK+f�f��I����@,�GC�}+���F���un�mf��e�&ӡta8�9�|D���^��+]B����i�rn���7�R6��bL���q��/qR�m{�r-7�:��o�XA��yh����>Z3���M����u���E�V�eV���!\nڮ��2:��xSŚ�k����-ͬ��^�o3\d��M!���*9�Q��:&���i?fզ���2��l�tO,�'2o�����9龢F=����7��-��%����0
��b�������[м?c�F-�Tx�I#�H���c�!l<���B���q�;\е�2�F�����1��dӢx�0��9�|Y�I(��ޗEմ�jnu=N�twW0��7��2��d���}At2t-.����2%���M3F@$��@H r���>��յ;!ugl��򕧍m�-�0i1��5$�����N��|�w���#hO�$�~��2�������B�-�w���7�SG���˫��FAb8��z��_����uk�{KU�/<�%�ɷ�c/��	��͎9�Kc�}_R�6v��qi�G�`�yh�L�lh�)Ӵ�M*U��Sy�0�8�y*��n��jΙ�+K]N�[�,���"�:�ַe�r�ۤ`Ѱ,x��������^���c��k����1I=���.D�0���I�G s�ǐ�� �^$�<=�{ۉ��&��Aq���?*a�L��Q���ϗ����4��B�rt�?����t-.����2%���M3F@$��@H r���>���W�]�۾���'ؼ��W_���=:c�Z�.�mo��4�97\]���)B|�&{�v8������t�
j��1Kc;gr�	����a� v�|�犂R��O�mϩ-G���!���r��x/T�/���v/�OsoQ"�2n��\�l��FӜES�<M�Y� aͩ����Y
�o�ZM��,
���ӜW9�]k-9|)��#=��B`���%���2�` 3U��=��i�}A�b�[����d��w��B����j��5K;�E.uE"$t�d���eRs�A�z��KH�|5aa��{gq�y�7��Y�`���"m �dn�ǥu𴷚6�q���qyē��*GF��Y�c�c��[�wP����X��:��{>a\n��|d}��폋��m<7��p�,����U#�����9F�9��h���a�MN{�B�L�t��Y2��Vs&���I(:����V��;4���FI7y*��$�~������O�x�Ri��5[�,�խ�sO$��$q���[�G'��-7�:2��y���ؠ��w!d2&\�1��A·#���<Bnt�*+f��+����Э#+)BA}��p�M��&����ub��|�����9%�n��޹�߱�4��1>��My��]�=�6㰩V�� ��V���(�� (�� (�� ���Y�	�}Z��������L���aݤM�O`=�P/��/|;�j:LFW�IL�,�fG`0�;W;F��֕������ϩj����:Rڧ�n�f���S#<�CO�M���&�	��#N���4��L�x=�ZV�,���̨� 
/�ʰ�ƭ���;ex���<h�mo-�I��A��4�:��Z���/�NN�' \lِ@=w~��x���EӠi���M2f�G��,�V!V���q����f����uK]F�PK�IP7�c�e$�0L����c޳f�k;N��xc�K������6d]߅V����w����VİW���!P7lW`[tx��B��Χew��Π��Cd���p���Nq�1�ShZ��c�]^k��G��ٲi�<a�c�ɾ,���Q��Gp[����;4���FI7y*��$�~������O�x�Ri��5[�,�խ�sO$��$q���[�G'��-7�:2��y���ؠ��w!d2&\�1��A·#���<Bnt�*+f��+����Э#+)BA}��p�M��&����ub��|�����9%�n��޹�߱�4��1>��My��]�=�6㰩V�� ��V�����ws�d�c��]��B/���vIi��3ޠ��"��z��:���B`��K�c,e��@f���Zd��G�d��"�]C5�6㰩VVt�c�O~*m�B��Χew��Π��Cd���p���Nq�1�C݂�����+(.����v��2	*� �#'�R*������X-�Qx�IJ}�3���]��]:���)a�-o�NU�tfl|�6�N�8����B�4�}͜󽼫�Zݳ+��)�#��b	Z���-��� �y�k�x[W������$���G����Z3�>Py�d��vv��'�i�!ѕt;�H_-�6��hc�!�2偏�b������~�/��om��p�/s4�IY�f?(��X������-K�wW�� �d��F��n�������rlw9#���4�|?�]�oAm�,�o!��T���G��*Ŏ����Y�Gxb�8B_kc-� r  c5B״�Z��\_�<��͓N���$�M�g�$��Gz�F�Э|3��_��)s�")�#�{$�>c*��z{�b(XxkQ����ٺ"<���@�*�K8l 3Җ����d.���}�R��ʹe��f&?��iך^��k�F���� �^(�V�NR0L�@���rB� w�M'�v���nӽ�b�=��.]X<�Z2�GC�408�ݱ��w��5S�B��³DR�Tʱ�9l��8� A8n�ݝ�����t��t+-U�Ԯ��ԠXH��$H�ʮL�[;q�g���u^��/�WU�N�[�a�5d�쭣�2�U$������V�8�+����m.�e��5!)����ʠ!e�+ea���2p*��[mI����'Ҙ��Z��W�_|BW�B�<a�p&�����n�/來}>V����V�9�1+��X�0��	4ݯ�m�b����Kg�]Go�tҢ鋨��6��ry�5F��};�>����	Y^���d�_~y����}J��)ۡ��	]V=:o�PՒG����ʥT�F�
��![ d�W-,O����b���]Ε�kmI����)4�$�Z"��¾�į�0
��� I�"�w���y1�W.�d��o����%��tQE QE QE QE QE QE QE QE QE QE QE u�燬�ھ�{w
_^\�qkd&PRB0��&�'�����W��ҵ&#+ݤ�E�x�3#�b����q��J�^��?�FgԵI�M��)mS�_3 ��^A����z��������I�t���TPrR�&O<��+V��fT��eXxcV��՝��o��V�4y��������� ��v�y�-V��t��''S��.6l� ��
��<imo���4�ay��3G���˫��FAb8��z�t�GC�ú���w�%ޤ�ȱ��2�o&U�q�1�Y�R����^xKU�1�%���É������2��«Z�P��~ނ�+bX+��C���+�-���<V��}�Z�gS����R�PDR!�GH�I�|�U'8����-{L�х��5��#�o��4�0�1�Nd�~RJ(�w��-��j���\��#$���{��}�{�F`�c��<u�4�뚭�W�Vj��9�'�x�8���-裓�V���WC�ԅ���lP[Ɔ;��.X�f �[���g�!7:F��M����H�hV���� ���⇸t&��w�xauu��Bn>D��F@���7m�n�\�o��l��I�&����.���q�T�t�c�O~+���`�tV����k1�X.�����G�ۻ$�����PX�M�=OU�dw��!0\Ä%���2�` 3O��-2OM��]ۑv.����q�T�+:c��'�6�}�Z�gS����R�PDR!�GH�I�|�U'8�����l�Xx�z��vv
�\ ѻ\ę���X���Z��z��,��Ψ�<i$�>���I��A��L�egc�����'*��b�36>n�N��Z�x��H�d�]>��y��Uѭnٕ�iF�������� ����<���<-��visgl��n�U�#�I���-�I��(<�ֲ]˻;uc����4��ʺ�/��Db��41܅�șr���1
��i��o}�?��|7�ֈ`����b������zqȬJ�l�[i�ừ�f� �\�Ir#U��J��s�{�6;���ԏK�V��.�߷���ؖ
�7��d*��c#��b�D�o	�z��#�1	��!/����� 9 1���k�e��-uy�/�cfɧD�a��s&���QG#�C�_hV��������l��=�n1�I�==�,<5��vMufl�FF� IW%���6 �Ka�[S�Vv��� )Zx���2�Z3��W4��/Ki5ޣk}t� �/�r�F�)&U dnn9!�Φ��;{]L�i���LޱM�kxX.�B���#��Mn��n;�j�ԡYl�Y��)w*eX�ǀ��@�r  �7r���X��b�_�:����jWZ�\jP,$Ad�$AeW&U-���3���:�R]�+�ǧC-����H�V��T��Hہ@YXd+`�
~��C~�6�W��Ꚑ��Z�heP�����V�8wK�ݭ�����I�LO٭QV+�!+��X�0� �RY|A��7N�_C>�+H��h�����P�Oq�@�n���� 1kc;J�!�kK��m�MHJm-c�2�YwJ��@YXd+`�
���u	l�����T]1uYf�8�O#f�/�0f���K�g��i��a�Ù#�����1� �\��O���g�~���++��!|�����=:c�Z�J�Ϯ�E�J����,:���=��v�U*���6�PV
�'�J����[hzM�ܗ�I�1&��E~��%}��V'�8� MV�'[�4�<<R�׍����pE6����n��Lo�˶'&��W��;_@��)�(�� (�� (�� (�� (�� (�� (�� (�� (�� ���Y�	�}Z��������L���aݤM�O`=�P/��/|;�j:LFW�IL�,�fG`0�;W;F��֕������ϩj����:Rڧ�n�f���S#<�CO�M���&�	��#N���4��L�x=�ZV�,���̨� 
/�ʰ�ƭ���;ex���<h�mo-�I��A��4�:��Z���/�NN�' \lِ@=w~��x���EӠi���M2f�G��,�V!V���q����f����uK]F�PK�IP7�c�e$�0L����c޳f�k;N��xc�K������6d]߅V����w����VİW���!P7lW`[tx��B��Χew��Π��Cd���p���Nq�1�ShZ��c�]^k��G��ٲi�<a�c�ɾ,���Q��Gp[����;4���FI7y*��$�~������O�x�Ri��5[�,�խ�sO$��$q���[�G'��-7�:2��y���ؠ��w!d2&\�1��A·#���<Bnt�*+f��+����Э#+)BA}��p�M��&����ub��|�����9%�n��޹�߱�4��1>��My��]�=�6㰩V�� ��V�����ws�d�c��]��B/���vIi��3ޠ��"��z��:���B`��K�c,e��@f���Zd��G�d��"�]C5�6㰩VVt�c�O~*m�B��Χew��Π��Cd���p���Nq�1�C݂�����+(.����v��2	*� �#'�R*������X-�Qx�IJ}�3���]��]:���)a�-o�NU�tfl|�6�N�8����B�4�}͜󽼫�Zݳ+��)�#��b	Z���-��� �y�k�x[W������$���G����Z3�>Py�d��vv��'�i�!ѕt;�H_-�6��hc�!�2偏�b������~�/��om��p�/s4�IY�f?(��X������-K�wW�� �d��F��n�������rlw9#���4�|?�]�oAm�,�o!��T���G��*Ŏ����Y�Gxb�8B_kc-� r  c5B״�Z��\_�<��͓N���$�M�g�$��Gz�F�Э|3��_��)s�")�#�{$�>c*��z{�b(XxkQ����ٺ"<���@�*�K8l 3Җ����d.���}�R��ʹe��f&?��iך^��k�F���� �^(�V�NR0L�@���rB� w�M'�v���nӽ�b�=��.]X<�Z2�GC�408�ݱ��w��5S�B��³DR�Tʱ�9l��8� A8n�ݝ�����t��t+-U�Ԯ��ԠXH��$H�ʮL�[;q�g���u^��/�WU�N�[�a�5d�쭣�2�U$������V�8�+����m.�e��5!)����ʠ!e�+ea���2p*��[mI����'Ҙ��Z��W�_|BW�B�<a�p&�����n�/來}>V����V�9�1+��X�0��	4ݯ�m�b��v��C~�6�W��Ꚑ��Z�heP�����V�8i^7�ciu{-���	M��v�U.�X0(+�l��Z6_`��Ӆ���ϧ��=��*��2F%}��+�c�&�/�0f���K�g��i��a�Ù#�����1� �K�~���Kg�]Go�tҢ鋨��6��ry�5F��};�>����	Y^���d�_~y����}%{j7n�W��%uX��e��CVI��;C*�R@ip(+�l��\��<<R�׍����pEw:W����=&��K��Ҙ�mh�"�
�����+�c�&������Y���\�`q�ri��O밖ڑ�E QE QE QE QE QE QE QE QE QE�����;�-[���d�̑R8�9H�Y�c�c��,<1�j��,`�NX"����2�Z&?���C�����z�b�7_jxD��bѺ��s�l�\��Y��=��o>�gy����[�a3��1����r4��I|� ����/����ŷ���7��-���*���0
�v�v���x�i��uk:����F��$�h��ј4�� dJ��5�.�I�6�5�����dӢx�`G�9�|D���Q��W�)��B��^{Y��W{�/N���2~R&��h���Ff����~���{mh���A{���*H`��0��@'����<-k6�o%���w%d}=AKI!d��m��ͷ)�^xn��+K��$Wt���
���)q��x=�]���x~�Pk]Rk�o2���(�ђ���]����=�ͱ=�Z?[�-l��iaԮ����
�Y��x`��C��}/��z���d�f��T�i ��a�_,����2��!�l��
�X-d���˖�[�*(���y�3�rd���5V�<icc��v�]�,D�~�Jmow;0W&N� �T�b����WY��*-R�L�}Bxg�^U����/��͓x)Г�l.���ske-�0��ݓ-�2H21Č���c�u���7G���퐋s'�l���H5@I#�fpGo*�q�����������-��۽>���2��g�$�f�ڼ��隧W`:cX_��[ô٬%|��|���N��ֵ��o�Y[ZZ�k;�K5_"�db�"�q0�$䃂8 �(�Qд�o����ȖV6�4� ��Q �Yʎ���U�3�ͨ�f�U�W�$[��o����iN��X�>���Z#�u��6�P�k�A���dF�����G̾���x�M�ƅ�4W0XD�q4�A)2��v�!ʜ�����������y��v�y�-V��t��''S��.6l� ��
n��gZ�)��xJḺy�qBe�2��,r2]�/�;k���S�jk&��Se�n#T�r�L�$�3�ǽv^�i<+���O=c�E�E`�1ؗ��i$"G��o��t�u���~�/�����2�q����)���,OO�x����5[�,�խ�sO$��$q���[�G'��[-{F�M�Qkƽ�r�Gh�����C�>f �[ ֳ5��#J�٦������C�+H��P��F�lqG��Z �z?�uMN�9L��5�ʸ���[͌�� Z����w>Mf;��?�!���wd��a��#=��F��A��R�Q�ԅޢ��d�*�x;��[8��z�OԴ�<-6���wnEغ�khm�aR���� ��P�}��E��U��t�GI���i)�e�4�����j�h�:���~#Ԭ����W�����$�$�8f����H�:g�쬮|-$�NF��n6��ۥ.6���+CN�ike�]o�m��ٙ��t�{�u�e�ᨵ����֧%��2[A
;�no!��'�
�|g(<�F���~ח�D���i�h����	�Tt<gҺoi�gQ����i�&]2m:A����7�O�IE�;�%�-���g&닻�q{�#hO�$�~��2�*�ױN�"�|3����u��w��qI.ѓ�0i1��>��ojZo��[Em�Uk��`2����c#�<�]7�<Y�hV�k�k"����q����5�O�D���£�uȣ�k�]���mZk��3+fɧD����s&���I(��ޛ�$c��P��~ނ�+bX+��C���+�-���<U���:�b�5G�T�9d��Z�<"��Xm$)�#��^�,tak��q��6M:'�3|��7ş���9�t][@�����Q���wGus�s~��y�3)Pz��ON�G�C'B��kˋ�"YX�4�4dO�D�g*:3�Ka�[S�Vv��� )Zx���2�Z3��RMkm��t�)w�wpn/N�6��bL���q��/q[�O���t-2ݧ{�3z�4z=��`\��y
�d#����h����ZxgV�K7��YR���\L�v2��p���㞔�>��+1sgl���4y�������� �Ə�;L�$ҥ[� �7�Q�S�'���py9�����2���t�e����K2,��kv\.��FǀH�z�� �����<f<&��^]����Ka"�J#��䟔r9�y
��%�M3��������k��_���dʐ\�*l�x �]�H�('!GA�C��a+WB��kˋ�"YX�4�4dO�D�g*:3�PZee�}��o�}����u����Ӧ;�������N��u������'�g�Wc���{��Ak��B�M�zh��`�syB�nخ��2>�<�O��ƭ���;ex���<h�mo-�I��A�M^�,tak��q��6M:'�3|��7ş���9���;{]L�i���LޱM�kxX.�B���#���v�y�-V��t��''S��.6l� ��
�����d.���}�R��ʹe��f&?������uK]F�PK�IP7�c�e$�0L����c޴t����Ze�N��f��h�{[���u`�h�,G\��:�埇��=��H"�PKsu���c.�8�\�#֯��6���ɬ�y`���2_An��7�g��i:��l��Yo-.l���&I���At�A��9銏OԴ�<-6���wnEغ�khm�aR���� ��P�a�|�X�M�=OU�dw��!0\Ä%���2�` 3Q�x[W������$���G����Z3�>Py�]ѯ�+_�vW�z�\��D6H��7�ʤ���gM�����jB�otA�(-�C�Y��,3p���枂�ͳ�~���{mh���A{���*H`��0��@'���k��B�M�zh��`�syB�nخ��2>�<�[V~-��R����3ĮY$���ۥg�9�=�M�5�.�I�6�5�����dӢx�`G�9�|D���Q��SѲ����j���\��#$���{��}�{�F`�c��<u�4�뚭�W�Vj��9�'�x�8���-裓�V���WC�ԅ���lP[Ɔ;��.X�f �[���g�!7:F��M����H�hV���� �����]	��]��]]n�P���5���$���a��9[�:��?�'�u�� �����f�v*��1��ߊ�����:Q@~���;a6��^�ח"�Z�	���;�������*�U��t�GI���i)�e�4�����j�h�:ҵ״� ��Q��-R@�S}�J[T�-���#���A�c$g�ިi�)������A0]!�i����	���+J�ŕ�� ���E�Vյ;!ugl��򕧍m�-�0i1��55���^xKU�1�%���É������2��¶��[[�t;�^i�A������r���*ѐX�2:���#Q����k���	w�*�,ct����	�s�z{�lԭa�iמ�owI`"p�u18y�f̂��־�.�߷���ؖ
�7��d*��c#����_hV��������l��=�n1�I�==�m^�,tak��q��6M:'�3|��7ş���9��s2��ھ�f�6v��&�%^�8�o��ј4����jM;���c啚���c��8Ď?�w0�z(������FU��5!|�� ���,�D˖?��8V�dsY���MΑ�El�Ayeqqp�!��ee(A�#o�8��	��]��]]n�P���5���$���a��9[�:��?�'�u�� �����f�v*��1��ߊ�����:��n�|,��w��(C%��v��- ��F{�:$SxOS�gY�1�L0�	}�e���� �����KL���h���v�]��f��f�v*�Θ�r	��M�_hV��������l��=�n1�I�==�{�[!���eݝ�� 4n�1&A%A�0 d���EV��yK��3�#�I)O�#F`�c��k��<k�YY��,7E�൉ʢ����͏��Ӂ��֧=��(Y&�O���w��tk[�eyZE;�`Ѱ,A�#��C��� �%��_�O?�{j���\��#$���{��}�{�F`�c��<u��r���X��b��7�:2��y���ؠ��w!d2&\�1��A·#�}5�C6���������.y�bF��!�+0,�� ��r+��?�E�xn����W,�\��~mҳ�����M��$w5#�敯���7��-��%����0
��b�������X��"��z��:���B`��K�c,e��@f��Z��c�]^k��G��ٲi�<a�c�ɾ,���Q��P�����u;+��E.uE"$t�d���eRs�A�zlEj:��]Y�7DG���EU�bcg�zR�xcV��՝��o��V�4y��������� ��:�A���Mw���]?�K�e�ѩ�F	�H��H_������B�-�w���7�SG���˫��FAb8��z�[�>�����u(V[8Vah�]ʙV<��'-�9'�'ܻ��V98������e�j���֢��	Y$�YU�ɕKgn1���4t�ԗE�J����,:���=��v�U*���6�PV
�'��xߵ�������%6���T,��`��,�2�N]��wkm�i6�R_��S�kTU��+�J��(V'�8� $Ԗ_`��Ӆ���ϧ��=��*��2F%}��+�c�&��� ���Z���u	l�����T]1uYf�8�O#f�ր�O���g�~���++��!|�����=:c�ZϩW��;t:��+�ǧC-����H�V��T��Hہ@YXd+`�
奉���v�lU��#�+�Ҽwmm��6�r_�&�ěkDQ�W���X�0��	5�\N�7R�&7������M�Z]��Ԏ�(��(��(��(��(��(��(��(��(��(��(��\�����Wկn�K�ˑn-l��
HF�D��� ���*��úV���e{��Ȳ�dvcAs�s�n?�iZ����A����� {��ӥ-�}���`��� �1�3��T4� ��^�bi �.��4�CJ\����o���� �ʏ����jڝ����W���J�Ə6і�ј4�� d��Nӯ<%�����D���bp��͙�w�[zg�-��]:��/4� �h�{[���u`�h�,G\�n���p�wT��n��ԕy1�FRM�ʹ�==�6jV�Ӵ��	j��;���8q:��<�q�fA ���Uk_�zo��[ElK{��`2v�v���A��ѯ�+_�vW�z�\��D6H��7�ʤ���6��i�:0��渿�y���&���>I̛���IE��w��a�m_S�K�;dd�w��qrO��yh�Lt�A玵&���sU�����Z�g1��ObG���e�r{
��|C�*�w���[�m�x��rC"e���+p29��C�&�HҢ�i������i�
�2�� ���P����.�o.��V(M��Ț��s�ZA�����뜭�SM���:�א?��S���n;
�`Θ�r	��`Q�������w>Mf;��?�!���wd��a��#=�)�'�곬���&�p���2�[� � @�i�~��I�i�}VK�r.��3[@�n;
�egLv9��ѯ�+_�vW�z�\��D6H��7�ʤ���=�-����R�����^�7k�� ���2{�u"�Z�OY�����p��$����0i1�h5��5Ӭ��b����Z��QpLWFf���i����S��I,�K����;�ʺ5��2��"��0h� ������y� ��_/�'�ֽ���}N�.l푒M�J��q�>߽�0i1���:�K�wgn�rp1]f��WC�ԅ���lP[Ɔ;��.X�f �[���>��g��r� O�������1#LT���a��ON9�]m��m"Լ7uq��+�I.Dj�6�Y�N}|W&�s�;���sJ����ޛ���[�^���@ݱ]�ld}�y�X�M�=OU�dw��!0\Ä%���2�` 3W�-{L�х��5��#�o��4�0�1�Nd�~RJ(�w�tk�
��:���ޢ�:�"��:G�M��2�9Ǡǽ6"����Nɮ�͛�#��ڄ	"��1���=)l<1�jvB���^7��+O<�F[�F`�c��j�y���m&��mo���%᲎Uh��#ʤ���$/�y��|gok�i��;�^��)���o�Ճ�U� �dt=sC����y�CU:�+-�+0�E.�L�X�����@��]�۫�WK��GB��5[MJ�QK�J��,�D�,���ʥ����z�:U�K��%uX��e��CVI��;C*�R@ip(+�l��OҼo�����[}SR�KX��]Ұ`PV
�'��~;���4�{�/�})��5�*�~��%}��+�w jK/�0f���K�g��i��a�Ù#�����1� �M�� ���-lgi^7�ciu{-���	M��v�U.�X0(+�l��\�z.�-��u�a�J��.��,�G��c��ce���8_�}�|�#�Y��7�s$bW�B�<a�9 k���6����ڿ�%e{_$/���}��Lw�S�Z���	]V=:o�PՒG����ʥT�F�
��![ d�W)]ޕ�kmI����)4�$�Z"��¾�į�0
��� I����s��'�g�U��VS؎�ԗ��Գɍ�v��$��u*�ԧk�QE1Q@Q@Q@Q@Q@Q@Q@Q@Q@~���;a6��^�ח"�Z�	���;�������*�U��t�GI���i)�e�4�����j�h�:ҵ״� ��Q��-R@�S}�J[T�-���#���A�c$g�ިi�)������A0]!�i����	���+J�ŕ�� ���E�Vյ;!ugl��򕧍m�-�0i1��55���^xKU�1�%���É������2��¶��[[�t;�^i�A������r���*ѐX�2:���#Q����k���	w�*�,ct����	�s�z{�lԭa�iמ�owI`"p�u18y�f̂��־�.�߷���ؖ
�7��d*��c#����_hV��������l��=�n1�I�==�m^�,tak��q��6M:'�3|��7ş���9��s2��ھ�f�6v��&�%^�8�o��ј4����jM;���c啚���c��8Ď?�w0�z(������FU��5!|�� ���,�D˖?��8V�dsY���MΑ�El�Ayeqqp�!��ee(A�#o�8��	��]��]]n�P���5���$���a��9[�:��?�'�u�� �����f�v*��1��ߊ�����:��n�|,��w��(C%��v��- ��F{�:$SxOS�gY�1�L0�	}�e���� �����KL���h���v�]��f��f�v*�Θ�r	��M�_hV��������l��=�n1�I�==�{�[!���eݝ�� 4n�1&A%A�0 d���EV��yK��3�#�I)O�#F`�c��k��<k�YY��,7E�൉ʢ����͏��Ӂ��֧=��(Y&�O���w��tk[�eyZE;�`Ѱ,A�#��C��� �%��_�O?�{j���\��#$���{��}�{�F`�c��<u��r���X��b��7�:2��y���ؠ��w!d2&\�1��A·#�}5�C6���������.y�bF��!�+0,�� ��r+��?�E�xn����W,�\��~mҳ�����M��$w5#�敯���7��-��%����0
��b�������X��"��z��:���B`��K�c,e��@f��Z��c�]^k��G��ٲi�<a�c�ɾ,���Q��P�����u;+��E.uE"$t�d���eRs�A�zlEj:��]Y�7DG���EU�bcg�zR�xcV��՝��o��V�4y��������� ��:�A���Mw���]?�K�e�ѩ�F	�H��H_������B�-�w���7�SG���˫��FAb8��z�[�>�����u(V[8Vah�]ʙV<��'-�9'�'ܻ��V98������e�j���֢��	Y$�YU�ɕKgn1���4t�ԗE�J����,:���=��v�U*���6�PV
�'��xߵ�������%6���T,��`��,�2�N]��wkm�i6�R_��S�kTU��+�J��(V'�8� $Ԗ_`��Ӆ���ϧ��=��*��2F%}��+�c�&��� ���Z��Ҽo�����[}SR�KX��]Ұ`PV
�'�+����m.�e��5!)����ʠ!e�+ea���2p+F��ٺp�����ZG��EXo��Hį�2�bxÌr $�e���8_�}�|�#�Y��7�s$bW�B�<a�9 iz����u	l�����T]1uYf�8�O#f�ր�O���g�~���++��!|�����=:c�ZϤ�mF��ݱ��w��5S�B��³DR�Tʱ�9l��8� A+�x~�\�[����G,�[\ǄB�y��=��$v���GB��5[MJ�QK�J��,�D�,���ʥ����z��F�|?��f{_�j6������o���	�v�Վ2zt�����W(G�iP�~�Q��+�e�2����YTl r�U�s�®��>'�Эc��]^x��}F��mre#���� Z�I��d�u�EPEPEPEPEPEPEPEPEPc�xZ[˸�4�yn/'��2EH�H�#qf�Q���3�İ�ƭ�Bd��)9`�nbW�h�yhX4�� d���K��0\5�\�}��U#��F�r7��Q�}pD�g��t�{i��I��+����9o���ۢ��ʣ���ҷ�%�����T����s��.�߷����,��7��d+��U��G@y❦�gUխ��#�6�-�4�]�'�F`�c��}+[D���-'�ڴ��fV�͓N���$�M��QG#�^�4-
�My�d[�Y]�<�:�f���H�C�=��Ts��9�����������.y�bF��!�+0,�� ��r+KH��}��֚�ܗ
%���,!$��_��gk6ܧʽy�w�,�/</,�\�F�*�[t���y���v6z�I��MA�uI�VѼˋ(H�� FHX;v>���/K6���9h�n$���ե�R�7+b�4*agS�M�;!3U����:a�U��R)��/���|�����oP���+9`����TO.[�nt��Sky�H�ɓ�(�[H񥍎����w����dQ)�����\�:`�r�S��v��	]f�ਵK2I�	�UyV�Cg�ľ__6M�BN��cXV��ͭ����db�vL�0� ��2_l���h.�t����B-̟m���9 �$�5������W�O����S���on����x|�k�h�:���j�NNO�j�]��a|n��o�f������=:c�Zֲ�emijm��m,�|�i��$����|����8��GB��kˋ�"YX�4�4dO�D�g*:3�V��6�᛽W�^\�o�=���<F��;���`z�So5h����)���B���F1�g ��2�Vƕ�m7K��\�a%�ҙ��[��@�*p7�sGO�������cXi�u焵[��_��8�LN@�ٳ �z��)�W�u�j����)32��]�	�h�l����wL�������Oy�����M�1��RM�I3� ���xnɤ𯇚i<��q��\�b^F��L�8d}�{����ǟY�SX��������JnbW����i=>@y⟧x?\�lb���V���q<�����.�oE�µl��	4k�E��A�E�+CtF��X����l�Z��<Bnt�*+f��+����Э#+)BA}�����hY�H��5;��2[�/*�FK�o62�`�jk���Y5��,|�P�K�#��ݒZA�� `�������5KMF�Rz��c�H�RM��3)l��c=�?R�$��>�%ݹb���Y��J���;�{�C���:���W��ҵ&#+ݤ�E�x�3#�b����q����R�����^�7k�� ���2{�u"��'�����9;9�ګ�n����<��;��m���rAtM����^LWff���Ӂ��֝�����_C���Z��ot�m(���x(v�|�����^\_���٦�� ~� $9Q��J�-�Q���F[��Y���tɴ�]�N6�d�?)%��ėP���tu���.�����>X�=��d|��T��^�;\�M�Ϋ�[��G m�Z5�i$�FO������ �Sm�=�]i�oQm�YU�o!��W���-�����t��f��Z�=��sk+�Ǘ�[��?)HwǴ
�q�g"����vZOٵi�/�̭��&��>I̛�'�$��Gzo���k��B�M�zh��`�syB�nخ��2>�<�V�/�둋t�=RH�+ak���[!a�����d��4-{L�х��5��#�o��4�0�1�Nd�~RJ(�w��um���ڛ�F�S����61�����̥A��=:uP]�K���./̉ecl�Lѐ	?u���xϥ-��5mN�]Y�+����i�G�h�yh�L�I5�����Ӭ��=����;H��3߫1�G̽�ni>3��д�v��/t��������r���*ѐX�2:��� _��=i�Z�,���eK�3�q2m����9�`s�c�zR��_WԬ�͝�<l\Fx���2�Z3��[?�t�3D�J�o$�T�uGL!N0�J����������x���Eӭ��K+�,ȰN�5��p\���4l#��C�����W��u��l���ywRB�l--���(�f`3�~Q���+��4�x^��{����nP\ig�ʘm�*As�l�-��� x#�v#0P�����-��]K���./̉ecl�Lѐ	?u���xϥAi����}��}�	�/'g����3�N��֮K�[[�::�M�w��
FП,I��]�2>e�({����7��-��%����0
��b�������j���/|;�j:LFW�IL�,�fG`0�;W;F��Ӵ-{L�х��5��#�o��4�0�1�Nd�~RJ(�w�L�=��υ��)������_�t���y����t��a�[S�Vv��� )Zx���2�Z3��SXi�u焵[��_��8�LN@�ٳ �z��+oL񥵾��@ӽ��d��kxX.�B���#����5ꖺ�ޠ�z��o"�7H�I�`�W9Ǡǽ
�v�y�-V��t��''S��.6l� ��
�k��B�M�zh��`�syB�nخ��2>�<�Z:5��k�N���QK�AH��#�&��T���cަе�2�F�����1��dӢx�0��9�|Y�I(��ގ�3,<-��visgl��n�U�#�I���-�I��(<�֤Ӽ�j�1^YY�[��8�I�H��s���OaZZo�te]�R�{��Ao�B�dL�`c����nG5��x���TV�4�W"�ZFVR��6�c��К�M�����	�0�_A .rKH0ݶ��s��c�i��b}'X���`��{xm�aR���A=��
:� ]��QE QE QE����j����)}yr-ŭ��AIûH�X��0{�_^^�wJ�t���v��Y�@̎�,a�.v�v���+]{O�� �5�R�$u7�t��O��|�;y�2Fxꆟ�K�M$�F�QA�iK��<�{ⴭ�Y[���Q�_��a�[S�Vv��� )Zx���2�Z3��SXi�u焵[��_��8�LN@�ٳ �z��+oL񥵾��@ӽ��d��kxX.�B���#����5ꖺ�ޠ�z��o"�7H�I�`�W9Ǡǽf�J�v�y�-V��t��''S��.6l� ��
�k��B�M�zh��`�syB�nخ��2>�<�Z:5��k�N���QK�AH��#�&��T���cަе�2�F�����1��dӢx�0��9�|Y�I(��ގ�3,<-��visgl��n�U�#�I���-�I��(<�֤Ӽ�j�1^YY�[��8�I�H��s���OaZZo�te]�R�{��Ao�B�dL�`c����nG5��x���TV�4�W"�ZFVR��6�c��К�M�����	�0�_A .rKH0ݶ��s��c�i��b}'X���`��{xm�aR���A=��
:� ]���[�6���ɬ�y`���2_An��7�g�Ac�E7��=Vu����s���X�y���?OԴ�<-6���wnEغ�khm�aR���� ��T�5��k�N���QK�AH��#�&��T���cއ��a�?�VP]��+�pF�sdT3`FO|�Uk_	�7�4�Z.:�<񤒔��4f&;��3ƺu���R�tZ�X��.	������m8��jq��I"��it��9�{yWF��fW��S�F�:�?/?�[k�� ��װ𶯩٥͝�2I��W��9'����f&:|���Z�w.��ՎN+��|C�*�w���[�m�x��rC"e���+p29��Q��3l��_����Z!��7�^�$i��"��0~P	��"�+���m�Z���!��%r�%ȍW��+?�ϡ����rGsR=.iZ�P��~ނ�+bX+��C���+�-���<U�)�'�곬���&�p���2�[� � @�j���i�:0��渿�y���&���>I̛���IE���}�Z�gS����R�PDR!�GH�I�|�U'8����P��֣��5ՙ�tDyP�$U\�&6p� g�-��5mN�]Y�+����i�G�h�yh�L�\ӯ4�1-��z����� ��6Qʭ��`�T�������:�O���t-2ݧ{�3z�4z=��`\��y
�d#����h`q5�c��<1�j�R�e��f��ܩ�c�r��q� �p�˻;uc����|?��VZ�i�]j)q�@���H��\�T�v��SG@�It_�����èj�#�[GheR�H#nea���2p)�W��X�]^�o�jBSik��@B˺V
��![ d�U�/�v��&�ou%�O�1?f�EX�¾����2�bxÎ�MIe���8_�}�|�#�Y��7�s$bW�B�<a�9 i�_���ŭ�:=P��P���0�E�Q�m����1�j�h	���}F}G�_�������l���Ӧ;����{jS�C��|��zt2����$�em��J� 4����B� ���ZX�	�)Wk��YOb8"��+�v���ow%�RiLI��E_�}�_p`��1� �\E��su,�c|�]�8�94�ŧ��KmH袊 (�� (�� (�� (�� (�� (�� (�� (�� (�� (�� ���Y�	�}Z��������L���aݤM�O`=�P/��/|;�j:LFW�IL�,�fG`0�;W;F��֕������ϩj����:Rڧ�n�f���S#<�CO�M���&�	��#N���4��L�x=�ZV�,���̨� 
/�ʰ�ƭ���;ex���<h�mo-�I��A��4�:��Z���/�NN�' \lِ@=w~��x���EӠi���M2f�G��,�V!V���q����f����uK]F�PK�IP7�c�e$�0L����c޳f�k;N��xc�K������6d]߅V����w����VİW���!P7lW`[tx��B��Χew��Π��Cd���p���Nq�1�ShZ��c�]^k��G��ٲi�<a�c�ɾ,���Q��Gp[����;4���FI7y*��$�~������O�x�Ri��5[�,�խ�sO$��$q���[�G'��-7�:2��y���ؠ��w!d2&\�1��A·#���<Bnt�*+f��+����Э#+)BA}��p�M��&����ub��|�����9%�n��޹�߱�4��1>��My��]�=�6㰩V�� ��V�����ws�d�c��]��B/���vIi��3ޠ��"��z��:���B`��K�c,e��@f���Zd��G�d��"�]C5�6㰩VVt�c�O~*m�B��Χew��Π��Cd���p���Nq�1�C݂�����+(.����v��2	*� �#'�R*������X-�Qx�IJ}�3���]��]:���)a�-o�NU�tfl|�6�N�8����B�4�}͜󽼫�Zݳ+��)�#��b	Z���-��� �y�k�x[W������$���G����Z3�>Py�d��vv��'�i�!ѕt;�H_-�6��hc�!�2偏�b������~�/��om��p�/s4�IY�f?(��X������-K�wW�� �d��F��n�������rlw9#���4�|?�]�oAm�,�o!��T���G��*Ŏ����Y�Gxb�8B_kc-� r  c5B״�Z��\_�<��͓N���$�M�g�$��Gz�F�Э|3��_��)s�")�#�{$�>c*��z{�b(XxkQ����ٺ"<���@�*�K8l 3Җ����d.���}�R��ʹe��f&?��iך^��k�F���� �^(�V�NR0L�@���rB� w�M'�v���nӽ�b�=��.]X<�Z2�GC�408�ݱ��w��5S�B��³DR�Tʱ�9l��8� A8n�ݝ�����t��t+-U�Ԯ��ԠXH��$H�ʮL�[;q�g���u^��/�WU�N�[�a�5d�쭣�2�U$������V�8�+����m.�e��5!)����ʠ!e�+ea���2p*��[mI����'Ҙ��Z��W�_|BW�B�<a�p&�����n�/來}>V����V�9�1+��X�0��	4ݯ�m�b��v��C~�6�W��Ꚑ��Z�heP�����V�8�Ǣ���Q��4��b�<�ʹq��F8�v6_`��Ӆ���ϧ��=��*��2F%}��+�c�&�>�so�Ϩ���BVW��B�Y-�ߞzt�~�:���]^����cӡ��XuY${+h��UI�m��,�2�Nr���^;�����{�/�JbM��(��+�J�� �Oq�@��,N�8ibx&x�]�e=���mIq;��K<��+�l2NMGR�mJv��ESQE QE QE QE QE QE QE QE QE����j����)}yr-ŭ��AIûH�X��0{�_^^�wJ�t���v��Y�@̎�,a�.v�v���+]{O�� �5�R�$u7�t��O��|�;y�2Fxꆟ�K�M$�F�QA�iK��<�{ⴭ�Y[���Q�_��a�[S�Vv��� )Zx���2�Z3��SXi�u焵[��_��8�LN@�ٳ �z��+oL񥵾��@ӽ��d��kxX.�B���#����5ꖺ�ޠ�z��o"�7H�I�`�W9Ǡǽf�J�v�y�-V��t��''S��.6l� ��
�k��B�M�zh��`�syB�nخ��2>�<�Z:5��k�N���QK�AH��#�&��T���cަе�2�F�����1��dӢx�0��9�|Y�I(��ގ�3,<-��visgl��n�U�#�I���-�I��(<�֤Ӽ�j�1^YY�[��8�I�H��s���OaZZo�te]�R�{��Ao�B�dL�`c����nG5��x���TV�4�W"�ZFVR��6�c��К�M�����	�0�_A .rKH0ݶ��s��c�i��b}'X���`��{xm�aR���A=��
:� ]���[�6���ɬ�y`���2_An��7�g�Ac�E7��=Vu����s���X�y���?OԴ�<-6���wnEغ�khm�aR���� ��T�5��k�N���QK�AH��#�&��T���cއ��a�?�VP]��+�pF�sdT3`FO|�Uk_	�7�4�Z.:�<񤒔��4f&;��3ƺu���R�tZ�X��.	������m8��jq��I"��it��9�{yWF��fW��S�F�:�?/?�[k�� ��װ𶯩٥͝�2I��W��9'����f&:|���Z�w.��ՎN+��|C�*�w���[�m�x��rC"e���+p29��Q��3l��_����Z!��7�^�$i��"��0~P	��"�+���m�Z���!��%r�%ȍW��+?�ϡ����rGsR=.iZ�P��~ނ�+bX+��C���+�-���<U�)�'�곬���&�p���2�[� � @�j���i�:0��渿�y���&���>I̛���IE���}�Z�gS����R�PDR!�GH�I�|�U'8����P��֣��5ՙ�tDyP�$U\�&6p� g�-��5mN�]Y�+����i�G�h�yh�L�\ӯ4�1-��z����� ��6Qʭ��`�T�������:�O���t-2ݧ{�3z�4z=��`\��y
�d#����h`q5�c��<1�j�R�e��f��ܩ�c�r��q� �p�˻;uc����|?��VZ�i�]j)q�@���H��\�T�v��SG@�It_�����èj�#�[GheR�H#nea���2p)�W��X�]^�o�jBSik��@B˺V
��![ d�U�/�v��&�ou%�O�1?f�EX�¾����2�bxÎ�MIe���8_�}�|�#�Y��7�s$bW�B�<a�9 i�_���ŭ��+����m.�e��5!)����ʠ!e�+ea���2p(Ҽo�����[}SR�KX��]Ұ`PV
�'�l� �����/��O��{k4U�� d�J��(V'�8� M_`��Ӆ���ϧ��=��*��2F%}��+�c�&���:=P��P���0�E�Q�m����1�j�h	���}F}G�_�������l���Ӧ;���J��n����:�b�5G�T�9d��Z�<"��Xm$)�#�t=O֔ۮ�q��� ���)o�_3*0�v`}9��.��Xx^{Ss���w������9�s� <Й��=X�'�N��ֽc�[�P�&F,f��<���c�������~"D���t��F{�i�R� Ǹ�<h]�r0�[�n^9�v���V�[j����Ok�fL��x	B�žb�t�+��m%��A�V�/�Cb��|���q&���h{�m{� �wC�t�iM��7j>\���L "����2��fӚ�������6�}ip"�Y��z<1*)bK�����N*o��:���Reb�>�����8 c'#�s����MZ����֖�'���"�4�FԷS�j��,�g��=h}A���C�Zj��y��Q6�)(��q������ǉ��+X�ƫ��o2h��$�mv2t=� v�rD��2z
:�@��( ��( ��( ��( ��( ��( ��(��~����6��}ww�+�l����Z樢���Iz�:_Ï�
(��4
����7�>���=�r����B����ʜ���QC�XuG	EPEPEP��4�5��X]4���4dFa���VUPq����97��_o��D#�V7��9����(��v�EP����j��I�U�MX*�m�����(��t5u=.=F���2_�+�����F8��YTQ@j�cK�Z����H�M�sF@a�f�=�PUQ@Q@���ּGmat�$So�ѐa�2qYTQ@Q@zF��m�I3:�;#q�X:.0Ƴ(����(�� (�� (�� (�� (�� (�� (�� (�� (�� ��
endstream
endobj
20 0 obj
<<
/Length 1348      
/Filter /FlateDecode
>>
stream
xڭ�Ko�F���<�@�����i��Z�@nz[�$���$����MZ�bQ��|3����ŋ}���<�����r���`��]�d�aN��aS<�TB�_*[>���J�������nD������b"��?/j%�6����.M�ZrQ�]�jW�Z���p��r�\)^~;��^����}�~^�c�s���}vZ��͗���yӂz��j?�S���;^�w���p}���?�}� n>�[��n�%Fz���X,<V*,ʶ�B��窶�����ޢľ��"�6��YWF��w3oy�VX]��#���Η�[����U�f�_M�)��<���0GN3[���eP�kK�=����|���`�#9`b��n@V�#���m��fVEh3ڶs�<إ�O)�i��/_����I-W��ra�T�e���.\�BRz�(�Ly[�O��O���C(����oM�S!�fJ8�>-��$�f*�n�U�����f��(!Q'�rL)�[2�Űv�Պ���R���wL�@��v�\_3�LkC�TB2�07#Li��)S)ɔ{7���6LjK�4�S����Lr�%���v?���ǄY���aA3w=�b�ZV0����g�$Pb�B��(H�N3�*&LAUhk��N��
o]�\A�YH��L�	�&�ή��$PЅ�y&��n��Nwb�!A9f�\[h��A�v�-ڂ����3ń,(��>�O������0;U0;Sd�MA�DQ��DQP0��2�̤�\���{��\���
	�!Mp���Q��Bڛ�N$P�D:�	(���	M��v���v��A�*H��]AEY�(h�Ef�v���9�ӹ�{��N7D�
��Du�O��L�E�9%
&�"�DWP0Q}�*��)r�d

$�"�DQP0����<A�L�ȕ���9����y���0�(>�p,pf���qj��<1�Nx��D1�N*h��9(�����B[U�0�+���
h�E�dAmm�[�h����;]���
m=��\[Xظ��N����ɝ-(�(�>s�cM&��Ϝ8T�0Q�:;U0;Sd�DSP Q�2QL�D����`&M䐨�{���빇
�Y��
K������N$P�D:�	(�"EQ�@�}�Ŀ?H��*2��*H��\��
(�"W(ʂ�l�c�-�f��t��:T�r4( ��T���wߦY^}q�x����Ҽ����4�wa�K[n�.��n5��:f�`u�L�7�u7l$��#�ֹp�wY�㈷8�\�~�W�	�۫Զw���jWavUB9KŴ���.U��R���ZߜK)<���!��p�M�E���i�$�
endstream
endobj
24 0 obj
<<
/Length 307       
/Filter /FlateDecode
>>
stream
x�]Q=O�0��+n��>����"�@�iӦ��
��?Z����{��'�	D��]IV[m!ea�<�U`�V)(kx��YFݾ;2�=�
%]�I��|��P,�ȗ�5��1��t�8��z��Ez�B�Kzq��\��.'72n��hb�M�y�r� �JM�X�6#������S�T����;�E��n����X�����Bgi��kBÜ��׋yt�o�ȱ3�#�_"�%A���1�B��|���X�	c	�,>��Kr��k�8��ϲ�E�{i~����g=Z*a��hq�-2����~?
endstream
endobj
21 0 obj
<<
/Type /XObject
/Subtype /Image
/Width 166
/Height 533
/BitsPerComponent 8
/Length 17122
/ColorSpace /DeviceRGB
/Filter /DCTDecode
>>
stream
���� JFIF      �� C 	

			

		
�� C	��  �" ��           	
�� �   } !1AQa"q2���#B��R��$3br�	
%&'()*456789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz���������������������������������������������������������������������������        	
�� �  w !1AQaq"2�B����	#3R�br�
$4�%�&'()*56789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz��������������������������������������������������������������������������   ? �S������ �X��� d� �?�n���d��c����W��w� �U����;�X� �i�U� �n�� �h� �N��?��~��� �Z+ʿᓿe��6��_�F���f��d��c����W��w� �U����;�X� �i�U� �n�� �h� �N��?��~��� �Z�_�����)�W��Y�� ×>+��X�gM�� gw�k�f��Av��CW�ui߲���J��Z�����~!�h��o��n�q�1O'�X�-�a��S���	��h�W���y�-.��⇉-����B��")�� �x�$e���V�<�O��?�_��/�i/�B�ᖍy��~^8�� W(�DA��ZI;������~�}�� ���K�S���Ѳ7��o���
(������� )�e?��X֡�ï��TŠ�A���[�a�Lq�8#�?f��(�+����� j??����U��դo�!.O������ �B����� �� �#���|�N���0�ci�9�LKg?Q��� ^q��� ��W�� �N��S��+��_|�~)|*���Յ�^ګ㝏�H����q�L�� QE QE QE yW�c� &����� ���=z�yW�c� &����� ���=z� Q^)��|@�����+H���h����Hm�+O>���X�i%{�����B�Q�8$�=����S��~*� �¿������_�;���-�� )��h�*� �7������|+� �j?�M�E� ����� ��
� �>I��h���� �ꪷ>�I�� �H�-\nSx��W �˶���D~�~���O�#P����F��j�$��|��5h�c���֘�2��?*�ʃdK�9m�E� ��x�A����� �o�������O&뛉V(S	��d�3�@浫�?��	��⎧u�|;�5�O��:�m��<6�2�����T�
$�;<�%����eQ@��-�'�O�g�mV�M�ť>��ƃh���㏼4��(}k�.�?��L5��3�=����_�x��)�~��v��>ض��5�@Q@Q@Q@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@yW�?���!� �?�o��|G^�^U���:��O�� ����E QEx��~*|}��Z��௄��l�A�hV�j�?�����;R��y^�y�=�j�J�V9� |�� ��� g��S������M6����1��E���X��-�J	�4q�c��ZҼG�Xx�B���M�-������G<(t�Op�AƼ7⟅~;|e�}�|2�����W��jmn�5u����+�ve�A����w�6���q�Iw��R���<[�����ic����I�'��!�*20�����xO������=;]��=���r�� �fRFy�u�f�
B@5WT�t�N��5�J�O����quu2�(:����5���E�מ6���G?���ڷ��<U�x��geb�l���c �i���"X5 /�]Al�)/�>;�y����0�:�Ɇ�񄱆N����0�*�OQ��j��٧�y�_���J�Y��2��nu+�,�����83�^v����'�� ��( ��( ��(ʿk�5����O�C� ����kʿk�5����O�C� ����h �*����?�?�'�� ӏ���kʼ9� 'O���� ����: �Z(��
�٧�I֯� e���j���_�O���_���� �*�(�k��׀<�;�7~���};�%�����6=��Xu0��5�Q@���KK� �>)��?i�-��1��.%��Dގ�PqĢc�c���u� c��{�|(����D�kz>���]ɦ�J���e�ٴ� ���	P	,�e!C~�W�x��N������ ��Ô��/�Ż�5�����g���d��ҙ�xiIE��6:08�ٟ�
�.��X��������H��L�<ɥb^g��;�:q]� QE QE QE QE�_������O�'�!� �t���_������O�'�!� �t�� W�xs�N����� � ���u��^� ����� d� ���q� z�Q@yW��� $�W� ����J�J�Z�٧�I֯� e���j��QE �^#� ���y� d� �_�q��z�~A|q��N�(f�����"��x�Y�]#VO�4�f�<�6�
J\�5��o��m��J �}�������(�gKx�%i�id`� ��,��,Ēy$���
(��
(��
(��
(��<���� �X��� d� �?�n��V����� �X��� d� �?�n��V�
����C� ����8���V��ß�t� � ��7� N>#�U��( �*���j� �P<w� �V�^�^U�4� �:�� �x�� R�R�=V�W��?o/
| ��~|?����O���,V>�w?��������9bP]�'b�ջ�u~��\�%q�-4��g?�-?3u㌙�Ĺlc�Z��\��'�[�
���X���\���47��||٬<� ��cf�6O�\r���Z�� ���|C�I~�?�k�H��*��G��D2"���I�t8��?������� �*\j�M������pmK�� �~�Q@�7�����N��)���Ƶ�|/�-�(�F�ܳ2c������5� �@��_�G�� �Q�!�|U��0�r���#}�	r|�~������ί�� lO�������u�L�M��"b[9��݇��9 2󏼿0�>���?� �w~Ҟ0���_|�����K�U��V�.8���X���Edh݆s�ܒd��( ��( ��( ��(ʿk�5����O�C� ����kʿk�5����O�C� ����h �*����?�?�'�� ӏ���kʼ9� 'O���� ����: �Z(��
�٧�I֯� e���j���_�O���_���� �*�(䟌v����
���ឪ�s�� ������7�<�r�i��G���]~|:a�� �d�)K�>!�����}(���7�k��
(��~!�w�z��	�,~�7�G��s��������O�����ۗI,�����p3����� ����h�?�>#hʶ�o�-)�f4E����'}�7�C�_�u��� ���_�����V��5d�$�f��bk�H��O"h�dx�(����2�2��?[��� Gc�W� �� �5 z��_��"� ���U� �o��MV�g�s��� �if��.�A�i�(�F�u+�-��v��ݤ[h�?�o%#PH'���E QE�_������O�'�!� �t���_������O�'�!� �t�� W�xs�N����� � ���u��^� ����� d� ���q� z�Q@yW��� $�W� ����J�J�Z�٧�I֯� e���j��W��S��� iO�?���a4�N�q� Ǌ�
I��mb�3�('���:���tMkJ��a�
��7T�������H��E=�){������� ~k��{���B��M��@�u����#�un̠����?�� � ���6��v���� W�As'�!�5��,�-���;r��d��ї �4V7�|e�?h�*�O���wG�@���}�O��I��w�� )	 d�]SU��=:�X��+]>��3-����0����B������^x����� ��6�j��h`�W�������R�匂U����1`� �u��ा$�����4à�w�&���;0f��PÐ�=F?E��?f������]+�g�ʶٹԯ�P��7��p�t��yڊ����S����i� �u�� �@����Z�z�yW��� $�W� ����J�J �Z(��
(��<���� �X��� d� �?�n��V����� �X��� d� �?�n��V�
����C� ����8���V��ß�t� � ��7� N>#�U��( �*���j� �P<w� �V�^�^U�4� �:�� �x�� R�R�=V�� x�_�3w�߈>ӼA�_.���Yccـ?u�P� �]�.�� ����s������ۋ��K��[�7�M���J&?�9�߇_�V=Ǻ7�k�K&���z͵ܚl$����P��M2	j� �BɖR7�yW�� ����?���|9@(�� �2�)�[��Q��� kox��)O�=)�@�熔�Pz�#c��}������>���
<��{KL4�n��p�c̚V%�|�8���@Q@yW��� $�W� ����J�J�Z�٧�I֯� e���j��QE QE yW�c� &����� ���=z�yW�c� &����� ���=z� �^� ����� d� ���q�z�yW�?���!� �?�o��|G@�EP^U�4� �:�� �x�� R�R�V���i� �u�� �@����Z� z�Q@yW�� ����?���|9^�_�� |+�ai�^��>�?��"�ߊ⿗D����}��{P��F8�d2ND�Cb�+���T6qi�6�|O$v�$(���Jʠ ^G%ݸ嘒O$�S�EP^U�4� �:�� �x�� R�R�V���i� �u�� �@����Z� z�Q@Q@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@yW�?���!� �?�o��|G^�^U���:��O�� ����E W�~�?�N��(;� ԫT�U�4տfOٷ_�ou�w�|�k��Z�ėw��~��{��b�K$�gvbX�$�I4�x����9����ϋ�7~	�hm��mgT
4�V�h��Y��#d�x��3	;�v�C������N�N�{�Ho��|B�� eh4�x��h���N�C,i�e���?(�F�e���	%��4_�Z����~��z$Z\3\�A���x i���؍U�-����������f�[x��zl7�<Gj�jWR�'I�@�Pp����`FJ���i� �����E��%�H\�2ѯ1"xO ����Ȉ:� �I'a�㶐� �1����_�Z��q�u7�6C����-� ��5�E ~x�~�� �W�:���[k�6�u𿊘�(<��Kr�8Ɏ/��z��� ��~9�� �G���]�V��ʴV���D%������t�rHZ�:���?d~�?�I�3�Lm7�<@��l��#v3@� ��>��� ���� �	��Jx�⟅|A�K�O��/�W?�Z���k�Ucs��)��v�#rI�������i� �u�� �@����Z�z�yW��� $�W� ����J�J �Z(��
(��<���� �X��� d� �?�n��V����� �X��� d� �?�n��V�
����C� ����8���V��ß�t� � ��7� N>#�U���� ��:|K񯅯�ŭx��Ω�\�I'�u��E&����N8�q@�EyW�)����v?�[�_�SQ� 
o�/���_��W� ���O�;E��� W�w��UU����O� �Eqj�r��z��]��r#���.�:~���� ��4x�U�%޳�����Gk�������a�V�T"_�9�nc�-@W�Zh�]��-gP��ÿk>#��-��g�N�Xi"�d7�lV�	��Kv�4���ɑ@�EP��KE�	� S�Y�FU��~1iO�k1��..��8��9��Z�����(g����|=����^,}Je_�-�ݧ6O�-���~��^U�4� �:�� �x�� R�R�V���i� �u�� �@����Z� z�Q@Q@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@yW�?���!� �?�o��|G^�^U���:��O�� ���ו~�?�k?���� M�תו~�?�k?���� M����E��� ��� g��S������M6����1��E���X��-�J	�4q�c��ZҼG�Xx�B���M�-������G<(t�Op�Aư�)�2��_����/�nе�Sku;]y$F�l��][�(5�����?Ŀ�&������i����_��� o�`��K(�n1:�N���C/$�te����xO������=;]��=���r�� �fRFy�u�f�
B@5WT�t�N��5�J�O����quu2�(:����5���E�מ6���G?���ڷ��<U�x��geb�l���c �i���"X5 /�]Al�)/�>;�y����0�:�Ɇ�񄱆N����0�*�OQ��j��٧�y�_���J�Y��2��nu+�,�����83�^v����'�� �*���j� �P<w� �V�^�^U�4� �:�� �x�� R�R�=V�(��(�*����>2�?�����U�*����>2�?�����U���ß�t� � ��7� N>#�U�*����?�?�'�� ӏ���kʿk�5����O�C� ����kʿk�5����O�C� ����h�� +��׀<�;�7~���};�%�����6=��Xu0��5�Q@���KK� �>)��?i�-��1��.%��Dގ�PqĢc�b��
�l?��?l��X��M5�f�o�N�͟��_�P���/�Ż�5�����g���d��ҙ�xiIE��6:08�ٟ�
�.��X��������H��L�<ɥb^g��;�:q]� QE W�~�?�N��(;� ԫT�U�*���j� �P<w� �V�@�EPEP�~�?�k?���� M�תו~�?�k?���� M�ת�^U���:��O�� �תוxs�N����� � ���t��_������O�'�!� �t���_������O�'�!� �t��QE Q\� ��ெ>���i��,Wt���Q�젟�ǠQ�'�	����^� ���x�\����7���Ż�o�Io-��z>�Gp��e0��0��_�W����i��=������}0uEl� �?
 � ��?-� ট�_��~��O�<g,��支5�bq��0N�ݱ�I�~��G��w�o
��?�3��C��F�r%�r3�� �?��sӚ �袊 +ʿf��'Z���� �U�W�ו~�?�N��(;� ԫT�U��( ��(ʿk�5����O�C� ����kʿk�5����O�C� ����h �*����?�?�'�� ӏ���kʼ9� 'O���� ����: �Z����Mc�'��� � �z�Z����Mc�'��� � �z �Z(��9_�|�k����7Ǻ��t-��]J�n@H�x�#�TU��~||#�1�/�
S�h� h��i��2��'x��0�L�˃��(��A
Qs�� �A�u?����3����C��������j�f�$p
�� x-$G���D�t�h�Ь!��t�h���a]��j#Q�*���
~�o���ZxW�>Ӵ-�[����1�vU g�OS޶h��*j�V��i�>����q��-n�Ya�Ut`U��"�<� h���߲o����?a��I��C?��y,�lT�?4`�U<EJ���zB4忳O���w�.��O��b[��jV0it��ͷr:�p*�nFF�����O�]=c��)/�>iy���}0���Ȇ��D�N����(�@A��j +ʿf��'Z���� �U�W�ו~�?�N��(;� ԫT�U��( ��(ʿk�5����O�C� ����kʿk�5����O�C� ����h �*����?�?�'�� ӏ���kʼ9� 'O���� ����: �Z����Mc�'��� � �z�Z����Mc�'��� � �z �Z(��??�(�?����x�����u����	��5�_������_����U�����?� ��ӝ�/y
��8uӲs��۟к +�X�$|J�ǎ�u��*��zw���K�4��/-�#�O4Gn��>� ,��f� �yo����$�<}s��_&�9�һ�4�iG�Z��D�"ā�%%v�I �h�� ��� ��j����e�^�n��rr�$�l��Ն�t?�>T�Չ�'����>9~�o�o|4���xV���xB}����J����C�i6F�wF�a³�O��~=� �T�|9љn�߃�S��̈w{���8��N_b�Ҿ��~x[�~��U�s�o��K���~�j�E$R"�팒�
W'8� q��>"� ѧ|U� ����sV�g����ia����?�j>(�F�t۹����v���dki%���q!$`	#<W��@Q@Q@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@yW�?���!� �?�o��|G^�^U���:��O�� ���ו~�?�k?���� M�תו~�?�k?���� M����E����/�ڏ��Ǉt��~�k�i<���0a/�+*�s�+yl~�r����o����������k�U���>F��[���A�>N��ֵ��a��S���k�O�� ��>�W�e��6��>��?v�"2�H�*��8;���(���?��� ��~�����f����5�#OxT�y#�d��O�iz����Y����;� ��-�N���:��ޙ7A���?@+���#���/���moU��P�n����I�˹�y��@�ߌ�������?n��+����S��u��"���JVT�]D��e��/���}�k� �~��O������Q��1I���[&E���y����'�  5 y���[����!������a/�O�w_ښ�ڼe�y�6��D�pf�$fvycoȄ}� c�,��|*� ��N� ���P��X���r�
��ӿ����?����¯�,���=^�E yW�5��� G-�� -;� �V���h_�^9�m|-௎�A�^��6�������}���"�Fvڈ�p8U$�zyW�O�(��^�+�P��E�_������O�'�!� �t���_������O�'�!� �t�� W�xs�N����� � ���u��^� ����� d� ���q� z�yW�c� &����� ���=z�yW�c� &����� ���= z�Q@Q@yW�� ����?���|9^�^U�?�:���O�e� �P��E QE QE W�|d� ���'�������z�yW�O�(��^�+�P��E�_������O�'�!� �t���_������O�'�!� �t�� W�xs�N����� � ���u��^� ����� d� ���q� z�yW�c� &����� ���=z�yW�c� &����� ���= z�Q@Q@yW�� ����?���|9^�_�� |+�ai�^��>�?��"�ߊ⿗D����}��{P��F8�d2ND�Cb�+���T6qi�6�|O$v�$(���Jʠ ^G%ݸ嘒O$�S�EPEP^U��J/���(�������_?��	� ��y� ���@�EP�~�?�k?���� M�תו~�?�k?���� M�ת�^U���:��O�� �תוxs�N����� � ���t��_������O�'�!� �t���_������O�'�!� �t��QE ��a�yxS��k��� �.>"|W��b��Λ����?v�&0�	�+��9;���۫��?���+�h1�ό�C8��1h����d�S��%�cf�����a?����W��������/���5[���a���k7!�z�|��U�"�� e��(�>���K����e�^bD�AW�2?��!�u� ��Ná�m!� c���l����R�T�n� �l���j[� �k�� ����� l��
u��O���5�mp��1h&PyE24��q�_��ٯ�
7��r?g� ڏ���%!�+�h�5i�K���E,�� �䐵�u|� �b~�>��~>��$:g�4��ox����F�>f����}���4��� ������?
����Ɵ6�_
���aq�׶��8�c�R+#F�3�F�%}�@Q@yW�O�(��^�+�W�ו|d� ���'������� z�Q@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@yW�?���!� �?�o��|G^�^U���:��O�� ���ו~�?�k?���� M�ת�?��ZWį x��λqw���D����g��^6ee��� ����پ"���Q�1��n��'��U�G��R�{FyKlA�CC ;s�o͌����"� ���U� �o��M_~�� �O��� �灼=��x�Y���������#H���2��[A��eo<��ٚL2Ȫe�-�XG���~� ���;�g����{�'�� �"��q�M�=\��.�vF9���_����|E�W�
��/|@�����W��s0��T.u鯓�ݾU�Tv;c䓓_�� QE|��E�����~*�v�?�o�"h2�z�ӥ0p-��XU�&-m�q��x��ִQE ~z|d�_���U?���e[]7�������~��>�ӛܡ��к��� ��Z�����J�n��]隲x�{�{d�5ͤMy��4k2<e�[��H��_�Xd���M�E� ����� ��
� �=V���S��~*� �¿���_�ƹ�mᴳx�ė~ Դ�x�D:����s��}gn�-�qBɷ���$�h��ʾ2�E�� e�� Q]z�V���'��_�?�P/?�ר�h�� ����Mc�'��� � �z�Z����Mc�'��� � �z�Z +ʼ9� 'O���� ����:�Z�� xo�F��\����¾
����$�k~(��g����T��V:�dG]E %��pr {�_���� �F�����EG�$�?���_�r��QP��^U� 	�O� Do�W��G� �T�G�S� ��U� �/Q� � |�� ��� g��S������M6����1��E���X��-�J	�4q�c��ZҼG�Xx�B���M�-������G<(t�Op�Aƿ%k�C�����9⟂��m��y�t�v��4��`�Y.mmO�ʊ�A"��w�Q{?���Ə�'6��|��tK���W_x�͚�!�n�غ/�#Fc�07�r�6Z �D�q>�<���	<���S�䶸4����M��0�8��b�xG�^���i���N�t{�o}�ܤ��1ٔ��yGz٠��MU�5]/CӮ5�oR���-#2�]]L�C
���*��M~y���獿k/��'��k6����x�0���X��*�.>X�%Zn�>H�@�WP_��
K�O��^n��cL:�x2a��a,a��io%9
��c�Z���i��|�1|%Ҿx1L�m��J�E.�|�y�L�W����8��: +ʿf��'Z���� �U�W�ו~�?�N��(;� ԫT�U�*��� %�O����Eu��Z򯌟�Q~� �@�� �W^�U��(ʿk�5����O�C� ����kʿk�5����O�C� ����h ��( ��( ��({I�nml��[��2GV�@��܎Y�".O;UG@+�^ �W����7����h�˶{+�X��`�a�0�� �AE |��-/��\���D��<c������世���z:9A����f�����G���/���ɭ����mw&�	+oc5�2�f�L�Bڄ%@$�e���A^U�?�:���O�e� �P�6� �L�����k���Ş6��E��Jg��09�%�d����f|#�+��O�b�gi���"ۡ2�8�&��y���N8��v�PEP^U�4� �:�� �x�� R�R�V���i� �u�� �@����Z� z�yW�O�(��^�+�W�ו|d� ���'������� z�Q@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@Q@Q@Q@Q@yW�� ����?���|9^�_�� |+�ai�^��>�?��"�ߊ⿗D����}��{P��F8�d2ND�Cb�+���T6qi�6�|O$v�$(���Jʠ ^G%ݸ嘒O$�S�EP^U�4� �:�� �x�� R�R�V���i� �u�� �@����Z� z�yW�O�(��^�+�W�ו|d� ���'������� z�Q@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@Q@Q@Q@|��X~�^����,��ˏ���vX�|3�����ݵɌ3r
Ġ�N�!�w������J��Zis�?�4Z4~f��3�%�r����?~�_�O�6�������G~���ho��V���Xy� ;Z���l�޸��#%Uhȴ� �c�
�O�������.~hט�<'�PU㌏�r�dD夓��q�H�� g��/�-|T��:���!�z�ږ� �� � ��?<o?a�+��w�S����j\:�_�LZ	�QL�%�fd���=�k� ��M���� ���C�.��	Ha��Z+ZF����n�QK:?�9$-}�_?�؟��?k�Ϥ�	��&6�Þ DĶs����r e�y~` }E|� ���<a�O¾ �%�͇�«��X\q5����9�� ��ѻ��$�_`P^U�4� �:�� �x�� R�R�V���i� �u�� �@����Z� z�yW�O�(��^�+�W�ו|d� ���'������� z�Q@U�X� ɬ|d� ���7O^�\� �/i_��_�:���o��{��[GU�8.axdhٕ�8W$�3��Ҹ��S��~*� �¿���U������_�;���-�� )�� �7������|+� �j �Z+ʿ�M�E� ����� ��
� ��S��~*� �¿���U�vo�����n|[�������`��T��ўD�dP������c#<g�)����v?�[�_�SW���S�B����ox;��%�m<?`���2�H�,�쌳���f�[�,��f��*�c��s ���h���� �ꪷ>�I�� �H�-\nSx��W �˶���D~�~���G��_|� �����_>!j~7���> ��A�zk��wo�`�]���$��� �������4o�s^C_�᱂�O��-��!�C�\�!T�� �W����>��A�<��ׂl�tm'Y�u�4Օ읾�"Q9Rc$4�FA Ɏ�@�EP��KE�	� S�Y�FU��~1iO�k1��..��8��9��Z�����(g����|=����^,}Je_�-�ݧ6O�-���~��^U�4� �:�� �x�� R�R�V���i� �u�� �@����Z� z�yW�O�(��^�+�W�ו|d� ���'������� z�Q@Q@Q@Q@Q@���PkmO�{��>���=��i:M��#*)$Z������t��G�F>��5�+�z5��t+�o��R�+�;�[ts�"�I���k��/�e�}�|2����_�6�Q�אRDnvȎջ2�_��3�K� �kx�?����K�_��̟����T���������2�J�F\ ~��X���}�Zx��>#ӵ����i�)<2ve$g�GQ޶h �$�UuMWK���c[ԭt�H̷WS,P�;�
�z�_��_�y�o���s��� ��ͫi���^7�<vvV,vʱK��2	V��� ŃP����� ����㾗�� |�����n�Kd���[�CB����,��g���_	t���S*�f�R��B˨�8mÁ�;@U�j*.N2}N�
�٧�I֯� e���j���_�O���_���� �*�(�kʾ2�E�� e�� Q]z�V���'��_�?�P/?�ר�h�� (�� (�� (�� (�� +��׀<�;�7~���};�%�����6=��Xu0��5�Q@���KK� �>)��?i�-��1��.%��Dގ�PqĢc�b��
�l?��?l��X��M5�f�o�N�͟��_�P���/�Ż�5�����g���d��ҙ�xiIE��6:08�ٟ�
�.��X��������H��L�<ɥb^g��;�:q]� QE W�~�?�N��(;� ԫT�U�*���j� �P<w� �V�@�^U��J/���(�������_?��	� ��y� ���@�EPEPEPEPEPEPEPEPEP^U�4� �:�� �x�� R�R�V���i� �u�� �@����Z� z�yW�O�(��^�+�W�ו|d� ���'������� z�Q@Q@Q@Q@Q@|��X~�^����,��ˏ���vX�|3�����ݵɌ3r
Ġ�N�!�w������J��Zis�?�4Z4~f��3�%�r����?~�_�O�6�������G~���ho��V���Xy� ;Z���l�޸��#%Uhȴ� �c�
�O�������.~hט�<'�PU㌏�r�dD夓��q�H�� g��/�-|T��:���!�z�ږ� �� � ��?<o?a�+��w�S����j\:�_�LZ	�QL�%�fd���=�k� ��M���� ���C�.��	Ha��Z+ZF����n�QK:?�9$-}�_?�؟��?k�Ϥ�	��&6�Þ DĶs����r e�y~` }E|i�~�?~&|?�o���vQK��1�L�����jj���I�TvS�'�,��q�L1|��U����?l/�����;�|7/�a}D�W�G���}2YF���7MrZt�&&Y⠤;�PՊ�٧�I֯� e���j��G�S� ��U� �/Q� �j��w������ťC�^���:��:]�v�h���M$P���P��2�p1� �
򯌟�Q~� �@�� �W^�U�*��� %�O����Eu� �Z(��
(��
(��
(��
(��?=>1�/���*�ÿ�z��χ�x�+�W��0���<r��dc���u���醇� ���5/�����O��[m��v� �4ߑ�� (��G�W�>"]~�s�7[�w�&�w�j� ����GH���ؾ���ݘN%�x���eIIR >���(���%��� ���,���*�����5��mC� �q������}��|6��^���ľ!����MƑ����\5��ǜ�����L ��v�_� �L4����?����k�Z.�>�y*jV`����m��'�+��Z���	~�k7�O�>%��Z�<Ug}h<}�>���}�U{�[{��[�{�W;��L�fF �2������_�;���-�� )�� �7������|+� �j �Z򯌟�Q~� �@�� �W^����_�;���-�� )�������cž-���ſ��jj�v��[�p���K+�##�-:	[�O���A �=V�(��(��(��(��(��_�(5���=�ҟm��i��&����-_���	hg�PO��u#~�֕�=��:�7�n�m��-�9��C��{�R�5��Oᗃ�2�>�>x�M�v��ڛ[�����)"7;dG
�ݙA�Ϗ��%� �5�m���M%������O�C|k*YF[q��rv��x�%C�. ?Lh�o���~>�-<U�����|������;2�3�#��[4 R ɪ�����zuƱ��V�}��f[����(aA՝؅P=I��?�/����e�9� d� �mfտ�����;;+;eX����MՇ�b��~
��`� �I|I��K�߀>i�A��L7W�%�2v`�-䡇!Vz�~�W�~�?�ς� f/��W��)�m�s�_ȡe�o�6��靠*�'>�@Q@Q@Q@Q@Q@Q@Q@s�:���'xf���|/�x�D�]��_���ǳ ~���A�(�����NX�Zj�?e��'����i��v�	bb��&�L|c��A?n=_>	O�"�h������t�&3��h��E�w�� ؇�_��e�����|{��ʮ��E�!���i$�A��U�ч~�|#�+��O�b�gi���"ۡ2�8�&��y���N8��PoEPEPEPEP��
endstream
endobj
28 0 obj
<<
/Length 259       
/Filter /FlateDecode
>>
stream
x�U�MO�0���>&ɜxY���`�Ro��_�&�������b�}��qz@81��c�6��@����Byg��N�5P�����Z|��ܯAI�
G�;܅4��Yh~�&a�w�rR�Va��j����hf��I��|���F^}_|�a�7'v��1��s>:�oЦ���ߑ:�p'!>w�WUx2{*��E�a.�
吠���
���U%�v1�DKq�r��qdo~-�_����+��)�fMh�-�Q���b�{��Ng�
endstream
endobj
25 0 obj
<<
/Type /XObject
/Subtype /Image
/Width 176
/Height 533
/BitsPerComponent 8
/Length 17248
/ColorSpace /DeviceRGB
/Filter /DCTDecode
>>
stream
���� JFIF      �� C 	

			

		
�� C	��  �" ��           	
�� �   } !1AQa"q2���#B��R��$3br�	
%&'()*456789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz���������������������������������������������������������������������������        	
�� �  w !1AQaq"2�B����	#3R�br�
$4�%�&'()*56789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz��������������������������������������������������������������������������   ? �S��( ��( ��( ���h�H�UA,�� ;�u|!� �����|/�|�6�'����(�c�� �%�J3/*I$��UQ�7 |a� ��������߰�����'�>^��W~����Y����Ot�#�0�\�ô� �q��k?����B���D��Y�O$)m����ہ�R1_]~Ο��Ïٓ�ŗï�ZbƑ��Q�dA��N�i�aԞ��Up� �4����F��zh�g�~2|S�5A�ݝB��޸��6� ��'Q�I� #����?�ǟY|���MG�q��)!r �rs� ,����z(��;���e�Vh��Dsxwƚ@#Y�� �V�N�x���7 N��3�%~}� �H?b�/Z�����I�-�m�MW]Ү4�����8Hg�kgS�F���?y`rBW��̾���i?�����~̿
-�T�ŨY����_Fv�0��*O�FF�@S�^U� ��,Ѵ�*� �7N� �4�'~��m?
���ӿ�� z��_��߲��O¯�#t��3G�2w�� F��� �;� ����^U� ��,Ѵ�*� �7N� �4�'~��m?
���ӿ�� z��� �7�2~ͺ���_]пgφ�v��x]�����3�O���ȱGV� _PPEPEPEP_���N;E���D~П����sq�x��;�J�&5m�>�Gb��p���~���������/��o8�4�ݛ�?xn���g�����(��0�<i��O�Z���f��S�"�k�i��/0T�IO ɴ�ya˅`J�A��򟅞 ��1�[⿉�g��k����Q�MXPE���y�A�	Z\���rkը�C�OoqK�Q��2���=A����	����?h��R+������C����w}��0Kb	� �~�~�W���?�?�_��C�����7iiq�hPi��$��B���� ����1�0� ~��^U� 
o�/���_��W� ����� Gc�W� �� �5 z��_��"� ���U� �o��MG�)����v?�[�_�SP��^?��o�|h�ß�Q��4�;����e��4�g����X�uV���VB�6�V �����_������O�'�!� �t���_������O�'�!� �t�� QE QE QEr�<u� 
��g��&e� i� �%��G]�������M�y�[f�/n�������:>j+� �H�y���^��S[����C���I"�;)�d��(9Ƀ�
��?ڟ���¯�9z�� (��k� ٷ���c�K-R�g����$��о�<Ai�Q�{	r�b��ŏz8U��L2�dm���+��w������� ��k#x�v�R�-[T+=i:G#��F>f|�~�'m}��\D��H��у+)�ހE�|L�����߆'��i��-����m27�#A���1�( ���3����⇌�ž���/g9�HG	z��TQݘ
��	Y�O����Qx�բ׾2x�mF��YG,�s�V�i�
Gc5�k���;�qY|5��> �CRId:֧.�<I:0�[�2ɰ�UX�bY��P>��f���/��������z~��Z�eeiĝEc��"F��� >��W��G�S� ��U� �/Q� �s� �,��_|�_����?�����u�ȭ>$_��Am�"ƭ���*� YFq�:���E�^� ����� d� ���q�z�yW�?���!� �?�o��|G^�@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@Q@Q@yW�c� &����� ���=z�yW�c� &����� ���= z�Q@[���e�+�I��|Z�]����E��0�Y��g_�Fy(r���M|������0���hk�>���C�<��� ��c�E�����"� ��o���
߭���~ؾ��o���lQn���lM���Z�� �VxCP�,<���0���&�!�ne���k�I�A H�G1���� ��h:��{OxkG�Ҵ�>!���F:*" ��~�( �*����>2�?�����U�*����>2�?�����U��(ʼ9� 'O���� ����:�Z����C� ����8���V�<���� �X��� d� �?�n��V����� �X��� d� �?�n��V�
(��
(��
����Mc�'��� � �z�Z����Mc�'��� � �z �Z(��
(��
(��
(��
����Mc�'��� � �z�Z����Mc�'��� � �z �Z(��<�ß�t� � ��7� N>#�U�*����?�?�'�� ӏ���hʿk�5����O�C� ����kʿk�5����O�C� ����h ��( ��( �*����>2�?�����U�*����>2�?�����U���h�H�UA,�� ;�u|!� �����|/�|�6�'����(�c�� �%�J3/*I$��UQ�7 |a� ��������߰�����'�>^��W~����Y����Ot�#�0�\�ô� �q��k?����B���D��Y�O$)m����ہ�R1_]~Ο��Ïٓ�ŗï�ZbƑ��Q�dA��N�i�aԞ��Up� �4����F��zh�g�~2|S�5A�ݝB��޸��6� ��'Q�I� #����?�ǟY|���MG�q��)!r �rs� ,����z(��;���e�Vh��Dsxwƚ@#Y�� �V�N�x���7 N��3�%|#�{�˺Ǉ�W�����h?��5h���5�8��^H�"ǻx?�bޭ�����~<����_|ZУ[v� 1ja�l��;g��p���dn��U�_������O�'�!� �t���_������O�'�!� �t��QE yW�?���!� �?�o��|G^�^U���:��O�� �ת��~�?�k?���� M�תו~�?�k?���� M�ת�Ey� ��w�� �%�����bּ?��gTӮ|��Ⱥ��Y"�c�F��
�`�8���S��~*� �¿���U������_�;���-�� )�� �7������|+� �j �Z����Mc�'��� � �z?�M�E� ����� ��
� �����O��;�m���^~��K{_�Kcwaᵂ��b��a�RP�Rct|����~��_x��X��w�t�^��ڄ�V�okr�5��24rE4y�F��2FA�� �q�/�O�#����5�[��C���V0Y�n(	�;c�=�+�����io������4Z|S�ý�V����Wmh�殐��#��c��b��fˤe�љf�3w��F�o���~��T�<vn�����1��~F�?@h���iR������br�+�.�8Pݳ�=�z+�ً�z���O��}� ͦ���TKo_����0�����W�R�E.�YWqB�v߫��C�OoqK�Q��2���=A����	����?h��R+������C����w}��0Kb	� �~�~�W�����[� ����~ Ӿk?	�i�2��pIB��y#@�5�_������O�'�!� �t���_������O�'�!� �t��QE yW�?���!� �?�o��|G^�^U���:��O�� �ת��~�?�k?���� M�תו~�?�k?���� M�ת��~�?�k?���� M�תו~�?�k?���� M�ת�EP^U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O@�_�	5��?�~<�S��/|y)��z��!��y$�b���]���م~�����읣~՟�H��]#ƞ��k!��[�3���)6�b9VTq�� BQ_�˿������f��Y����QjڠY�I�9_��0��3�K���;k�f��$���%�E��YH� ���� �(�K�gŏ�� �1?��(x�L��ng��i�������a@ŏ���7���?<ev-�X�{9�B8H���ʢ���W�_�J�x�P���ڋǖ����Sj0�"�9e`˞B��N �R8���GQ��� Y��g�iZf��/٧�Z����`a���g���8
2��b\���V��h���� x{N�O���X��� ]��j#Q� � _�*����>2�?�����U�*����>2�?�����U��(ʼ9� 'O���� ����:�Z����C� ����8���V�<���� �X��� d� �?�n��V����� �X��� d� �?�n��V�<���� �X��� d� �?�n��V����� �X��� d� �?�n��V�
(��
����Mc�'��� � �z�Z����Mc�'��� � �z �Z(��<������W���B���mQ�ԋ=B"a��'��ο:��P�r��&�'W�1�a��S����}O�>��$y-�� �7��ԋu�߷�E���φ�U���ϋ<#�~׾���~���\Zi�G,���i|�O���W��S�\c 3v�� �VxCP�,<���0���&�!�ne���k�I�A H�G1��W����_���P,� ��k�h����~��<=��J�����VP,0A計��U�(������ �X��� d� �?�n��V����� �X��� d� �?�n��=V�(�*����?�?�'�� ӏ���kʼ9� 'O���� ����:�Z ����Mc�'��� � �z�Z����Mc�'��� � �z�Z ����Mc�'��� � �z�Z����Mc�'��� � �z�Z (�� +ʿk�5����O�C� ����kʿk�5����O�C� ����h�� (��߈���߁5�Yx�U��֯a5����]Iowa3)��H�X26��@8��$P�o�J/�o�(���5������֟ioZ|h���[���������5}qm"�m��X��B��9���ٔ����{@Q@yW�c� &����� ���=z�yW�c� &����� ���= z�Q@U���:��O�� �תוxs�N����� � ���u��_������O�'�!� �t���_������O�'�!� �t���_������O�'�!� �t���_������O�'�!� �t�� QE W�~�?�k?���� M�ת�M[Iҵ�*�B�t�MGM�m䴼���f��	��I����R �h�|��W����{\���������ɧ���os�lRH��&)�up[�Qk�� �N��?��~��������i7�/��>�l�A���j�"�Ӭ���Y��mi�U_9��q�� >���� ����_�a���Ol|�G���'M���!%Q<�G�aD��i� ���>2(�k��Z���.���d���HR�aq����b����?gO��'Ë/�_�ō#&��ȃ�Z��0��é=���T +�h����������d���j���:���q�m� ��N���
G� /�$
~-�>���<=��$����%��RB����Y�_��P��w������Ѯ-����4�F��mA� ҭJ���:-�n 2�U$g�J�G����u�ޯ���7n�~'x� jj�YE�kVq�޼��E�v��Ž[$-}9�2�y�?i?�����F���@b�,�d�_Fv�<�8%I�����ԫʿk�5����O�C� ����kʿk�5����O�C� ����h�� ����C� ����8���V��ß�t� � ��7� N>#�U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U��(��(��=?��v������?keV��P�xwD��Ljۊ} ���Oc������#C7�_�?�q�i?�7j~��gk��
	?#@�5�Em�6��R�q�('������7�ƌ���*���J� (?��O�t-?ĺ�ڴ�R�;�I��O226��A�+B�Z��� ���	4_�� �~3�T��,���~�m�<���DE���\F�#,�lR�&�+����$�)���ee#z�;W�����1�L~���.WG��u��o��6��?`��� L����������� o���A�|�6~��fe���&��}���F�?@kʿk�5����O�C� ����kʿk�5����O�C� ����h�� ����C� ����8���V��ß�t� � ��7� N>#�U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U��(��(��:>j+� �H�y���^��S[����C���I"�;)�d��(9Ƀ�
���� m?�;F��>&�ox�G�<;#j�C6�\f7e��RmP�r���%0@>�����o{����߶�7��'h%,�յ@"�֓�r<�q$a��gʗ�+v��p��Iqo*K�2���AA��Q\��ϋ��b|P���"��{6�#r4y_�3�<1�oῈ~(x��[����s�4�p�'���Eـ�������.���?��-Z-{�'���aE�r���<�i��Фq��1����;�
��:�JҴ�_�_�O��5����q������peaV,ĹU�ҭB��/���������V�YYZ@�c��"F��
 J �^U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O@�EP�xs�N����� � ���u��^� ����� d� ���q�z� yW�c� &����� ���=z�yW�c� &����� ���=z� yW�c� &����� ���=z�yW�c� &����� ���=z� QE QE QE yoǟٗ��'�.��k�vڣ[�z�D�}dO?��~u��6�5�L?�N��c�ô?�������:��}�H�[�� |o����ӿoЊ(���g��+~�?��A�b��žV�M�E��
i�6��k��	Y�Cİx������ߌ��D8�Q�� s��I&u"!��_��Q~;�@�� �WA�U�
���_G�����{-+K��ZYY@��c�� 
�zW袀
����Mc�'��� � �z�Z����Mc�'��� � �z �Z(��<�ß�t� � ��7� N>#�U�*����?�?�'�� ӏ���hʿk�5����O�C� ����kʿk�5����O�C� ����hʿk�5����O�C� ����kʿk�5����O�C� ����h ��( ��( ��( ������5�W�l�]���Km-��=> f��#����;�\�#s
�&�(��1��o�S�/�����>��'x��� �6B����۸�� ��v� ��g� ���^�_�_5��+�ox����:i�(����.��i�j���9�1[D���E�R��C��!��'��	� S����X<�Q|�o��zRM��K=�9��-s"�F��K��UCB״?h��!�ֱe��z�B{K�)�h'��dt%XPj�_إ�Zc�@��D��ndW�
���R�d�u�Q@ו~�?�k?���� M�תו~�?�k?���� M����E�^� ����� d� ���q�z�yW�?���!� �?�o��|G^�@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@Q@Q@|��i��:7���5{{5��i�)O�����2:��b�r��fD/��%~t|$ӗ��� ����ⷈ�|�����wɇ�E$�5�vc��w0`3�e��˿�E�5��i�Y��?�◱i:����8�/��(����E�UI��a��$���"�5��U@� ���( �K�g��� <1?�~(x7L��p`��q����<O��U�c]m�)���ߴ��]D|��q?��Na��T���7�s��YU�	2Ƞ����=/��ڢ��o�|E���x��>�Դ��÷�%�մo9E���Q������̌`�[
���ŏ�~�����?�eh.4���e8�Z2yIS��º�̠��_�J���O����wǗM.��o�SiЗ'&�IeP��J���A�H�� �W��ڟ��'¯�6��� /k����������9�~6|5�M�V�{�^Ki���g��^6mq�8W$�3��ҽ֊ (�� ����C� ����8���V��ß�t� � ��7� N>#�U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U��(��(��?���
5/��]yΩ����]���m���?�)���~������~���'쟬��\i� oh�1��͛ip�X�<1�3@�u��XY\_J��o��FI
	 {�S�2�X�� y����F�a�o�84?�j�e���w`%�	�����`L�!������k���oxS���/��mss�څ��[A�w�m�2Zø�B2��u� W�����D� ����~Ӿ[�	�jS*��pSIrO��3_M4V�=�ĩQ�ww`��I$� w�ϯ�'T������� j�P���j��������A�#��{r�EPEP�xs�N����� � ���u��^� ����� d� ���q�z� yW�c� &����� ���=z�yW�c� &����� ���=z� yW�c� &����� ���=z�yW�c� &����� ���=z� QE QE ��������=���������
�x�N�w�L���.ʼ�Ty#�o-��<�����D�92�!���c@a�:~�?i��_~jk"H=GN��ڴˬe��GB;7�e�) ר�����=�}�����!�����O���^V٤�_6�T2 cϓ"������?ࣟ�G��7�a���O��e��:��s��*t'�r�s�P�]����Y�z���~�S��C��>�2ޙ��F� �+'Q��� #����� �?	O�o^��!��=G�$sH�(%rA� s� -@���������^��S�7n׾'x�� e���K�h�rޤ�F�v��E���}9�2��?fς��K�H���e�/���HwO7<�!A���������bφ_���qq�I7��i��u��	��tX�d�d�1n�h%��1BPEPEP�xs�N����� � ���u��^� ����� d� ���q�z� yW�c� &����� ���=z�yW�c� &����� ���=z� yW�c� &����� ���=z�yW�c� &����� ���=z� QE QE QE QE yW���(���Y� �+�תו|� ����������z� QE QE QE yW�?���!� �?�o��|G^�^U���:��O�� �ת��~�?�k?���� M�תו~�?�k?���� M�ת��~�?�k?���� M�תו~�?�k?���� M�ת�EPEPEPE��E�ǎ�	�x:�Ě����{	�m�m*�K{�	�O�<RF�����2�A"�8σ�Q~;�@�� �WA�U��/�������Kx���G�z�E�w�5߈�me���i�o�
�nb�1�wF0F̧�fo�� (�� (�� (�� ����C� ����8���V��ß�t� � ��7� N>#�U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U��(��(��I#U�� �i�������>=��!���x�����Q�w�Kt��(̼�dI$�o-UF|�P��
�߈?.�~�O����z��%]�N��mfBJ��<y�0�pr+��	��D|dQ����7����]î�g<����:�nH�}u�:~Ο?fO�_�i�FMGQ�ڵ;�a���R{/�U¨ W�����>�����OH�+vu7�z�;h�� ��G�'���@_�H>�Z?|e��x{[�I5$�K#��������#�E��� d��O��Y�\[����i �g�ڃ� �Z�;Y�8t[�� e8�H�Е�����.��_�[�nݠ�N�1��բ���֬��y#<���� ��z�HZ�s�e��~�|9�kB�m�T�ŨY�ɲ���y�pJ�������QE QE�^� ����� d� ���q�z�yW�?���!� �?�o��|G^�@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@Q@Q@~z�8��'��B~�ʭ�ơ���+�,շ�A�1��_���F�o���~��T�<vn�����1��~F�?@h���	u%��v2�^X\�W*v���(����6�
�� n�{c6����}�OH��a��`���Ƶ|��=�2=�?��b�o�躵����<[�]���E{�5œH�wn��H�u.p��W�Z d��q��D��"�tu��`�PGj��� �uB� ?i��/�T����>��"�������g�L؂響����>��� �� ��4����v�l̿t\�P���_���Q@Q@U���:��O�� �תוxs�N����� � ���u��_������O�'�!� �t���_������O�'�!� �t���_������O�'�!� �t���_������O�'�!� �t�� QE QE W�G�MEd�)�>������Jk~�|��^I$X�e>l�p�90va_�������'hߵg�$�-�H�dmC���b�����0�M��U�d�ДW�?����{��c����F�7����Z��Vz�t�G��$�0|��R��`N������.-�Ib�C��VR2#�#� >�+����c���O�/�2�<9�[���f�do�F�/+�"c�P�c�g�>�7��]�}#Ö2^�s���$�wr���0�����%�<!�����E�|d�ڌ!�Ȳ�YX2琭4Ӏ:�28�<�Q�~'�V~'Y�ZV���K�i�&���n<Cq���r��*Ř�*��U��Z?��=?�^Ӡ���*�+++HlpA�H�v@�@袊 (�� ����C� ����8���V��ß�t� � ��7� N>#�U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U�*����>2�?�����U��(��(��(�-���2����о-x.�Tku"�P��o����3�Σ<�9F�ܦ�I��	��L|v��T��5�GS�����Kx���"�zw��E ~oxs��k�.��������|�G�j�tQ�$���_����b�U�C%��W�ݿ�?����<K�?j/�>-�ɯDC�u�`�9����gP@�"�Lp>��7� %���?�Et�Z ��h:��{OxkG�Ҵ�>!���F:*" ��~�( ��( ��(ʼ9� 'O���� ����:�Z����C� ����8���V�<���� �X��� d� �?�n��V����� �X��� d� �?�n��V�<���� �X��� d� �?�n��V����� �X��� d� �?�n��V�
(��
(��
(��
(�w�/��<w�M{��^$�|=u��Mko�iWR[��L�|��6V����0r	�|� ����������z�~a~������_�[��> ���/ýi��Ekk(�M_\[H��x�xV3s���C��1�6e>s3~��EPEPEP�xs�N����� � ���u��^� ����� d� ���q�z� yW�c� &����� ���=z�yW�c� &����� ���=z� yW�c� &����� ���=z�yW�c� &����� ���=z� QE QE �t�I*�%�� sN��?�?~ |A��� a������?U���{��[��IFe�C"I$��yj�3���?�P�A��u���x� �����|Q*��tߛk2U)�Α�{�K�Xv��N?�#�"�g�����U�\\���vK8	�-��[p8�F+����t�q�2|8��u��LX�0�j:��>թ�c<�:��~�@�F�??����/Ml���O�zF�9[��Y���F���d�?	?��� �A�������/�����RI�� �"Y�$.@�N��/E |��'~��j���H�o��Hk>��*ԩ�������)�uRF~���o�wX�����߳v��w������_&�g�����X�o�l[ղB�ӟ�/ǝ���+�ϋZknڤ-B�6M��gl����T����ހ=J�(��(�*����?�?�'�� ӏ���kʼ9� 'O���� ����:�Z ����Mc�'��� � �z�Z����Mc�'��� � �z�Z ����Mc�'��� � �z�Z����Mc�'��� � �z�Z (�� (�� +���	�h�?h�����Unn57�tIXd�f���'��P��8�к��� �40�~�C��������v���v��� ����4�ESV��m*�-.U����[wn�)S���� [��U����H������'U�5�oΞ'k�>[W��>�l&���}���ɹ]�(���UP&�+����$�)���ee#z�;W�����1�L~���.WG��u��o��6��?`��� L���������Y� ��~О!��6^�ӧa�D�J}�[�� �������w����_���O�QԦ��,me�1�/�F��<�7m��PEP�xs�N����� � ���u��^� ����� d� ���q�z� yW�c� &����� ���=z�yW�c� &����� ���=z� yW�c� &����� ���=z�yW�c� &����� ���=z� QE QE ���Q_��
G�υ> ?b�wǒ�߇�"��I!�O�%�!A�L�W�|��i���7�Y��4�{��<i��P�����1�/�"�j�#�eG)��%5�dR����# �J�O�]���|?��7~���������V� ��ZN����đ���*_��	�_u�4W%ż�,R(tt`��FAuw��:�}��^/��	���F_>�i\i���yJ�����CEr_>,|7�7��e�C�Zg�4�ps=��L����e�D@�{
 >,|L������!���+�o�xr�K��p��D���Uwf���exi?�?>*�o���˿��#�TIt�BKIŤ2LU��$M5��"�2�B�IT+GQ�~'�V~'Y�ZV���K�i�&���n<Cq���r��*Ř�*��U��Z?��=?�^Ӡ���*�+++HlpA�H�v@�@�˿�N]c�y����3X񖱮��V1��j�'�u��^A.#������&V��b$g���C}=� �����?���v<U� ��Z(ʿ�~���W� Ǌ��cG�3Oï��*� ���W� ,k�h�+�?���Uյ�O�kv���ך߉�=jy �i��K���4F��`�TfV'5��E yW�c� &����� ���=z�yW�c� &����� ���=z� yW�c� &����� ���=z�yW�c� &����� ���=z� QE QE QE yoǟٗ��'�.��k�vڣ[�z�D�}dO?��~u��6�5�L?�N��c�ô?�������:��}�H�[�� |o����ӿoЊ(�{ß� �_u�xGP��|����b=P��Ӣ�Y%}>��<-��.�z�� f��	� �����X<y�Q|a�o�Mz"C����9��$�:� ��
c������(���Y� �+�ת�A��/��x{�Z=�����-,��X`�1�QP= ��Q@Q@Q@Q@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@U�X� ɬ|d� ���7O^�^U�X� ɬ|d� ���7O^�@Q@Q@Q@W;��w;�&���/j����&��մ��-��&e>\�I+F���9� �>� �E��� e�� Q]�V�0�`[_���/�-�O�u�}�޴�~"���Z���-�Zm�s�+��[��!�Y�2�9��Oh ��( ��( ��( ��(ʿk�5����O�C� ����kʿk�5����O�C� ����hʿk�5����O�C� ����kʿk�5����O�C� ����h ��( ��( ���h�H�UA,�� ;�u|!� �����|/�|�6�'����(�c�� �%�J3/*I$��UQ�7 |a� ��������߰�����'�>^��W~����Y����Ot�#�0�\�ô� �q��k?����B���D��Y�O$)m����ہ�R1_]~Ο��Ïٓ�ŗï�ZbƑ��Q�dA��N�i�aԞ��Up� �4����F��zh�g�~2|S�5A�ݝB��޸��6� ��'Q�I� #����?�ǟY|���MG�q��)!r �rs� ,����z(��;���e�Vh��Dsxwƚ@#Y�� �V�N�x���7 N��3�%|#�{�˺Ǉ�W�����h?��5h���5�8��^H�"ǻx?�bޭ�����~<����_|ZУ[v� 1ja�l��;g��p���dn��TQE QE QE yW�c� &����� ���=z�yW�c� &����� ���=z� yW�c� &����� ���=z�s� ��|J��~�pi�*��tK�mVxๅᑣfVP�\�J��2J��M�E� ����� ��
� �=V���S��~*� �¿������_�;���-�� )��h�*� �7������|+� �j?�M�E� ����� ��
� �=V�=?��v������?keV��P�xwD��Ljۊ} ���Oc������_�;���-�� )��?�#C7�_�?�q�i?�7j~��gk��
	?#@�4QU���O����]4.�1�;O� �E|��'���^x�$���A6�$� ����<�ϝu}s}2�wb��2�Y�u�P}_@��"{{��X�R������A��_�_�N�_���1�E�ʐ�]G���Z��ۻ��I�[O�3���"�'|U�c�ߴ��O���� ��������vv��;�]:A���s��XE#�&�	����� �@�� �_x��z�|1��/V�<1�f���f}=�2�m��s����� ������d��?�O|4��c�[�]RB�S��z曭�,f0c��O���l�� &B#R���?�)����v?�[�_�SP��^U� 
o�/���_��W� ����� Gc�W� �� �5 z��_��"� ���U� �o��MG�)����v?�[�_�SP�X� ɬ|d� ���7O^�^)�����9����ot_i�^�m�/G���G,{�GW]��2�0�A��� (�� (�� (�� +��&�����ǟ
|@~���%5�\>D?�/$�,C��6K�B���;0��z�������oڳ�i���x�ò6��md1Sku�cv_�E&�G*ʎ2S�J+��w������� ��k#x�v�R�-[T+=i:G#��F>f|�~�'m}��\D��H��у+)�ހE�|L�����߆'��i��-����m27�#A���1�( ���3����⇌�ž���/g9�HG	z��TQݘ
��	Y�O����Qx�բ׾2x�mF��YG,�s�V�i�
Gca��?��?���+L��%�4�KQ]��7!����عFVb�K�Z�*�t-����i�i�^�k����8 �B$j; ����QE QE QE QE QE QE QE QE yoǟٗ��'�.��k�vڣ[�z�D�}dO?��~u��6�5����l���hK�|��|si��,m��d������$稁zQE |��� ۳�������n�i�69���o��2q��C� ���'¯�&��Y��T���/x���q\�o��I���pe�W��J�FAR8�F���~��<=��J�����VP,0A計��U�(��(��(��(��(���
endstream
endobj
31 0 obj
<<
/Length 2250      
/Filter /FlateDecode
>>
stream
x��Z[��~�_��2��_�6$)h��prPxm��q|��޳H���~CR��+�V	�K4E�>CyqW��+��___��[�
��׷����9)��U���L��0���fS�D��ͥ���1{�=�B(&���y1W�ic��ʹ���+׳�(O�P��D�p���q�_�W����Cj/���U��q����X`�n5_�wh�T�������t�p}�'�%�[�ww	�Gж�<�꘺��i�M�Ѿ'j�<aYP6�? s)M�Y��j���S���+��q��l�c�Rm�m�#(�Աޝ�����0��_��n��Z��.�d\[���uIF��y�Fhno��1w��s��B�x;��=�z&�F�YEΡ��r�����W��B�3/da\` �Xn�޽��
��I��/���-~�)�M���?/!X�
�4 @H��P�W���w�5�OY�h�����GZä�� ��}?�a$� %�, �0�Iy��t��hO3F⃨���s(�<�Y9��:f��3	�IGS���b5�u�<�s�2>O��d�ƕ����l�oa�#Bxv"$<��lP_��0q��!�8�,���v��`SX}��F���1̈lӒ�#U�[?��A;�4�G�@_uN�.i+ˌtm�����4<�U�Ȥi�%YC��$�F�J�����)L�ׯ�E���H�c����O�0����C���>�C+5���ap_:8e����o4S@<�Vi���y��G�A��u	Ef���zEal��DJ����������n/G��%���J�pڔ���^����F����^��d������Xh��p�.��E#��$���6�HW�P��P�4��1�V���D�������d�xQ�,R����v��C�i�c�����V�;��C�h��],H��E�ʉ�Hz7"'�J*A�H���~���
���O�-�����Ö�#��$ع�)�w���ֿ.zi�y��0�o�3!q5tF/��ּ9w�Q$�:�9Eɕ����O�,��	�V0Z��qm4�.�a��̠D��A���_8ې����-#��6�t�>����'M+��7��e���i*d^*.zsn%8ʵ�6���AV\��<�V���G�`�,���E��r$]g���� ��xx@��~z��Z?� ����E�F��#��u�bM2��Z��c��I\c���	0��'�K��L;e��=�Qtn4��V�
���־ZS
tHH�S���^ǯ fmܺ�LԻ<o��NoT�	�8�;�3Χ���a��i�4��@�߅���֞��'a�6p
xn[_I Z=�� ��r4�����n�y��0� �/u>��S#�[��=ī��� ����E���s��\m�L	BL;�c���b��z±h��rġ�ě�AJ1��N�N˷��ूz�������o�l� �D�9� ��>#�fz��:F��(7�A<7^8�!��p3Ӷ�A0�k�M�����i=���`��jB�	֎T��W��/0MX�f�h�y_!���Y��ts�N5�:	��-ҿ�n�T��o>΄%�T"�n(*��t�]
m���j�Z_��q����N�����b����D!?ۘ�ٹ�*}Z0��ְ��E"�0CvQ-�Z��0C�AU��2N��٠kA�Z�<�%8�T��F�-�j��{���%�<�����C��T��~�D�����X��>,R��;���v�j�q��M,*��/�D������%�XI߲.��؉I���=B1/O�.ai�`,^��}��Rי�:�L�$��V�:�W�,�uv�$[R����l
���6Rm�[ę^`� �n��u��?L�`J�*xϚ���#�Աh~qY���fҁ�>F��K?�|</����@]|ޣ/�)d�J�� VzV�u^��]=�������}O/]�}���(^>����U�ppv?�c�xf�iX�Y�量�u�L����>,^�y<_����`��&���羹(�mӘ4��������ו�껤����}�����M��������e��q��O�͆+����Ԭ�Ѡ#��m���f����s����8?MZ*��l2�S�j՞R/���n-]\�I^�B�[$_�:�{V�z�v���TI��f&�J�)����(��+Uy�c}��j����UT�s&RH�aNse���������nW
endstream
endobj
37 0 obj
<<
/Length1 842
/Length2 1325
/Length3 0
/Length 1902      
/Filter /FlateDecode
>>
stream
xڍRyTSwY�t*j|PV1&���	�C�X� K!6!�%</�����ed�@� �
�
�e�#"j��Z�J�����9��;�w�{����At�G|��':C��B<�%���e�Q�"��ga�%,1"@�Yb����B!vt��8ɐ�H�t!4����$0F�L���`� l1x�#̗��\ۿ�9���b�@(�
A�����ʗA��6�@�^�8��E��K���c����( �}��+��7�b��O�5+���=U��#l��&�#�/"� D̎��,��㷢 �#(����b)����v�D�]$,X��x>K�Q �|� ��B��`}3�����]���lAy����B���Cd(��%)���zT �R�8�8	�
�����N�쐰�����"��/�K�"�"�D��rr�q�?��T,���ǘ!"�" "v)���-| �'F��)�B	x�=�w�`n1=�h����-
*^�Pl�a.�� )`�n�[�v�s4���Z����;�/q��ogwo���ո�۞)o�6����T%��3d��c��ɨ���d�Z6hf54\�|by��6~r`<�\�C/�m�u���������X�L_^Ҷ���c��F��j�x0�o\��'mb'�W��'�=��ޔz��JH1@Z��M�8lů��ن�����v���r�qk�5�
Mމ��%�g�-*�g)�j!�YV>�Pc���'�^�Z��o
h0�p�����{d���_U��P�; R��i1���|vD��s���s����D�#z��Y��y{߁�Z��8L�Ҽ���o~LZ�(��wpQ�t{����L/�.�y�k�����O�^4 �i����RѼ>�|��Iy{����_*˙k�t�j���d푘�V��.�7�B�yyfE�je�^tevt�������9�2�V,�}1���a����Zk������'��Gt֌�Z�?�]nx8N�u�?�������@&����܄'�#õ�:G���Ue�Zڝk�_c�����y�-���W�����:�������ѕ�h�ߦ{�������}6����R%���x�*/��t��QO<x��s�������r]�X�yS�/�\5�(y�ɶ���[����W˦��z��%S�;�?/)QtV}1�F��*p1�}�tJ��r|<�ģ+;鵮Gu�v��B���?kv�ٷ���YR���h|��O��ˮ�X�{�6MӨ�b��3�����vH���h��bx��O�p������P4y ��m��E��t����c�I-���K��5n��u�֪C[&��a�1�����tJ��L�,���L�g����z��Rw�t�|n�(��f�}Ŗ�:�f`k��,i�Nn�o3��Mu�h8�7�V��C����P�K��o>8ӠT����Σ��m"ߖ�i��i45�wO>b6����^m�ZdT���ft�1iPvb���D����}�\��l���gdtN$���c��&<�{=V�7��i-�����e�[�W���^���{ ǟ��N==����d�tp Y�Nw�\����:3ӗzV=P���h]o5<s�ὤ������4K���2���c��\Rw�jY�����VMqЂYK+kSX��KLw�:񜤺rPIX�B�>��}AޣE��-���2�ʴ��� ��{w���+��)O�G3�.��[��-!cu��)r�oԆީ r��Û������.��%��>��v�.TX��J.g�?��qfդS_��wO�ƭIm�����nn�M���}Y�5�76�k�7���W�.Tr*R���\�ل��(n�Y�E��̴�I��hu�*\�;�����
endstream
endobj
39 0 obj
<<
/Length1 996
/Length2 15657
/Length3 0
/Length 16411     
/Filter /FlateDecode
>>
stream
x�}�st���-vԱ]�m۶��m;�ضѱ�qǶm'�����>��}ϸ���5�\k�5��}Ǩ"#RT�2�7��۹�1�3r�\�,���mL��!F&X22'����������4(�� �L��̬�l� &.�x�r��F�),,�\ ..��0@��h���9Y�Y�-g� �ۻm��N fFFv���1�������$=,����Dc���,�?r����L���M]�;�tr��@�_� �����xL�f���.� (E�<�,�-\ �&TGrr����_C *��.@[g���������_]�� !��?E� e�3����?�,�@K������4��[��wS'#S����5�����,� ;��,��T\��� #;S��=���ab�j��d	t�;��/����/j�����T�G��_��;fN@�_�܌,m��m�< g `��������jNo�d��/����Z��i��������_����?���C2������i��������j)��[ٙ� ���,��-=����.& 3#��7�_\ퟝm,퀊�Ζ�\O #��ȩZX�X���l�I�L���+�+�AYECKF���e��=SK;�����������,�\T=���:�3�������� �0�s+��~�����E�����7����r&fV. ����4qurڹ�����c3˿��@��%{�����:̼�	Q�^�/�xؑ�G[�*y�i�w������2�3.�#*� ܞ�-"O��I�5��g?r�֭�7.ֺ짶�d=r�pg<f����o:/�˾���f,锚)�.���Ke�~�#��f�;_�3>vLzޞ�����q3��ҨP'�5^̮�5f�>F�z�]S.�"N��#l]Y[��r�Q����}�������X��N#��g�<�7�k{���	7f���{��O77��1�W�D����Y�q�Իf6|l�I.�_�f�<ӡ,����{�U��L����a��R��I ��Hk!�Y�,<z9BER��E#g�YL�K
NC�I���N��.���/��Uܨ1a��u�<L��D[���RΗ8���� 4���q��f���������l�2l�eW���G}.��M� �[�`��#f~�����;I�G�Ʃ���ŉ��� \|�ǆ��(�A$T��G��T�֍IJ0�qt�=YQ��2w��!�1�����XH���l`%�$7__C�6�۫�=���+M��5fX겈@p�=ԧQ�#��=��SZy7�I�5�6��wNN�Y~h�X�$��N��`EV��<
��Y�	�ʉ�Y/�V3��	H�;3ݵ�6��Lߘ<&9�qNx;`}U�<�U���v�hV^w�s���}���FR�Ȧ���U��m�{�]�F���A�BeH{���ʯ0.��{sv^k��rB��iK�K�u:\�^X3@�T������	�%�F��^�E�)�E�����qx����e�s��!�\����J{Ɯ-kI���7�/�N �:sz�2b��ͮD�)��n�9�9v�ڐ��4�=�A��@J�۞��
��3~6�
R�P`�Yr�����>�Bx'䧆Z�!|��8�X}�AQ�`�]lhOJ�g���t&v��/AX��q�/�m�}���h������#���?7��+��4Cn��av1�X�2�1˨X�=�Td��K�+&?��~K�K$�sl��(��Ν��Ku��`��>���9�pF�M�D��}�E���W<L��u	�A���`%��t�KV��e���nu�v���T�TN�)��w�T��9���K��Q`i!���e��]vczq�K���*����h�m�"����WU�7]��ɺ��?,�- ��;
�^l�r��
�bu�4)�a<�L�k?=�T.P�΅A}n���_���ä`@jr�̏!�ZUf+�T�-��1��Ո������fϏ���?��I�C���/�3�+���(����r�ԵBQk�Cp⨘�nNiY�:��o���4�$� '[X(OG�ѻ-���%�	:c���-��P?����z�_H�-)V˙/>�M
'4�7���HͰ�HA��X�& �^��Z2]$C�,0�'Oˣά�2H�����Lq��.M�h Y��lo ��|�X	�z��kj�e؁
�ݐ�Sw�,_�d�|�# +��̾$Q���T�r������g��V[��^�D��Q��OZDݑ>TW���1�4|���D��t�Sj�<�2�?.�c�/��ؑ953:$@����b���ңk#�DC9}��Ώ�Խ��Q�w��>rA�P�_A�_�\��ΰ+�Liǧ� ��K��Z����CA�ab� ��M�]]��e�;�p+�V�����)���5Cw�C��>�Π�z��֬"9�Rkr�Ij�BX�q����	���=�bS��l1���v��/	�&�\��-�#���uft4�-�Bmi�Ő9�F�^Ó2]E�GBԈ��ݣ��
������@���ه�S�W<�A�a�d��;?9�2T�7��Aa(�ʊ�νu�צ���;v��n8�''��3�|V���,��m{��:�*&P. j�>t	��B ���7��~�)9�(G����x��?e.s�Bc�Ȟ�OQ\Õ�D[P��%6��b�w0׃���t����������C��(H���5��M{�c�1���z��	��ߍ�uN��8'��6�����I�:7�D߽t�!���&�cT� �=��f�wRg�u�V^	��c���� ��v��%А��7W�x�� *��֞i}A��B�A��z��(�=��A(F�Pθ5��Ct�D�L�,(u��y]��/��c��;�c8�oī5C߷Y��y�� ,&Y�$kH}��`�����h�r6"���x/|3�[U)�s�3���ϭ�6�����D�o�����e>��_���=ȱ���S����(1��^V���/R���g�]8d�ۅ/M}����r=q6����֓d����2KJ46����3߫��+c�av�*��CwP��a��:^c�Xd�B�?L�yC��Fd�r��1�O�����OZ͔KH3�+��� ���n��vQ~!�84:�!Ml�x2К�u�W�Ĕ|O��Zį���S�Z�%����tΈsv�t]'���i�z�Q��T�����_6J?�\�1����P�im'7q��@��/�ʥ+�B[H���-��觍�T��Ct����{	n_��h��������{c�T�"���]5�������VG��~aێ�F��9Q��+2���O���d����i����~[2��V�����ݞ�����̊!���/)�%Mж|d؋�1��>�tV6;�Y��A]���/��,���)�c���nb��lSl)�m�G�b�sZ��k^ �2H_
jR,]���������{b��[zY��{F�C=�5}-�X�ti��'�^@�_Z�׍菭O�U�O ��j�8�4(�h��4��J}M�,�����:ig%]B7�*�������U�v�r�	��
��[ˑ���8��ڵ�ȶ�!���!��~g�5el���,��w�-����ɖ`�=�a���j=%��jn K�1uQ��&?v�~�nw��d��)V���hڡ�A�0L�}n�4�@y�n�M�G}�T��5��Gl�����˔�?ĩI2+u$�a� 33 ����+�����'w�V��S�7����!����6Oup������4���J��|-T՘��@��܉���K�h\1�=�X,���̚���'�J��)Ea��U��[��w���M�|=�Q���$�&x]��3�N3���l��h��4=T���+%6Op]��-�W�]<���I�P�$����[$��~7)�8/DYQ	����5~���<�b�<Ei���^R2%{�Ja��[ZXB�O��GtF`����c��,^�
A~���#���p6L�r��2�F$A���xi��P��5���ӈ�Zﴎ�ʲ b�C�fp�s �o�70-l�I�{(���.�޸�3���4����g�/0��S@���=N@�����C�B2�E���g,��<��d�'�" $�,d�����Wse�*�ߐ�,�k}ˈ�G{W*V�	�T�����$g֑�/�&���t�4N�o:�׳�hoﺫ���w��䞷�^��Jx������bJ6s�N�q�\Mf ^��0Ore׊DL�E�nV���?���U��,3ҕ�k=Ǉ[y��T�f;f�0f�ؚG ��U�I�N���XE���b��u�=���#�o�a�
ך�9,j�� �d�e�E"�K����s�#��s�F~��%~��׻��X��n:&��թ�zQ	���d(�F�%G�/��$N���g4ޓ��4+�LU�jQ��!��=|�� M='!6ޜ"��� ~7�n���mY5Y�n���rDB]g�(�ҷ���bd�י�a��9ҺH`k9R9˟E�U�1GU"B�������٠�2�O'�Lzb�s�gt��X� ��%��s���F�Ƴ���ʊz�	�.��I?6�2�u3G.m�.�{K\s��Bo鼙�Q�8�B1�A[��s���H��1fͰ�i�&9�*VBk,�Ĕ59���X'|��	^1d�N�֚�ߢ��:ܫo��S߀�U(�@�KR�g$Qk�� ��.̹�~�GB��(�=S �I�{Ӑ���I�<ĭ*N#!R��S�MƙFj>�9V8o�����L��Jկ�Ko%�45�+�i�['��*i����"JN���x��2Y
;$��1x~2v�p��{��:��+X��\�%�g�
�I|{VO�� �XXtoX[5�y�������=�s�"ͪ�mVO�O��
�?�EM��j@��;d�&T_�gT��׆%I��M�Yƈ!d������lDP<��<�K��砛Dut~D������9������KU��y]H�?�h��F�qg�Q��.z�]J���=��Ȕ�H�5n9�NW8Z�Σ�R�h/���Gϐw�V�6!? S|f�-	C��Y��%s�^ (tTXR0���hb�6;H���)fȧ|�K,�&ЪF��n��_��m=tx�5��՘+�ŋ���V�ݤ�i����~�Q���f�`0��u��庬S�|�;��s8��~E���=��Jc�+���2�"*p:�>݈h����)���K$��a�,L�[ćJ򠤅��)*����,����aug�%����/Wk�����@(��#K5t��aﲝ����I���$:$!n�-v���%^��F��E.� >�g��ڕ=��&�E'��l4����(�%ӕ��-N�c�B��S,_�g�^~L���f�<����8ۑКW&�Q(�O��&|Kld'��+{�O�&.��gY�| �2�C�m��P�����m�sp��T���ǥ&/�aPep��� �>T��0�Q�;�v�Ѧ���0�е�����R"N�ra��-[Ke*&}Y̑�]Vf�A�:m2~��4�y�/�(H�o8 բ���<7YQ
���\)�����ͯ������'���׌:P�8
?4��c7O��5:"�E������xXL�@Ȫ�I�g�OE;���遼��55�h��4���,l��	x��n�v�+2!�DKi�r��	��h�km��F^V��ӕlzB栞��	����x5x�n(̍���I���2`v��$��� ���^�V�-0�L��wm-"Xf�:�Nc�Q�-��M?�>�YV���d�]�N��O�|s���������"~����%d�i�Df��za��3���6�e�
�HꎭjpғT��9����f<$�A��B�Be�!�O�(jfgbm �Y�#�Ŏ�����.M���&0�����?:�?_��������]!�Ҁ'M`J�?ِ���u۹���瞏�Z��+�H��¸�uw�2�qIj�|������x}�����-�`Ňo��˻:����}ȅ����9�:yh4�92���!ڷ�>q�J���]\*K��Yd�8#C��E���?��f�:��U�����ǩ(7g�9�%rs��C�cf�P98�l?�M����8d�!�sc�5�8wI�Zʻ�C��a���nVG�]�hH�&N�R��=]�x
���)�vuմ�hp|zp@���Du=P��@�����z���U�%:0�b����z�P ����Im���;�n���#a�9�E���)�do@kz���Q�oKր���E2���j4��?���0=�F�X�T�9|�F���� �9?Jה���֖[#�GM��e��^r�s;yHH2%Cعs®V����X�
���:���R�.K�XjY�Oj)�h�|lt7FZp�BoRpJ�F�?֎�si�a������d���.�t��Bvt�#Q�d)�\4Y}"�{�ӦCjm�d&�}M��~��G�-Ȅ���*~'{+M�Y~�kg3��������M�\5:�� ���/[�n��n�nJ�������q�s���-?�'���5��s]�Lw������붬�}uz��������AB����%&zЮ���]!���tO�.�Ӑ�E<rE�2��+��
��g<+�P�����R����>�4��g������^��١x�X���\�&v�9�ߟ�Fzd�4�2փ���iT�̤^L�f�y&�m��Q`Lɒ/&+ml�6�����st,�G�X�I����=��D��[��510y0��� k���ԋT���˛dG���H�n U6�~�Eg���}��]�ȏ=�: H6���,��}JO	�Dv?�Ji�o>M5���7�����0<�NH���5�Y���ˮ����y�ފ�y�e�1�ϖ���/N�7�(��/WX�=nBy![��Q�r�ģ	D_y�w�U�]��{����Ȼ��^tP�աU�-m/�F(�����z���ۚJx�A������o����[5�.k|����L�aLP$��:@:�a�R�'݁m���e�������;��D9��mݻ�q%�m�g;�J� �L�:�6N?�Mظ�/�"a	��+����Ió�<7�B�v�q���K»cI�� }1�p~���;���a^;Gk�a�@'�W����W{$w��š��z��7�I�m�v�ϯ�% "�ZͶ�(Ol2	�gt�ㅊ�;�TN�ѥb4n���Jw^�cԻݢ|��V�4�Q_y��w �
����~?�����i���z��i�-S0�HjEڅ��F^z��ۧ$�E�1�tG�MڕD�x�F[�|��U3Eb�����:��0#����U�xR>��?�n�����~�X�iF��}�3��e,���*ܳS��хś��x�7*�ݎ>e��n�!�������1VM�4�̱?o����3v8�̹K[�?	�P���n�t�Z@l�߀��+��8��T���B1��������\?	���L��β*\c��&+�P��O��377���*B�4�&c�T`����q�v��a��J9*{���|��;x�&y���zNK����?��h��G�r�x����L\�.^�ÎE $�X!%&tj-ߐ����`��%q�Tʭ4+�wb�Qy�>��1�*��w�3c�R�vpaNuJ�u��?���z
�a)H�#D����4�A��J���P��Ϡ��mbt!;�+E��5g1�u7��8�+z�e�e����A/��b��ʔ�`D���g���ih����U4�uz��p:(����w�>9�j�����F_2?�����;��Ch�a�ܫ&^p��BL۞�NS�%��X�#�6�K�rD�'�꫑��h���}W�������Y��߂C�|��@B��i���r��z���a�S�NV��`;��)4E6%�q?�섇j���j��2 B$���YU�/�Y�q����5,�'�(ܨ�rcd���2�Q�)��3L;�0;3Z���
M�FּP��������*�
뀰�����gH�w$m]��R0}���=%�	]�n?���Kg}��j�L>��������z�Ո)�](�rth-mO��9��N�L���"��F�0;vxS��&HO��sn4ۈ��p�E���'㴹�_���5��~�-$�l��jJ�H.�Ǎ����E�S�Ϫc��<)�����:���4�~��/�����i�Z�V����fb�6�Ļ�������B�Tzϵ�q7�d!L-�m���Ms�P��;�f?_�8�k �O�%��;K�C��9����RzY����O"�|~��W��g�5O�z�&�eL񰌺����n�`���4��Mf���.�(l���ɔ����3�L``��ObZ�}�DLo`�N�TZ�հ �ҷ��Q����L��8ŲwRY<S�`:ӖnĬq��
D��/�!dfp�s|Pԥ����؜�vUj�������tE&u���jN��ώ�`ط�bjָ%8lW����F�����qlr@i�n���)���B�tBF�r�s�JF5��:�$�����@B���#����It��L�>W��za��R���d��4�&:�O֟Úm�����I�NY�/�R�Y����Aݑ��OIT�i�ͫ��C3
Pp��b�dHd�����5�k��b�T��v]#1��>��}�����E"L|�Q��A�A��w�����li3;=6�}4��A�<��]Z�T
��ORje�)@5||�c�9jg������ ������/L�����<a̘uI�QK
�~���\/�96^��$�U�RF��1>��1���~�oz,ST����;U#8�BRW�<�@����s|��7@3�2)f���������K)��k�^���<��ujOR a�Y�o���jƮ�k��|-�Fke���J����O&y�[z��(mn �ьc��œ7.��V��s���&u�ok� Z/;_�t�X���*��:-s(:��^;lf��t�����L�0����6�P|�<+y���&�P2����p5y��j�)�)����C�Vqf�S{P�z�k�f�<� ���

G���)� �c<�K�$�-���S�r˕�g�� ���d��_����(e�M�yD���9��Y{��m�{c�|�)1w;Kv�
y�R����b�IywG�u��O�0���\���1����kH�T�G�AWQ�=�ꊔK<Y��yG's̠ΰ�E�
Yd[������	b�w�d��A�Y�A�]nP9�y���:̧�WW^�la�]|��i&s��C�=��)]M������nW�S���'�iƍ�&�>E���pvQ:�O�e����A?��ca�~�	yUz��`�zx�͓�~��,����S�����Te�����g��?0�l�:��޵:$�&]s�@F�c�j��$|0��'ߟc�)4.|WF��.��]�ך���B!G �i3f��\&�R���I�RL{rm����m�a���.-��	�a�.ܑ\8�F�ѻ�R��8vu,���S&��4GJ�B��@,������4���<`��/۝��"�I��ѳv�B���2C)md��kg������>4��8�S�L��ԁ��a�0�ioC6�pE� '!��qm0�o�nT��x�o�e� R���`z'�?�u�E�cT��CȎ�4Y�������U~�����A#���`X�E��+�đ/���z�6�Z�u͵/'O^�8%g�;
��19P�����h�~�e/Xvp��[-z�<C?��l��͍�t��fB�����/d	�̑�^��AW��ِ��#؜I?�ط
�N�=a��}��vq�ѥF��FH���e�6�Swn�R���Q��<#3�X2�F8��ϣ���jQ鼓�	���nw���E��y�?tU��G�nyvt3"�ʡv�a�wrN����E	��y�|5W� �\�ȋ�S�ynX�O�����Q�>6#�1�4E�f�c�4���ӄ���ՙ��7t��	AU~��~/\!��"9.�/� ��fs��g�^��A�p=���LZHls��1|�e���4�tq.*¦�2'��j[S?͌����=<}Z���e�2�1;�р:�\Pqo����#�>����*w�� �a���zx^W�����#�=#�6o5	/���
1������V��ɅUW�d�&�g��g��d��EL/�}�c5�X��Us��I���&f/��|J-}8�2���"�)Z)t��'7��4b��
%a'�;��z���ݭ1)�5*>824�L>!�V�:�C���9x�YL,`�Չ]1�F�:�v7�XgD�3�p`�q��A��=P�O�h��������Ψ��DB�4kr��(ԛ��|���N���Wy-�I%D(�/��ο�~��Q�(j��������1���&��qi�Ԋ}@������������j��Z�}��Q�mR�ׂ �G�KӺ�Qz;�35�MA��D!��(���)3�Օ
/� NqO���sT���cKy­����9F��]��D2;����:M6C�bĆ7�8�!rF$77>����	UnP����X�?��#�$�0�f$��m�=��-���I�:� �^MY]�e��䌬W���	��1ik��:>��O�b�ƞ8�3.",`j[��M6���|Ģ��^�7����jE��'Ōɡb�Pq�pTņi���.J�m6[�2	g6�ͩ�Y��"9�we�P���vz88���m�+�\셹<�:�~�n��p���Y��9�.��m���M�����nĹ�K�Ӕ�]J�p���̯�w�FB���b_��Y�,*��BVض�R���H#X4���	{hǨ[Rݧ_�yEe�A?P�Ѩ4B�DE�W-�=xU�)׶y�ν��#�j�@0�n�,�l<��!��|�&�T�0�iz���bK�[d+�w����5�o8�f�)h�2�mw�yy��a��!����
AmLC��I�&
Յ��@W���o%�wv��)����F�uܖ�R>e8 �H;��)�ԓ��	B_VdE��u:i(6���-$���_:c��Q��o��[��1�z�;�I��̓b�g��j����Hc�/Q��}�����y�O���5�-T1k�J��'m��;zd�0X
>ޅs���0=���9�q�?9$����i�I��@��n�K~혲�$ݿDFp�I��]��p��
����T]=��?#֫J�u���u��rgL)����v�4������x�ߔe���_������ �j�<݌qi�R��.l��o]�n���A3*�7�|"h�{ '�ej{�d���������1�KT�aJ�(6�HӭBp5�]uQJM=-�VR�Q��a봲p7�bƸ+��L|���$�n�6xO���a��$o؂ILH�JC��$�'g�X��{ 9@ Q�`��H�*$�^��l�~�1�z�y[ss� �z�2��]���Zl���Lt�"�oSb
=�I]PQg\�h����y��};p�D��4�J|ޏ}_V�_c��v��͑��^ckd*s�8o�Z(��N�k��m��,���^l�[��gk��l���͈����+�cG���S���NV²H���]�zsE{�n��k'2�������.� ";oC��ۙ�A�r���}�.������̝B���`���+�e��<,/TJ��ٱ�x�2��U�N����=T���S,&���]h�C�
:�$
���˙R�����K���h� �Eפq��8����噝��!(�v�Х�R�t�A]C>Y�-j9\��*g6&j��ze«�D�����)�q���1��
]�L<�\��2;�f��-'��)�� 3���!~� 6"/JރTw��eQ���LҔ��cW�Za'�z���ò��?lH��z�� ;�;�Jh�*�,䨪���ynʉ]�cxQ�x��f*y���Ŵ]bek��U:�/���n��� =x
z�{�wq�$�X��9/�omdK��ia-{P�Qs~������d�_�F��(#��_S�Ŧ�S�'� �F���Y���� �\_oPE0d@K ��z�iw8�ׄ�'��/@{��h�z�'oCFʽϗ��G�^?Xۜ&O����hB-���ķ4�δ� ���A���ٝ�f�<L��u<_=��to;��QJd)/��K_N�eS�K��V�D.�=���V��n�[�1�.	S��!y�����eI��v�3��+*.O����aa(��{$��c�+��O����ş�.`d�_���@�5R&�l���f�&�2;�
�;��g�wP�vZg�=ƧՏ��k�:��;��jK�8�ZW<y|�TcH�r���u(��7|���c��^���s�x$I9��.	I��ѯ�"SZ��KNr�A����:l�����a�����L4�L�!q�w�c*oR���%C1��X?��z�C��R�����*Jf�r�^祯5 [v�$�\_���`D�9I�b�c)!���
:��W[xm:=��^��W
����>���W���4��i�h]쎾�_�a#��,������O'�ܺ���q[���ȯ���Ə��O����m�8S����c���'P�+��s(�&�q�ѲpA�Kx��+��>{���&D��>��Û�LT��o���$�����l��]���d��]Ci�`�kI�8��r�?��3�>������^�.�F�߃K#W4��~4.ñϠ�d{����c31 ���oN�ڥ�Z�~�����{��h���H�`�Ԃ��2��K���+��~���G��y(-ƫ�	�Y��8��T����ܚ�V�q��9c�]B��}@s$�戌2��S�ʉ~�+B[���CpYT��t����r��Vw,�Q�,���0	�}�W�H�֠�G,�(O/`���W���A�K��Oδ��("�2�cY.X��o��Qzjt̿	��l�h�&L�&���Ϗ?ˢ�d-tl��,�������t~d�ޣ !$[FzN�e��>ϓ��4�i�]e�q�m$Q%C�R>i�:��T�R�@�j�r}2?yk��j��*m*��ŠZ�?����[�����>c4e�j#�k��$���Иp�4��ĩ�ܯS����9�ˁ�yy���1:�̴�X�R�{Q�z��JȔk
���.k��Ԫ9�{SK�OU�E�d�׮�:���Գ������֟[<b���-�}�|���i�y�c����%�3ׂ���4-��4�x����)"0��?�������q��,z�yVJ�@�3kh�[>��S;�.Nz��b��	�(6Ve��u<
���,s�:���ݴ���� �z��q���f����߅<k�r6�[8J���7���!U�}1���UDD5(�<A�ce���KfS	���8�{Z*�wh\��j�ۚx)0�9:�vm:A�wˮֶ�3L{��'鉯!:��<g?6��YN�ࣲ�t*}�	޿��V�:��v�i|n5�=�{sqGύ�/�|��$hn�a#���¨	|�WfW�A�)>8��� ��bћ2��-�xBSr8pF��*�P�~�Q�|��-��YS� �Ę<^���)O���P���q=��v�o	�(���%��MP$z�=�_��pc�q�E24�\���V2��|�|��E���Б�!�Sf�4�W�t���Y�=X�b~�
"�\Oװ:�K�V��H�e�0چ��%E��8��*"qJ���1�%��J�g�~�_tRL�m�F��k�.�Ϙ4���y��TGt:����ӹW�٧�k�!���$)�9X�SC�����*,}���V�c�=�5!N�:��a ������u�p�2�ɧEQ�f-O����7"3EZe�L��f�{�� ��?�?|�����>kc�]��)�Ne�9?�}N>$���RX�tÏ8����g�f��<�ũe�ͳs٫���f�_��0�9scD�C^W���m�j@��W�$���7_,�H
��s��&�70O����<J��7п.��:�nx�?FĊ���AO�rű�DR2i��K̗O�,<�(��L�-�G�cV�Nl��e��K������I��aW���Ǔf�>���r�˲L�R�4����o��'�
�� /�%�=��bя�� ���K84-��[�䦔������3�z>Rd| l	VK�W
���ﭾNa"�iѡf��/�C�"=m(�{�e��[(������נ��F��7�~��]X�5e���i��!2�шe
�
E�Oư)w�:�*F�VF�Q�w�W����cԺG$a@2'�5�j]�b�����Fp�j����ˠ8����9o�)��������7�̖F��~(�
�~��"/!����d�S�7xk ��I��-�������5T��sw���?G$���V&�6��M�6j��Z�;�_�H ���������Ş1�dI^�V�%_�t�4�ƺ�fy>�d��V8r+H#0X�"y�0T�]E���a��ga�K�MAb6���/>�ړ՞⌓�5o= 	<IM07��k5s�B5B�1>.��&1�pȈ�h!^��S�C�z�?Z!��êT$C�S��m�){�_�TfXf�y�q�h��xO��?�i���;&�|6���(���a��	��f��{�s��v���KWd>ç��%n�3<�B�~q٤���F�u��� ҅n�g���뉁���ou5� x�^�7�ہ��DZjv��L�ł�?��`�����RCS)����Fω[�e@M�T��a,�bWA�q\<
�eڰ��ėT-�s?��Q�����S{ا��qh�5A5J���aV?�q������D���Y����]wa��z�B�A80���{mn[+4�V��q��$c��5�ҕ�](*`Nl �$=�hta#�z�6�Ҟj�y��9-=��P-�aʯ��X/�ynK��'�)�iD�FgQM�k�C1aL�g �m�T���s��k�ey6��h-6/[~�[Y�6�%0Q�<r�1�F�!��A`p{�:u�Ύ������l���<�>3)�FU��)�s���l{��2��k�"�,���~�SE�:�|�+��F� -�x�'��k�]r{��{�Gn���JF4��Έ=���+]����#@���
�K�M���*:À����T����a��� _��L�~��2��ĲBt�֥52F���4ɵ���$wE�D�����=��.�_Oi���g�^��g��ޚ(*q�������"���՟S�A�	���p������4B��>Yƾ��W�|�ȥ�>�>�^�fq(y=����T(�I����ە�a��5 ?�CP�������a�U*�v;���=���!6ͻ��[w�Q��!�����=�D�Jm�z����P��,H�� lf*� m��l�L��^� �f&�M���8�/����kN���&����3�n8^�Z<��aөB��nz�H���{Բ� q3MoXG��h�D��\�h [��\���ML����#��ڄ�Ԍ0�����ʛg�s�׈����6&nM����B�i��7��<�鋶�~k(��吋���s��\���Q�_ iy|��e�|�-�n^?��L���h�1">�$L6��~�[�2L*���J��;6�j�����X�t�k����w�^|�l;�(nK�W��V��&���OqE�^���*�x��$0r|�
�ً�X��,4K�;��2<�u�ǁ��U��ӎu����+��C�œ��ܷ��2�YՆY�.Ǧxad�gⶭ���`��Z�R�<�g|���vW�9�><�4�y�%�<l� �~i�?|`56��w��?4O7���K%���p�;�;=L61��y�~�dX��9�հN}�CS4���JVWh&Og��Ӧ%,�#`b=|\Qfg�!�[X�5�5ou��f�`�y�wRb~Ď��uݢ���3h�d}q'̷+�C�_I�y3ϙ2���N��5�
RL�w�&%�������#��є1F���u.���tᄫ!���Zͤh%�)�>J���Y��gZ�Fs��a�s��46Ea�&q�e#�4�+�
2�^��m�U'�Ɔn�W�w�ӧ��;BObq��d��vZ3����O����3M�#�L:���!A�!�[�Y�o��`^���X��{��5�K����ÿ
endstream
endobj
41 0 obj
<<
/Length1 1008
/Length2 17519
/Length3 0
/Length 18274     
/Filter /FlateDecode
>>
stream
x�|���[�-Z����U��.۶m۶mu�v�m[]���{���w�y��bf��̑c��ŷ")�����������3-#@����V������������CJ*�hb�lag+l�l�P31�9� ��\�\����Te\���B��89���8aH�F&�N& ��U-L-��3�d�\MlMLl� {SC��������A:FF���ߎ�&f�0��0��5�02��o�b��1WG��L�Ş𗻱�������^���/ ���������3��oKN�� ��	@������	 akd�ho����1@����O�@�������TX8L,���r6�����o���I��Ml� v���a���`a�[	�bk�����0�5��[���Fv.�Ύ&N�;�Ÿ���Z�Gh:��?���e�W��Ɏ& SG��2�XXZ�p�LL ����\���.ftv�f����]�ͥ��≺X[����ￊ��Q��l,�=�w��D���G����g�5�60��e�$j�nb,o�ld05��{�����3���������?�@����?b��FV�&NN ���Ll��'翃�˘^^NDP\��܆A"w�����=�56p4�_����������?E���o[���ƹ��9��?�����$(h��E����e�K��'����4rqt4�u��2���mS���������-�q[�ge8�a�O
k��};�Ì~�p;�(�U����~p'�dW�I�ћuF�U����A�&4�@��2+PZx�%Co�>�d��~n��J�!��s�eB[�?/��z^�Y�r�0eN�POYqV��Z.����1���f���e���h �<NϏ�]��D��<�S��drɬ1�6 �I�v�tr�#=��垵]�K�&�Es�WO�o((���S���u�8:�ΰyF��=r3��tG�9�d;?����t�~i}a�I3����H�kv��Ə����~�#����l�*�-���10�6�PRB�5�����ۜA�^z���f�5׈9��=YNΠ"���I��Io��s4�nŬbG�����J��1���n�8���q+���H娀�mJ����X��~茡�j��9��7�ʲ,ܴ'uh�9���L�o�� �HȌ'_	�v}���{�AY9x�TQ�`�Ȱ޿qI�h�O�'���vԔ�p�[q��뽸�N%��g����P�m���X �hۿ9���yۃ&T3,�.q)G�X}+qI�S-����+�牘�*��ċ�]S�WGX%!\��hQ��
?��)�*�0w��p���J�������P��L߲*h�DOW�u��$[>�ڔ9���q��إ_�Z��5I�c����K:�(�!����%#'%��
J��ֈ/Oo�C�~��ɥ��gߝ�L�W0�'Y��E&�+����a0���U�� �Y�L�;@�5�ŕ�������gQө���V�	����W`Ⱥ�^��݌�$<'L���@=S�"7h��/�겭:Q� ӥT
x�Z�$�����^ں��_:K�>�3C�p_��o���ӊ������V�bCL��R���폨�%{$���b�H���EM(��k_����Na����*9q��H���n|���<H�h�.�P�v\fo��X�����^���!l���P1�o딢a����ag!H��)K69Z�6_+�_���|S��G�ouFf��p�ڭm^����W� �M"4[��LJ�ϼ��	��1X�E�/��4��˘�I*5��IY�<����X�4a�o�Q�g�iJ?��Y��뀛�U��Xˡ<icF��S|�p���eW&�j�{1Լ��@z�_�޲M��T�Y�I~�\������y�_���Q�ux�%
|�[u�=�C���f(�9|�Wd����^�g��l;�_|a��Ą�Fmf��m�~]ٹ]i|>��7����0ɾ`x�M����ȉ,z�D���p���d{���Cu���%c�Zo0��&�UC5�е-�O�9a�M��>��U=�a��6]�{�Y��#�� $�v�t�� �@;�Tg刚��nI�
�VT�JY�W�/�3���_St���}T�|��6�Q�Kw(���d\=Qve;h&�sTcM���t�hnO�8�+Ba0ILs"F��r��m�d���s��w�^7�Oژ4> f�ҝf~�L����^�Y�9&8��lGc>��):}��ݽ���r����e	���]W�k(���R���)�<��Kt�u�����FKf(�Z󧶒%�9����Q���"��G�`�f����xoL�We���<�[ءӯR;����c*t�x��!�'L����݄_d/��ٶ�����$�s�
|ޏn	G P�`{>���-s�>-�lq���j9��l�X)6U��.ͥzS�W&�!KZ��[y�F�4������9��s���ժ"�M���%5��Y�(�T�d�$���h�g��c�t�WL�(ML.{��<�BL����oAi�4ߪ�F��B�!,�d�wR�Z��1^�T"�||�TA�&|�ԄX�P�7�is�C�C�z^����l�Y�Y�o�!dA��Εa��V#�V̮Cُq�U�J+Z/�%�Q�������"��	fQvCŒ�r��yBp�=����.xޮ@%M@��:�ƱYc$8
:}�tk���wl�=�*��:L�F��C���rN��&���B���׭�%G=Z���3NV��֞���s������ak��Ǥ����t/��Y��Nn���O�!�A~�_ �|�e=lP��x2���X"���3 ��K2,�s�d�(o+R���J�?�����y�Fjd�Z/w�%~#�W����S2kS�e��$&W�Wr�n�*������ɝ�~9��D���+�oL�%E~������g�� ���BHc� �='���j�ϥP�%�2mr��"�咊	z�Y�Q�jr*��-������o=ս�%q�-�	%�����"�VMF��=��b��쁲>1Jj*y�#�I��bi���}J��П�|��8���D(@��K��0��7dTj�f� ]�5 	�F�����ٱ�����OK ~}1l\�L:�����Ta�c�3Е��Y�B0e�-w�y���CUt�������?��J�:�]�\��#�xv-���h��2+����;�u�qCrO8(���VG�a�|
F�������������Y�"ްe�y�O<�)�u�Q�+{�J�'ܕ�o�����_�r��Yu���)5�rN0x������2�nK�?j&m8	�v7����ZV'Z�e�p����X�[�ZKofv�(���D"5�;B�#���.��M��-��Ӥd �l������B"Q&i�m���.7P	�q6�H�C�'!���1j�+���(�3W �?�Q��5�d���(���]��Tч�>P8��/wN�[���8Ij�<��a�VvdJ��)��.P	�L#N|҄�kN��CH<|b1[�T?�����4��O`�Uf�����9�Tb�D�w2Fg؋j� ����l?z��ϔ��wt��՘�(B0<�y��f���IA֞ڒ��v4�u����X�b�ӊ�3�T>1!��V�����X�WKS�����~�����g��f���4n�@C��e�2�������\�$�zZ���/a�<�Ͱv��f���s��"O�Y�u<x�n�u�kq�ހ]��u��t�ߨԚfu��2�T���9E�R'�&��~������J@	�����$���Ylw�5�E`Kh��gAX��CXlaW���ů?�)�Ǖ� -�:���uk�RT͋{W�_�쐘�Hp����炘eA�|�"͉�ȿ�.�Z����Z�f�2X�M$�DЮ[���I������3xH����Ϗ���sA���]Q(�#+jMɳ�Y(��ރ����C��4�>��4���#�IbKӐ��J}�_j۱q����@Xa^i�r��]�NA�Z+���Hԅ�6�kqP�k��Mt��KvQ"� O� U~�q�z��tG��,\G��v��QB��W�Q)��N�i�?;X���%����;A�$� 	�/v���Z��!oU������K�D�Vi�E��jhK�>�z�($h�n�oI�8J��B��u�������m˰�=�����P>�q���@?�(�DmQ5�t�ՄV��^�7#���ܦ��~�6U�W˷����!I8EN�ջ���g����̍�"vC�(8T�T�NBL�o)I�8?[4rٛ�[�%�H<�!7{����o�h�O=�t��<hu�h�ߜ4OiZ�4+;_�GS�_3���QS���}?�I�Z*P��Nt�K��TZ�2�h����͋cuh�\*�N�]ętE����n�.3(h�G���5!��K��t2��2'����ܖPc.�D��b��54°| ����A��9}֬���
��h�Kr��~ԧϬ��0�|vH��756�0��&2_`J�EHpz�^���^�>�(�(����a�.�f��hF�-2C~мg�
����.7o��P�m\�f�C?j�s��i���A����X�y���Ly�J�3�q�G��ca�`~W��:-�bQV�4=-I�6����5&�}��Ƿ��0�r�(T�Z�mˎ���ۤ���A�Tޅ�3�PR�y��&(�"O���)z*z,�l�#ns	��zO�6�����hP�]�f]/�O`��:-�H�S���� <_�ɍSһ>]$���u��+3�<3}c4����}�_X����f\C�y��W����>zHT��� �`�5R��Lf����:�}���0ˋ�f�Ғ��[��"�B=W~�d�JL����P7j��AD�شmlئɔ�8	1�,\�EjsLJ�M�@։���q�oS6��4�(5,1��e(��n�aS~�BS�i��������C*(��8��S(�@�b�ZK����V.�,a�r�l����׬	����ϲJ�4�����h�5$��ʧv|�1N��G�̷R�m�x��,�}�Q~H,g�K��8���iw��|�P�w[��=Z�:�'X_@��������b�t|����t�ޑ�t��x�v?��8��R������W�w��otn~_L*�d�Q�⯟}x[�%E?j��Ii�Iid�^(�'�����Q�^/#-���"�yhC	ܕ�	P}+z��~���1��e`B�T��$.�]��̆������'ₗ/'�_º�T� 3�����ql^Ʃ6#�B:������4:G=4AF�8����,�!;���y^�폖=v��T��Ve��=��[�I���G�O�S�x�N��ޟ޵_�ӷ��ν(��zR#��h�1�����q'���epss��@NE����E����z�U�����Ʒ�ŧ�l��=�%���a�A��x']��f�`����-��g���,�y��Ő ��:�
-ce(�nC'A�z��;�r����K�	ȏ�z�Ћp�1ۄM����k���ەN�!��62�g��̄ٷ~*)�f�'׆��NX�K���k���uܙzH�����[�Ӽj�ҩ����_|2�Sʟ"�ĞD�"�������o���l�Z����G�|���"��C����[	�U�c$Ò ��Iޯ先/|c�����-Y��/m�E~=��X�V��/튴ǹ���v��w�q��E�[��G��n�`���e?7һ�}�gd�u�ڸ�>"uYRN2��1΄�'��t����/��}�����#�����;�"O�G,oP�^�.�g����P���%�O�fRF�4�R�k�	e���	�8˫a�0nlc�	%r������P�V��K�6F0b�~�h�C�#�K�u�+ ح(�*�{�'�^}��	9|v��|Y���L�3�,#�.��WP��C�RgC��!Y-�@��!��[�;bMl���իԝ�J�Hޫ��cO�O\o�a�*�6�0��,��l7�U�-	�4J<Z��npP��G����"�?��D���9j��.��멑�[�!?w+F��8�w���_�Y�\>	o���a��F���
�@SJ�۷pdk�U)�пǔ����HW�l+�;�0������Ak�5��w�
,ќ�5jx��`!!�@@�a=��w\]��Z�~��#T��o�)�����	K��I��P��ޟ-��~��TS�g�ټ3ǧ��m1�/d���\�Av="3�G��oSWw�nl����@%����*�����e�n���$�*[�=$R���yXtm�����0ݠ�~��7k���0Q�R7���^� �OT!O�$�u�S�7�ee�S�ޡ6t�)���L.�K�F�����U�[y^W��h���JF|��\M�)�Q�X?��8�BM�XG Pfxkq>��n?:�psυ���Q�;R�ό��/��T����ێ��xnÎ�0q�,�(?���ϝ�a�#�h؟� 8[���b:��T���h�BzA���h%�E8��U��,[� �����y��VmWz�ҹ�f�yY��+&�3�vv�{tS=�uF�^bZ�귗�m�Cy���5AN�X�����=uzj�w��^'�-��!p��-�?$�NOL�œ�A[Ẑ���0г�!��TSÏ�X�ɾH�6O��NV|%9���Gϴq���3�\�-1~�U�*��uj!���8��zج����s�t�h�t=�������U,P3���L��C�ޔ�Oh���~g�Z"��nHk�%��<�G�G�x2�~%~ؠ#�]���y�m�M;���@a�f��9Z5Gz`.	�]�2���6�7a�}��d����,��_<���'�ƫ��3�3m�b�E�ճN�T�R|zl�����bJ�˺�z���_�k���p�4Z�'�G��*� �N��5���-�Ȓ�r����FVh�)u��dFJ�8�_O<t�s���/L�6q�Iv�b+x;�Մ*�(�F/�~���o�Y�U��qX;F��y-�.��I^*YG9ڵy��V���`�-�G�k�+D���[��B��Ѽ�λ�)��F7��-~)K.�g�)�S>��L��Cs�7wrnʕ��Bgv��m�c�`����X��'*'
���f�t2g	�.��+��6�R��~����V�|���t��O$��ndO&���~Y����j8��CL=JF״X"����;<�0��5���[�G�y!��l*<���1/��[=���a�-�p|�AВ�O�W�'k����$��J�${�\fJ0����k�G���v��de>�=�����3-�h�5=(�������	N�d��;�&����<�ʆ�X'9k��&r���`��(+#>CT|��5���9���ΥZg5�7b⁀�׏�UhKcm*h���!MIH��܀Kf��e��]�I�$J�tY�h�1x��?����������gT��ݧ�+�ĕ��y�M���/�"�%��B���C���y,U`_������_7�#%6fc�9a(�0�Mh��Vn\Q+voJ�FN~�_m��K ��]�Yj�~=����=LG����Z����9�DK&
�z�J���<���z_}8z����ik��h��Q]ULk/_˻��{�BɅ��]k��(��dJH(�\O�<I`*O���*��7�z��	ْ/Z2�%�>���#=v1�&I#�b���j��]���C�(��y��.R�Zla ���+_�%.�]�vfѣw���� *R-甞�t���9z\�`9,ڹ�s�~tcOj�����L�&���m��H[�a;6�u��+}�F�\s��LaQ��yN�N�7W�ӯ&�nS1�G�uz�e�RӾ�즴�"B�K����O6m��$�'���5�I�_jq�{�8���gʻ0\5(��唃���� vJ{i�s��(:��ۢ�����t���#�r�׏o�T��FP����/��&O�~�=pe�5�uص����5`HIo��}��Xޟ��x&Qo`j�|�|������,�	���ߡ��bm��32Q�qd���)pH"]��<Ƒ�s<�\FL�e���+��$��md��@��6 ��� �42�=�QN�e���0��G@��b�-ͷe��,���Vp4���ٝl��?�O��θẓ+Mn=�T�n[�VI����o�O�_)��K:<({�
.�So�V���==�^��.i ��L�6�;!��ٮ � <���>!T��Q�k��{��Pr��_����)v<ߔ�9��=��6�%�璴�t�Qd��1Xۼ�Y�Z��PVT\k;�6s~T����J��G��m���gt�5ʂ������a޾R��0#?�	�M�Lnٺ�N��v�}~��[�C��G�k-O��1(�)l=��.��%�b�O�)g��E�?��ޤs�=z�)�|},�����õBVN6�Z���vǩ�"cd	nC#m��@�'Ao�8xz�[��ܰ�=>���O��L��sޚt`�g	��[�M���y ���e��W��BIC��Kء b��\]�<֎����Ѫ�dW���4�#݁�@�BM��~]=��|�.2l��ֺȄ�C���}9o�!��Ex�kc.&'?�o�yN)�9=Z�:�U����r]m��n��-1���?��U&hJ85�F����ӄ��J���0Gq#�ID�0�!�I�L��n�W�3�"%��<����6�F6d�ov3�:�6 wx��w�c�q����m%S풷;��R��ۼKK���~��B�3�Oqi,���	x88�g�WB��b�R���?���fD��S}UPC�K��d(���U� ?���t����q��f�a�lgO�r*k�m2��)%��I�N��쭧����=J`쐴�^x�q��"�D��O��h_��Ś��+���Y�"�����q�����EZem*ѱ�\|�Y!dOH��M�3�E�O�(��Aw���6�®}hA���-�n�wnϻS�.�̺�'4nz@'�Z^�����-�s7�eW#E���+�i�r;�Bh�j�Q��t�!nq2��9�L�$�E
�&׃Z4*s��-�X����i����=���w���vӴ�K
�.gV�bS�L�.�zi&�E&��pU�����r�=#��Mȝxx�]�ߟC��w�<��Z���4��\��5�K���:`��V�&iA�ЭĂj�d����L�-������c{�Tx쀝`S8ե?��;�گ�v)m�r����f�p���le3E���>�e/���pvVwt�4ۋ��Ȅ(yn�v9��X��TJ���G3<���Y�5K��rM�2��M��?��(�H��ڎ��N�FPЙ� ���|��ן��rv��Ⱦ���"��rK�KN��Nn�Iy$Q�����Xը�΄"ƣ��)Y�7.�O��%޲�	��qenB�Ͼ�s�^O����_°��1���]n��>8�`r�����h��o�ݽ�6vN�V�g!�z"�yb򦕫�d�WZ�Q�q��/���YE�������d�;g�Y�k��X�bkd�&/�u�I�G�rE/|�	O_H�O3����4���<���+�7Lx7b�-Z쬬����(|1:��>�5
��L�c�>�ǟ��D3o�4���T/��Z��r����̯jjk��.������6�F��hJy���������2��?y:�O<�����P���.�~�\����0��2���̯��󒓊ޓ��l/�8O���Cה�����q�����f�i�'�����Dh-d�DDe���u�<�I�mڵ�uEv��R��x.�F}@t*4��j6	���ѯ�s}�|���OM�՗<Eߨ�gM�/��{��N��f��m����/Ajn�oWr$�g�ګà�����F+�̸@�%�'"8<�j��v*6U�����W�D���d�=�	��'�jJF�����p�]Fg;:Q�'$��Mx�r���F~:S���v��)"��I'&� ��d���� �F2��a���F�f��m�A�o����hN�A��T�𜸰U����2���^��Z�A�U*�j���1�/��'l��B���E���	<�{�B�o�S�_�X�Zܘ`x��z�!9�0^�c��8��}��A���O��HH��.�1��ι�����U7�>�$,1����9�&\]�Sķ��ra�}T<P�V_���;��E�����鰐��{���2���&�>Y�����*W��9�ݴ�ӋǶ7�}TJV@��s
�tS�$s<7Pf�]���&s����g�K��"0Y�LR�g�e��N��<j�q�J��&Y��k��W��gs	4^��+	~:����P�'nF} g�b�?­�(�ׯl_�ة�y=����l��|��W��aSFA*��TO�~O�{�������U��)���-8vmz�p���\H�Pz��=�c�n+ɼ�k���ז�����U�����F^���Y��y�^X�xC+�ΦIb��h�z(|��lgl>X���4�>,X�Ё�0�AA�T�����#}���u��L�$�*�.��^�7�h���k~jhD��}{�'�ڴ@��¸�Îl��^�Z����Gh�˙�*>c�/Ç�C��#��C�bJ=Q����;R5����U����O���M�0��B�q�I�8�H�2@u���p���`��6��,f�7��H|ȡ7����%����$����~�xN(��~���������C�������v|{�x
���$D�������8����k���T	�G���(G�&ܗ�1�WPH&�}�Y��ߥ<<�l����v��lpA�]j(��F�]G �t��'I�!��ה�O�3�6«��6O�N*\.6e�!5w_l/.�%2K��2e�9�2g��&m�$�%�<�'p���.�$�&ɵz{��lxg?�)� � M٭�c��v��v?Pz{`��� %��%��ଝ���R�>�x��S��yf]�a�V��@�n�=�#����r_t��e�ȩ]P��6!��q]&-�����p�p��	1�o�d���wS1C�,��Q��������<M�T<^F�Mgظ>�=ag%T)�B�1�q�E��˺�&y��q����/d�s�x��r#^���K��jP�����4�����=+[:��L��#܄B����!b�X%���U�� ��f*�pVTz�-e}Ed;���I2������aܑKS IH��N�w_}�U%��?D�j-�UohD�Sx��H�ȟ�N<?NFL�V{�?�\�y�3Ju��R��p�-���Q�lv��^(�p�:]�Ȝ����Y�)>]j�@Y��Sc$�� 5Ն
Үbh�n2-*��hR�7��e=�0lן�H�%�7(���?o�R�Ҩ�6�S/��Y�����!�m��VZ���!�Ha�w��!Ze�X�����K~�S��R���Y����U�I����3�M� �7!��"����$Q���å�܏�=�����FRQ�x�����gWCJH����9iS؅](��u��s�t{�byqu�h쀎�h�J�N�A�pv���3��0��Ć*���e �"9�tQ�2l1Q���6�����0�)`d����~@�؅��K{.ľ�q_�������e�ޙ_�G� =T�}̺�҈0d���n\=�|`E�ԹOyT�|�,�/�j��tt
�s�p#@��4�ʘ6�2�^X�ϯ��r�������?�ҬV��(hY:��g���g�@��e �FR�x{��t7B"Be,�*5�)k��_�/�j���z�wi:��th��[��S.�2jY��.�A�f�E�27#pt2�m��O��ܱ��!�
.P�P	�pX�q^k�Km=�}�0��M�]o�v:���J����@�aH�{�}	y~"�_�c�^0�O?�����DVJr��M�$w��g�K���t&�m�B]����N�a�����'%�Oj���'����
0�Ă�M���=P�Ľ�x�"])�̴"�0�3�j'���)��A�T	N�L譱<m͆�%���`|l�-r��!�3��T�3V�'�n�r�f�@=y�g��uR;V�NS�:tU*��u�f�.L.�O�3z�;yV�Z��I�ƕ�f����AO��>�	��`���=yR�À��
P��7ys�q@N�} �!�\.Y��+���ߣ#� �{ACu��`NE3��j�'�O���.`I�F����h���h;=q5Â:�iQ���ʡ�zմ�C�C��<�(*s��h��뷂6/[��=���#F~��0���J�+�hJ�K�d;�%=��M�s���v�|�⩩��	��usI���'Q'�!�O�BkN2�E�d匔^_�hk}0<���D��ZH~0Z���3�8�����
 �ǀ��'�Nl��<ޙ�$OQoF��]Y��3�9��Ϣyq�������d*E���?��Ӹfڌo�_�N_�0�^�eʉ�ҲX�'#��
Y&J4`}��zW�#�e���GG�J������Oz]��{!'���i=C�OF��8�-���}��rt��z4��^&�8�w��r���ɺ~��5X�j$kD$�E'Q]z���r5��̌���[�S<�N����׊!]��n���b�y��6�����}��W���rr�7~D��� �=.��h;=V���+��_��R|1H�F������X�����.�݆��!S����+s�!D3F�l?�B��*X(�:����	C7�&��@��M�ͭJ��EEJSKPE,m�G"<��K�q�?��촯�Guin��'��E�pe�-Ω_nQ3H�����٪q��3��P^�����ʐ�]N[�x�ޘFr#<V8��������P�y������r�,\.D	/�T�����amSG�B=�L�W�C�J�(!o�^��3�Vȸ9�K��*��*5�`���� ��<%	��h�e[�#�¢c��L4,�Q�ƪ��G�ܓ������שH���ȏ�Dfؽ`
�\�T���Z�!R�0N��� bQ�ڂ�'��2��)�I},Z��Y)�X��{�>�b� l5p]�Tu_"���1-Q{.NB��m$Nt������n,Wcs��_$�)��ep�ѓ����(�E[%׷m8��} �L�T��!YʏG�7�J��>�7�tJSJo���J����S��M�?��L��L�*�_Z�.Mޏ�Tr�
o��p�^89�Oi)"d���y��Dv��.{8j]/�eVz���t�2P����(�ܬ�9Fsb!�tM�G;�_�5�v��ɀ/�4��'�	�Ňi����/�ޜu��	U����"��7�}=ښ��M͂�wVb�V��`UW��!<Qx�Lr|�螹�PXvWܟ�K�b�ۣ��P��רO]���^T
��֑����ŋk0|)0lQ'�#��
t�]]Z#��� ����L����������DAO�b�b)!�%w�� ����:V1P��)^����MB���P�H��܅wb�Zj�	�L����;0�G���Ǔ��/��s�]C�GD���f+]g��6����*�@ƂD����wTv+x!Q�ɼ~D�Lo�x�E�F����($Е��/�S:q�B`6���H��S70�G��K�����'��Q�����~�E���:�Kע����R���3L�aP���K#��Dm���ta���R`~�����^�S�&�^7�5Ł(30���$�q�t���r��lo?�� 
�� ]j\�-~�lww0R��Ԃ'Vƺ�rX=�ue���'S O�m�K���%�]������p��MQMk��j�'�Ҥ��\�5�@�F������
������0�.�7N>񝄚�Q;`�m2wGrɑ:t�A����H���*vW4m����G"�T�oc��������h!}��H�m�14Ip�nT��?�*`֊1>z��h�U�X�sd�R����7y�%4����h�����"��1 q��ėkANė}�4K�/䭲ƝY��zMa	�!��"Q����O�[��w2��s�!�|�ʡ\y�0w�Q%�#�~�PA����*���D�������}�ԩ#a%M����I�R#����/�k8��@^�B۶w�������{��NT<�5=�)e)XU�	�-�5[�L.F����Y��Ag��y!p�.3wo�aAĦ��I�	�>s��G��9,SmLI�ZTκG�&J��\G#W�>���E��܉��0�5P<�h�S=�_tu�uE�*���u!h2�����%�E�:^��\Q�Y��'D��tDq������Et��ahwР1��:N�´{�5	�����t�Z����\8���S?'�>չp��?8V{�R��V�{�����+w6-�:]���nl~�{����6�tk���	Q�r����hej�8��p����}S]
�Q�A ���?�Ge�t~���4�o�;J��ubn'\��j�ttJ��$�'�c/	������؂��
���������K�R�{�_ٝf?)����^��YQq��	����V}5y�~qk�G�@i��S/R��	���wv����5�j�Y�o�:Us@[��W�l��������<]7�?�n� sI4�~:�*b���A�[���f�N��N����>������t����C���"`������:t��'�'t�T�)�3�h\��f���d�������t�}۞@G���l�>�z5ʆ�?�{��I^�@ N���Y}D�k���e5�KŁdE�m�4�4�.7�H�B���XQva3��C`e�bX�"s6�z�����f���TS��M"�fg��N���2\�n�ki����W�i���Ͻ��u��J��k���/�%�9%V�B�a�E��[�*g�EU-��T��@�S��n�ew32O�eh�\�ĝ�9��,R�I\ҚZcQ���x�d��Lc�7�������@Ɏ���c�j�m������EC��`�SZU_�D��k}����Wt�w��M�5��Ǿ�Ⱚ���Dҥ򏢣[s�	��$^à����b$����K���y2Y��S��d�Nb�<���':wĬy���Gf��6�;��geA��h^��$�l����vR�˴�$�D�]�8E�6I�\��D���!�:)��1j��Ck�x_� g�i��F����	�IY��fUʮ�i���ȉ����[��:<2x 2ŚP�e�4�B��)ec5Ң��W[<E� ���+��)���C��,�1�ިG����[p�>{�t6�8P��@W�?��E)a�.fP�{��" ��\|H��$(|�D���v˸�x-�V��L�6�h��e�#�?���ڽ�,��9|-I��+���("x��)�����6g��_�C3|d�Fg]�Qc�↷A�>��Z�K�������P����v�Ԇ��$�%v�u����}e\�^Ǜ0G8cz.���"���`��P�3�(�5XK)���S�:�z t^���[v3�zJx���	~���S���2�~������������[cDY�zk
/%b@�w��n`�!կ��e�ۡ ��؞�a���K�7�8$�_��}���ŋ�'�Q�V|yB��)�O�C��Γ7�>S�ޚ@T��w	���$�vs!협*���&��������JKq��E��w��Ɔ�V�s�y6�Ð���v���p&U�.Q�M�/0$W���ܺ�Ǡ�.����!0 ���<:\���:8x5%l��}Ԯq^A�_iVI��qx�z�8���F����C����ݮ�v�/�@Nc�@V�����W�!@C�J��P{�>/�ֹ'(��)a�X9g�~�������`��.		m���~ֹ��խ�Ze�Ɂ�~P#�D�9&ó��5��w�NPG�.����)G2e���Ψ	�u��*+3�ʭ����6z|�����[����w#��
-Y��'Igq�r��!(�w9΄�N�R��ӽR���; G�E�jH���')"K<�K���3�C?��Ƀ���RY��jG��p)�|�x�Γcz%W<U�H�r+3���B���� u��j�13w��8Y�;�<G��a��v?L��&cr��^#��&�"��)�&�D `�_o�o����ó�d�U4n��t��	S��T��Aľ�<B�B��`�۞�,����K&��P���~'<g��H^��~	j�3�EGb��O�����y6���e�&R!��o��\�2�j\��ͼP�������PW��pu7�
�$%X�7^��]�R����) |�X������ؿ�� lV�¿J���Y��W��ad�yd!�տӧ��u��V�"���k;��lEMȢ���9��8�%�
����D���`�]���1�ro����� L��O�t�8���H.�MǇ���p4T�o����3�R|<5�+��w�i�zTo*S�Ҹ���%�HQhڕd�|es�!�'/���mVw�w(ZEu&6���X�x��hr޲�}��YXf����4i��k�Y�y�zY�1P:p���u�H�y�{�z9������ȳ�2o.��?r0Jg��=�ғ#!<j�5[Rqȡ�{'�J'] �`�n���`[*UG%J�7�¹�`G�0VMo�\$v��^k	��+]��ӧa{��:dq�C[�CB��Z���4�7?�o&D��6��3���&tP�����h��X�������gU��"1�h�:�_��Ƭ�Z.�KVYY,���x�@�,�T�.�;��)s�v!���/R���S��}2�d��5r�'Y�+����j
���l��"�g9K@F�F"GY�JF�Ņ\�A�6uoJGn���_+Wf� J�c�e�NIYS���n�ie��'���P�߃�c ((�ٷ����X��{�'`��y����w�g�+��Q�~�V�^JKC�e۞g���ۗ��]����Ո�V�:Ֆ������� n���=��4�-b�O
0͟M~	� vT�d�_�73g0:zm�%�K(;�g��Ax����	a�-[K��nb��� �w��:�GNK� E�����&C���q��Q�	��ps`7ov=�&_SS ��2��g�����B�Jtd�=.Pgoz�~��L;�ٍ4�匉�h���z�tz��f�Ĺ�{Y8�f%�l4{{�!~dCڄ������� �|o��~����c5[���I��U�j㕮ӕ�Yn�o�����{��q�׿<��}��\)��{[K�v㦽�ӡ6�«��"΀W�^Ё�/d:y�>���P���%��y$X�s&�=�����;W��<�h�-��d��dt�<�k�52`8>�
���v��<{�\��9N{E���W6�	ܼʃ�G��W���P;��y&0���/�8y|
[���8k.C2@�)�;.;���s�/-nm����a5��Ǝ����|b��^�rs��f�kS�iz	wTY�^�g��uJ��l��#9��}zpK��J
�݌��!�s��3c�6��GQq������6�Q�(���	�a��BS�s^N%<�q]bO���w�gin����Qh����W����81�"{���$��Ih�Tɪ����w�^��̌]�����ܒxkr�$��7×�W)�t���X�x�Ts��x�,���rU�O縎2@�f��=��M��oA;�'&��/����I�����#y��~����ޝI]�ݺȋ�B�T��V�Cf��� ��L����&�2m�	Q�h
��JE��ϐ��OX��J��ѱ���Oy��p1ĺ;.K�k��t?)����׉�Ag����ʹ�>M�����Q!ZlWU���q%fw������)����3��V�TWI������J�4 ���K�{��8�$�yL	a=�`s����_�.�ºpj� Y	^�WCHѢ���<;%t��!��5���5�є��cZ�M]�h(9����G0�l��U����}{����.��/8�N)
endstream
endobj
43 0 obj
<<
/Length1 1007
/Length2 9687
/Length3 0
/Length 10435     
/Filter /FlateDecode
>>
stream
x�}�eT]k�%�$8��������6�q'�;��%@pwww�@pwo�9�~���z�XVUͪ�5�z�X�d�*��@c��đ������hc6��v4�� ��ޝL����� #G�D���� 
&�  3;3����o�������;���������̆L���  ����=�����	��qY��,LL� [Sc��-��{��d@ff ���Af`2�߄�!�6 f��@'���9��ޙ���=5��;�b� �L��m�� �Dml���f� *���\�t�L�G����#�� 1������d [Y��Nr (�@��;� v �����[������'u�7����-6���a��h C � j�ߖ���`2�װ�������rx����q� ߽V�
� P�;�_^��b�'ۃ �� лF�F`+#c+/��;:��02::�1�؛1�gt�'��?œp���7�~�ￊ��)�?��5�����'B���� 3������e�!fV  =3�N���T;��L������ߣ[�! E��[�����1Us��%�� `�7� ������pf�Q��&"K�?o�?��S�!f�	hd������GU7[�����f�߶�����t��^�w����oz�J""6��� z�w��,L� .n���i�do�8�s�'�o��. �
2A^��1��HNKq����?*��i"�f�<�Z�kg��U&�7!��Kv�^�*��`�qP�@�q��Nf��k�,Gj�ދ�S���7[e�]c{Z�W���B�Q�΃���9|�S�d*̈́GM���"	���A�ӓ�7�IO���[5��^rv����7l��}o�rw��r�O#�[���'����e�[]��s3)5��鎈�(�b�E$�S��=��'\�V)�x�ǖ��/PIW�j!ӽ�˾�_7)y�G�B�X8�ʉ5���0�H���G�\���'�i}�-_v
p
��0=d�:v��׫� m>9A;�雬���hh�!��OBݠ�X1�X \a�z�(��{�~�(6�Z9Ⱦ�l]�/11��ث�5x���C����Q��X��n洫o�5��-�����M�E.�w�c���18ZIܽ��o��q���  .@���a�er5��ל�!�n�?{�~�*yg�|f��'v���zG�H���F���B6�;'���/��SU�س#����͎y,��{��MוS@?�Z֠ηg�jDLX��ϱ,Tf�'��p��4��d(At�p�?��ĔUH�}�i�41�v�0D�M���9WR���Ū�<���q�O�1�eĩE~ºk�E��Vҭ�9��e�7O+]*i���*��I%��M�r	U5�Ξ�:>R����� ��Oo(��D<�xF�~���$z�ӟu|�Ԧ!&�r���m�va�4�x��x9�L���A_)���@�:�x�R��N���G M!��yB����X,oʌ��_�dj�1�AO66ڄ��d���P�9�L� *�ST��(cDۨm�_�� �������V\�E1/�s�#с�����	^|��A�s5%Qu�w�2;[@��C��I����7����Mw�e震������X7�̸������Wo���P~i:���i�<�ղ�/{�/�"���+�l����x��p�0� ��cB�N��i~���!�:���%v<@%�,�2�lxOМ��R���daZ�b���w�yVY	�6��;ıH RC�̈́�[�8[ �=I�֊���5fyy� A7����D�2�	��j�xt09C��$��ھJ?�%~�y}
D��r�+e#�ͤ+�g8��wD�󇍒���?�+by�\2|�/��$�H�KT���*��~�qX*O]�n�ͧ#�N����2�ӡ�-�6v%���Z����(�����C����S�o�*���2M��<E�g�J��@e?r�:2 �E�	�/�S�dY�JI�xtV�G�*�,�Z�JR/���B'���4ݪDM+��3է�<w���l�W2�N�����F-*j���"�+���D��J�%����!�GM*���f墱U���:2(S��?��~��x���S�j2RMH ��;��qN7����Y=�l���Hŧ7<�|�.#��F��ʔ������e�4��V���u%#l�l^`�I!�b�w�!Ze�e�,ݢF2�;.�������k����O��d��
'����Ԕw1�������z>=���pVg�!jJәĬ�<�����U��W�U
a��S �FS7�ql_��e6� ��!�T�S��O>�r��Kx#V����!.f>��L�\��OR��,"�~D���C1�o�G0�`�3C������88:-����eظ4�#-Zݣz�Rt��U$�#���B"�NG3����w�e�}���P�}:�t�����r{�YFj#9���0�1�}��_�ֈ-�[�'�_��-i�B�N�k�5���l���u[���T�H�~�Ά)��K#!��F���#�T~���q?0r�{
���S����?��!-|�����q��P)裧��w�7���}
XEČ��r��\N�d5���P�<�����!����<��+�g`����ee%�Ӥ��ַNI�*�R�sN��i&�@�O�cY=���$[����ʟtŶ6�ٴ�J5+�|�]�+�/;��g�`�3�,)�q�����ӤAIL��]Nk9��)�P���hH��u��X�=��J��&�sװQP�r�f�%�~��3���@-�����8���/W0�c��I����r�T�tp��o,ݕ:�����-�_�Jy\*�҄��/�B��(��X��m�.|����p�	��B9<mV5���d���m�Q�%��-���'���qEMFÇ�L���@�|?ϯo�Qg�7��x��t��tl>+�C�w[4�z�y���B~��ӌ�kI��\�@?��a��s���`�j��˶����{���p,q'�yRT��e#�4A1��-f'���Ld#���\����Q^ F_�l.z���k䡐�T���JV E/�M�����$��<7�hv�`�¼́\g�ŀ��r�"k|�:.�v�7���cZc9��+�i��'�"�T��"�[����Gr��D-�#��O5V�^������9��9)���؅��R�"�}}a���P1�q���}6r���2G?��8�֗�}w��~B�:�(!�&��c��3<�����uy��U�A���ԅ�M�j�&
����Ph����+���ͩ.a���3E�#�.В>��ƣ�ds/gzp9��ێ�4�G���
^�%��Q�����8��a�َ0&��9ʰ*c�Ke툵1J�kaݸi%��P%0��)4%�0f��~()
�W�Ϻ��d�@�g3�Z�=+�}FQ5�/�Id��7�	\�nj�2��p�hp{9�҂�w��A�/�$�Ԫ$���K[��j,/���I�d)݀[���I C��=�eK���>z�FM��Ҿ�zQ*�1��Y�Y�h����"z�Rj��axa�'>���#۴!!M׮Ÿ��X�^�3_��O+^�n������/��XD~KG����$�
�L@ښ
d1�Ql6��ar,���²n3aL��"�߶YM�Z4�is��3Z�?5}fZ�c�vg�~mr��������Do��k�E���+��J�~�rN)XsF�<����!j��r� g��I�R�e��i�!�:0�e=9z��	��&�q�Է>���	�͟�N�az{y]�#&��۵��C0�	^�`M�k��nN���6	��^��A�,LD��`'5���ֿ�ǰ䤸��Ղ�a�"�����k��mJm��A��$*��5!B�⠮Q��y4W�Az�����I����4�.[n�L3�Ĉ8�^�����Ӱu����3G�r
�TC�S�*0��� �Q'�fCC�Y�}Ve���W�7E/3*�j.�%����E$3���m���Fg����L�P��Ճ�Z��?�����-1��l&�g�ʊU
��;���t���^'���]q�4a'��,ud�L(:��T����'�vm��ܽh�X�pj$�o`�μ��Ϭao�{��6ZY-��όL�ܩ�V˄��]O/VT��%�j��T����� �I�0Qd�M|���T=��Q؄{���}\R�����s��.�M��/;��eN� ��_�\��X����9⡪k�`�g�q�_x�t��z2�v�92�@�:cϰ��ZLy<*6���\����챋�ƣC	�������ݡ��#�ԡug,"�ОX�L�D"$�)}=t��a5 �	�a��W���)!/z��9i;����_p�]���NmH��c&�O!9�U�"t� ��me�Ы�8�6��
;����HL�z]is'�0��͑�^�^�`Y���f3��?�1�q6�N��:̗�f���k���V�5�R���Nl�5�F�V{-�vY�I�V�ML�oy��p9.w��/�H�����VC�ކ��	?�q@6�~Ĩ��F�x�qr��)�a��W�S� �-DPt����=[���(�����^Y�1<@L�!����zF�i.�(�l
kZ0HPǨY���޼ʷ�d�V珝�^���圭7�c�߿�(/�w�P�8���U�8WlL��c��] �-�_���	?������\	����T^�H'Y�����`�H��~�+{���uѻMN�7��=�02`���9���:�!e�fD3�cQ��Ĺ��@�DѸ<PS�^��sbe���خ8Ra��٦H;�}�I�J�3�T��L�m尥��(�Ra<>�0����WDr�O�b?�%D��+�� �8�36(���N�X���^K���ϫTn�O	����W�t��{�<ڕ}ĭ��\��w���=B���ġ�oӂ ��Jʒ���reO�7��,�=����`�Z>�0��} �G���r������44ay�Y�yq�д�#=MB(@#���(����^�z5u�t���zh�b2���x�M��ϐsmۅ�^�NBF�����trYT7�����K��U$���C0j��<��~�ܨvNFuJrƣ ��7B�g&�������支�ĉBX'Vt�r���eG���uU�uj2_�4�ewB�Q��&9�����w>B�t�P��u�(sB���M�:G����T�k����5�m�s�Ԗ��f׬���F]����"�.,���8��_�Q�_,RN��^�G�f?Ӎ�b	��,�������,>F�>�3V�a��d2R��a��%�^��+'<N�[�LF�x�C���N���ч��4� ��M�
�m����Bћ2�[+�Q�OřM�� �M=�i���IQr�d�]v,jD���eY��"���<��B�}!��߄�L��+�S����_3�au{�;���,������8�����)�C�1!P�_H��r��7XL��~����0c�ɔcݓ�1�S�R�DRx��C��=��U�fz/!'2�>�
�����#�h1	��O�(��UFN�f���.)�b?f.�a"�Y�4F_]����uX8H�V̟s�(;t%.E�l�r.��Ҭ�{=$w9I�w�r.X��!�GF��H�����C�Η}4�1�����͓����i�A.7Z��8>2p@������qZ;�=Z���ޝ��ɓ�����UYF��Qo��Lu����9���D}M�\r����Y&LC�2h >}��38���s�o��u��b����`�b�N9�
zIח	�9t�*�n�3Cє3�"R�}~K�f�eV�����z��(�Ϥ��S�~w1���Z}�d�\)��my\�?�QT4���b,E�>&�FNJ��H7�Pt�*m3������ÙH3r0`�85D��O�1<���10�:�zj�-�=�S��ZT��1��=��Z>��`3
W]�mo���(�e�[0}nH���m������JU;������J��0.��.^�+>z�?1v�ѿ��V�q�ے��x�'l ,��j������u�d��V���R>�~j%���Yf�jkB$}����Hã�Sbv�4�VҘq�s�*����oS����%_~x��&u��^�匠�I�.%�1�`��NY'�(��j(�Ķ���'i�yn9N�y�Y��%ߤ:���
I�
k(�6Cg���Tdܧ됏D���9'�f8�bˆo��$�B�%����P
(PggoN�a�Ɖ.H-wvM�����
ksAie��k��&ݵ�MD��t�� `�H�\�ƿأ���7�33L���F��3��!^TE�~Zm�]f%��E��D�p�oڤ�M�5Իw�p��G�ZSvK�KI�I��>�� ˄��z��y1d**�G�j����[�<�1;��ԡ�@qfu�7ݾ�{Q���g�<N�F�:�*���4-�8WEU�q~�&Wo�K�rQ��B�"�:F�+��q(�6�[���Pf��>s�Q#�m��%�~�~�l;w�nk���m:^޾��=�����Lzآ��^� J�5EL�0�B�_�c���獴�é���'����~3+S�&.N�]��W:\޷䟺^.H�t��~�&ӈ�W>U)���N4�n�5�Y��}W���^�V�YQ�|�<a�1�x���
�$2�Y~��K�l$���e!,)v���wB�H&��s��v��	#,��&��iܪH�˵b�5��9���'th��\����{ se��D�󜷱`�m�}I�}t�H,�)�%oTx��{ދq��}_�S���d�l��p�P�/{Zjo���ؠ���%'��gL����J�O�B�?ʉ����^�#7��1M�׫�3�m�~����:���}���&�C2�S�g.�Ӓ���v_s(�tB�CO[���N�N�Ld�R���9��F���o�fɕ'�#D�B~�Q\�	��Kɺޛ���]�?|V�5��O�g��c��������:���9i��G�Ɏ�塢O�t�?Z~t�c/�j�z��`��PW)����6ܮ~?������ۓf�Ա6p@�ߍ`�v�I:��h���oSM� ���Pg1��]4�nh���ݿB��E�.@T.L���0����+=��/"�G�$Y�1�U�;<����ѕ�������띵$�.Ꮍ�j�̈́���llƒ�J2����T�?�oqp�z谀~>#'r�m?'�Q�vmu��Z�%��?�I�q ��� 5�Q�x��k��?��?�Ϟ������<�mTC��A�+ε�@_��͡����83�9 �Y}�vR�aBS7��&��Qح�v��Q.cx>�����νX �,͎<�bo_34�MD�b�P���&����(����E���)�Dw�`T�6`��C�J(��|�������@�V�qkt�.2Ss�Y��)��ȝ�����,���S�>��rB������}�ţl�[âv7�j�R����a�z�����'6���
cp�����~����)uh:	�lE�q��}��c�+��rab.����C�"���:r��~g�Ђ�����:9#�z�Q{��	�q��!t�	�Nmϼ	\�j�c��zXz��,ũ��h�zR�#�è�r�ۡ�G����
�lK��k4�U�;�?����e�'9�v�� �wy�_;�E�������k�!�Մ�?����"%�p�lJWű�&����d����FQ��6���!EJ��e��x_�~ 9��Q��KAE�`3�:�"٧�q׮��P�Po�/�3f�1ݩ�~P��+4T85��C�@{H�����qJ#iF�Z	�R�^#��oKu��.�<�I��
>�,�?W�M���B�}�՗ ���gbo�M(K�Jj�:���ٺC�[3r�35Se�֗��:��Px[\;�bu�%M*��^�)��s�W�Wa��l��̽�k}�.�b�  ��3�Ak��?w��� yk�>�(�m=���>JN9b��β"��i��#�2w�
�/�v/'(�JZ���R*㵱os �vZI���El�P�S�T�NV���I_���8�#�$��`,K۬Ҿ��ݎ0������v>8,2,�r��6HZ9I�ì?�'���IX�m8{8;����X�pmw�3�e;��2X��Ҫ���]�97���A��O?���#0Q����/+�5�9A{1S��lM�d�V�`,�G7�eO���]b��e3�gZl�51K�w0���-����[��+�-K�V��+B}���m��Jx�����mTZ��g�%��8�ќ.��Q���S� ��[��dK\r(�Ĵt�C��(2�����BF�!��M2Y1+�l�}�M�(� ���ϔ���j��ɣV��j��z��az�S]˨��A�� ;X 
�R��e��FMGuk�)=��&�@��&� {`ƉN����?���qz����G��O�ǳz�c
�vDCǲ՚=7�Vp���³�0�Mx�<��d�d= �� �LIew9/�=3���D_gkH�R��Y��$Һ���z�&�I�	(^����jǼ�@�1o���t�ɗ�fUj*�ͱ�e�&���f���}�F^�#�}��`0O]��V��=9����������K�7���)d��}A?���0b~>>���f������z?X�;�~/>^
D:��)�߽/D�h>��@ƵS�3�r�����GV#[z���=�"j���:gxэh,{-�Zp=����p�c[۶�1�t��G~�N�0}�!h�h��zT�O
��<��5�S;��a:��~`K]����-u�Nk"k��&����G��S�Ǿ�/�Ɣ���Ae"��p�*�(��&��0�.�����~(£H�����*^H�T�
�c>=��P�ԘNeD�m����m��?��^6Q��QB+�*O����y'!�(� S(�,*b=|c:&�B�X��I�6�|@��~�q�3څߙ�����1���<c�^��������<�� ��Y�'C�80p"푚w�x�.�{����R���������׵�_��p�ѭf��b[W�������U J�:ŸQ��}\fL�j�I&���3���_*��'�Y���O��zaN��U �7��ݵW�.�a	�&1�/=��-+O�֑rN��h��:��s;1{3pe�n��s�?J
w��MX��%Q�iCu�mB`�#�Q!�r�������<ț��l��%~�v����zLN-b<���K��s#���_�\�Zhc���q3:i+B���f�%3��SN�reCy�3&��,����C��9�h�k�Д?_YVQ�Vnq��>����!�&�k�4�;}�ο�,�NC�i��ded������L3�i�~2���`�\5���� �*��k��"�R��U��`�r_��U�sGp"Q�P�s�`���RZ��zY��G�G��� ���$n�yL�@痄�"���䥢A�へ�UY������c0��Y�z-hT<c_��?��K6CO#�)Fq��K�?fsTk�]@Qq��30����-�j��D�F�@���H�%�}>�<x ^w�4@a:�§aZ��9�-)kD���9}}���"���,Ș����`��U'y{�|OFs���	.�ݙi��`l����_��s F��=)�)R֙��AVE>��5�ASx��ς���}mr�CU�#��@ß\��B}����~]�t��"o4�w[���KǂA�>ҁ#\���OɊ
�F/*,P��������M�p�����8	-*�J��*�MG��,���xJ�s���+�BQWk���%�X���I\�x�j�z*���gqCAy�l�%�zd�0]y.�T�"��c������ #8���ך�o;�ߺ՛K�C�CL!A���QI����H�{�����j�Tt�h2�)��Ο��	k�<�_dF�� v�9Th�h��g��B�k��^�	��=mHǙ&x���.C5C��fL`\V&�f��z��l1J�*s�P�j�cRJ&Y�Ԩ��cG-`\�Ê��D�diG���Ӵ؞�o�}��Xk%���
'T�'BcP<z����-���w����ۇ�5�Jf�Ǯ�\��&ֆa����W�I�\#v����e��g�f���Sx��1nL��W�ddZ��K����	����C��fȚ0�F4�~���>�AY�c��@?#*����5�����Bf�� ΠY�9��V7�h&�!i�#�|t�1�3�3]�������X?�ȔNږ,��������-�L�߭�9�O�sMB�LI�}�|=��� F9C
endstream
endobj
46 0 obj
<<
/Producer (pdfTeX-1.40.17)
/Creator (TeX)
/CreationDate (D:20170307074432Z)
/ModDate (D:20170307074432Z)
/Trapped /False
/PTEX.Fullbanner (This is pdfTeX, Version 3.14159265-2.6-1.40.17 (TeX Live 2016/Debian) kpathsea version 6.2.2)
>>
endobj
12 0 obj
<<
/Type /ObjStm
/N 30
/First 221
/Length 1742      
/Filter /FlateDecode
>>
stream
x��X]O9}ϯ��V���j�B��]Z�vW��!�d�I&��P��~��$0!PZ�{l�}�=��z�D&���N(g��B['d6�B� �J��ʋ`s�2��@�]�I�ꠅ�h-W���1Zh~̥������5vU9j^O�ɄʍF�-�1B{���:h�.-��1b��8l-3a�-L��
��x1��_Q�q1�ڭ�m�����d@'����(6pA�8��e�S݈�N*�:�����<���ye��U}�(FQ�ަmc=���q�}}�m�S�c@�@ ^���=�H��aWX5���ۆ��66���]�G�ˇ3��v丮F��g��վ����90yW���>����<<�m1�g���-��gc�v=a��o�RϔB�S(̷Lv��d#��&k�erx�!�[j��'-�W�z|!�n�Ыx]����s^����*����6�R�/���Y�M|h�SEf�����r~��W�g68a�>��,j8�*ᐗ�C����j�d���"��́5ːZ�C��w�p8��U#?sm}g�B��N
k����iɉ/`=�6
�XƁ���d�N�N`�v��J�;���{;=�)�zT�"{�/��/
rWH�ˈQr$w<��'4���gtP�F*�}���$�����y\@X�����>$�Z��q��LHct9<�~w�P���g3 F�	���C��y��0�f`��u�bÊ@m���k��OXOa?���Ŋ�����l���HG#����.q�����֟fO�Mg�<�5�b�~G��\x�u1��SF�ۚcO3Z!�{�_�jx\�G���<R�G�`�|R�9�]���\}^v�,���v�ëp�l�k��-�ao:C�炋�U�~0��c,g��x�@�g~>�8g���b0G�W��墭�.�-fyt����}��2�ã��O��.�i�i�b����I�y��� ".��/�h���bq��ـxKA�-����|<�b(�N�8� {�g�^؝5��_(~^S���Y9_6��.�_;0�%�Ѿ�������?o���e1ܩ��(�C�wp����Y�m�B��l*�7���FJ+��%��.��)���T�]���Slk�O#!���"]�Uy�
dј&4����9��/}�)�hN�r��
����9�Wm��\ĺ�.��26m��kj���X�)o��vR�H헊���_ƺUu�k�B7�u���G��no�����'q���c�+
����O��S�3�]�(���h�^�ኅ=br_ju�[�s۽EԨ�͊DW�n�d�n�����X�Ʀ�~*��5�|>���Y��������I��?�/�U�g#��7>����玍Ghvn}�7i64;o�E���k��G���G���7l�۶��G�e9c���*��|M=S�1g�u�dKvLtBX������xe::�*�>U��N?Ik.׬&�l����F~Zŕ����������E.r�:G|�+�kC�"؞DD��\�V��CP?�T�i'�Һ���9Ѷw�η%�mz�N�͝�����D���#�
��)�˺iYB:,�g�zR��l'��󠼿���d�	�d�!���@*y�`�ѷ�H�Ð���P����({��P��{��}L.�A�W�;@�gß�K@���My��|�?����Sݧ�J	\���������[���?dI
endstream
endobj
47 0 obj
<<
/Type /XRef
/Index [0 48]
/Size 48
/W [1 3 1]
/Root 45 0 R
/Info 46 0 R
/ID [<3499915AA245FF80F3031CD81D6F8474> <3499915AA245FF80F3031CD81D6F8474>]
/Length 151       
/Filter /FlateDecode
>>
stream
x�%�Ka�̏a��N �p�,$#6��+�Y��p�pT�|��N >$���:m�D�ס���vK?L���S$��^^��@2�ŢDƋ߶9�V�\��UE�<�^S��-���k��]=u���S�6�zbJ�V���r
endstream
endobj
startxref
154750
%%EOF
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                