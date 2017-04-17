#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
   int hp = 0;
   int board[10][10] = {0};
   ifstream boardData;
   boardData.open("battleship.data");
   for( int i=0; i<10; i++ ) {
      for( int j=0; j<10; j++ ) {
         boardData >> board[j][i];
         if( board[j][i] == 1 )
            hp++;
         cout << board[j][i] << " ";
      }
      cout << endl;
   }

   string move;
   int x;
   int y;

   while(hp) {
      cout << "Enter a move: ";
      cin >> move;
      //cout << endl << move << endl;

      //cout << move[0] << " " << move[1] << endl;

      x = (int)move[0] - 'A';
      y = move[1] - '0' - 1;

      cout << "x: " << x <<"y: " << y << endl;
      cout << board[x][y] << endl;
      
      if( board[x][y] == 1 ) {
         hp--;
         cout << "Hit!" << endl;
      } else {
         cout << "No hit :(" << endl;
      }
   }
} 
