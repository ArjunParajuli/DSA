#include <iostream>
#include <vector>
using namespace std;

// print starting row
// print ending col
// print ending row
// print starting col

vector<int> spiralPrint(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    int totalElm = row * col;
    int startRow = 0;
    int endRow = row-1;
    int startCol = 0;
    int endCol = col-1;
    int count = 0;
    vector<int> ans;

    while(count < totalElm){
        // print starting row
        for(int i=startCol;i<=endCol && count < totalElm;i++){       // loop using cols for printing rows
            ans.push_back(matrix[startRow][i]);
            count++;
        }
        startRow++;

        // print ending col
        for(int i=startRow;i<=endRow && count < totalElm;i++){       // loop using rows for printing colmns
            ans.push_back(matrix[i][endCol]);    // bcoz endcol remains same
            count++;
        }
        endCol--;

        // print ending row
        for(int i=endCol;i>=startCol && count < totalElm;i--){
            ans.push_back(matrix[endRow][i]);   // bcoz endRow remains same
            count++;
        }
        endRow--;

        // print starting colmn
        for(int i=endRow;i>=startRow && count < totalElm;i--){
            ans.push_back(matrix[i][startCol]);
            count++;
        }
        startCol++;

    } 
    return ans;
}

int main(){

    vector<vector<int>> matrix 
    { 
                    { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 },
					{ 17, 18, 19, 20 } 
    };
    vector<int> ans = spiralPrint(matrix); 
    for(int itr : ans){
        cout << itr << " ";
    }

    return 0;
}