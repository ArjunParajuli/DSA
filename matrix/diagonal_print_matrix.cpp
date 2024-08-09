#include<bits/stdc++.h>
using namespace std;

/*
- from observation, diagonally print honepe, i->i+1 hora hai and j->j-1 hora hai
- we need two loops, one for upper triangular diagonal and other for lower triangular diagonal
eg: 
1 2 3 
4 5 6
7 8 9
*/

vector<int> downwardDiagonal(int n, vector<vector<int>> A)
	{
		vector<int> ans;
        int col = 0, row = 0;
        // print upper triangular diagonal (in eg: from 1st col to 3rd col)
        while(col < n){
            int i=row, j=col;
            while(i < n && j >= 0){
                ans.push_back(A[i][j]);
                i++;
                j--;
            }
            col++;
        }
        row++, col--; // reset for lower triangular diagonal
        while(row < n){  // (prints 6 8 9 part in the example)
            int i=row, j=col;
            while(i<n && j>0){
                ans.push_back(A[i][j]);
                i++;
                j--;
            }
            row++;
        }
        return ans;
	}

int main(){

    return 0;
}