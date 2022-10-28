/*
The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.
We have to find total number of different ways we can do this.
*/

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int,int>> queen; // places where queen are placed already

bool isAttacked(int r,int c){
  // This function tells if the current position of queens can attack at position (r,c) or not
  
  // traversing over all already placed queens
  for(auto &[row,col] : queen){
    if(c == col) return true; // checking if the column c is in attack
    
    if(abs(r-row) == abs(col-c)) return true;
    // checking for the diagonally attack from already placed queens
  }
  // we are not checking rows here because we are already plackng a single queen at a single row
  
  // this part of the code will only run when already placed queens can't attack at (r,c)
  return false; // that (r,c) can't be attacked by already placed queens
}


int rec(int row){
  // every row will contain only 1 queen, so 2 queens can't be placed in a single row
  // rec() will return different unique ways to place rest of the queens with the current placed queens (in the queens array)
  
  if(row == n+1) return 1; // n+1 row doesn't exist, its a NxN chessboard
  // return 1 because if we reach n+1th row it menas there's a way to place queens thats why we are reaching n+1th row otherwise we wouldn't
  
  int ways = 0; // ways to place n queens
  for(int col = 1; col <= n; ++col){
    
    if(isAttacked(row,col)) continue;
    // check thats if we can place a queen at (row,col) or not
    
    // this part of code will only execute if we can place queen at (row,col)
    queen.push_back({row,col}); // placing a queen at (row,col)
    
    ways += rec(row+1); // suming up different ways to place rest of the queens after placing this queen at (row,col)
    // moving to next row now because this row can't contain 2 queens
    
    // this part of code will execute when we get return from the rec() call
    queen.pop_back(); // removing the queen from (row,col) // (or can say BackTracking Move)
  }
  
  return ways; // returning different ways
}

int main()
{
   cin >> n; // Taking Input
   cout << rec(1); // we are starting from 1st row
}
