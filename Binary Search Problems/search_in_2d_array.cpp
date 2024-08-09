#include<iostream>
#include<vector>

using namespace std;

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0) return false;
        int n = matrix.size(); //number of rows
        int m = matrix[0].size(); // no of cols
        int low = 0;
        int high = (n*m)-1;
        while(low <= high){
            int mid = low +(high - low)/2;
            if(matrix[mid/m][mid%m] == target){
                return true;
            }else if(matrix[mid/m][mid%m] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
 

 int main(){
        vector<vector<int>> nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}}; 
        int target = 3;

        cout << searchMatrix(nums, 3);

        return 0;
    }