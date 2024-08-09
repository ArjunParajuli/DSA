#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

// void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         // transpose
//         for(int i=0;i<n;i++){
//             for(int j=i;j<m;j++){
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
//         // reverse all rows
//         for(int i=0;i<n;i++){
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
//     }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // swap cols
        int first=0, last=n-1;
        while(first < last){
            for(int i=0;i<n;i++){
                swap(matrix[i][first], matrix[i][last]);
            }
            first++;
            last--;
        }
    }

    int main(){
        vector<vector<int>> matrix ={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
        rotate(matrix);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout << matrix[i][j];
            }
            cout << endl;
        }

        return 0;
    }