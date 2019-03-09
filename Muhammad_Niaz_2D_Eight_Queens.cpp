#include <iostream>
using namespace std;

int main() {
   int q[8][8] = {0}, r, c = 0;
   q[0][0] = 1;
nextCol:
   c++;
   if (c == 8)
      goto print;
   r = -1;
   
nextRow:
   r++;
   if (r == 8)
      goto backtrack;
   
   for (int i = 0; i < c; i++)                    // testing the rows to check if there is a Queen
      if (q[r][i] == 1)
         goto nextRow;
   for (int i = 1; r - i >= 0 && c - i >= 0; i++) // testing the up diagonal rows to check if there is a Queen
      if (q[r-i][c-i] == 1)
         goto nextRow;
   for (int i = 1; r + i < 8 && c - i >= 0; i++)  // testing the down diagonal rows to check if there is a Queen
      if (q[r+i][c-i] == 1)
         goto nextRow;
   q[r][c] = 1;
   goto nextCol;
   
backtrack:
   c--;
   if (c == -1)
      return 0;
   for (r = 0; q[r][c] != 1; r++);
   q[r][c] = 0;
   goto nextRow;

print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++)
         cout << q[i][j];
      cout << "\n";
   }
   goto backtrack;
}