#include<bits/stdc++.h>
using namespace std;

class Container{
    public:
    int data;
    int rowIdx;
    int colIdx;

    Container(int data, int rowIdx, int colIdx){
        this->data = data;
        this->rowIdx = rowIdx;
        this->colIdx = colIdx;
    }
};

/*
- create a min heap with first elms from all k arrays
- pop the top(min) elm and push the next index elm of that popped elm
*/

class Container{
    public:
    int data;
    int rowIdx;
    int colIdx;

    Container(int data, int rowIdx, int colIdx){
        this->data = data;
        this->rowIdx = rowIdx;
        this->colIdx = colIdx;
    }
};

    // custom comparator
    struct comp {
    bool operator()(const Container &a, const Container &b){
        return a.data > b.data;
    }
};

    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<Container, vector<Container>, comp> pq;
        vector<int> ans;
        
        // create min heap from first elms of all arrays  
        for(int row=0;row<k;row++){
            Container temp(arr[row][0], row, 0);
            pq.push(temp);
        }
        
        // pop the top(min) elm and push the next index elm of that popped elm
        while(!pq.empty()){
            Container top = pq.top();
            pq.pop();
            
            int topData = top.data;
            int topRowIdx = top.rowIdx;
            int topColIdx = top.colIdx;
            
            ans.push_back(topData);
            
            if(topColIdx+1 < k){
                Container temp(arr[topRowIdx][topColIdx+1], topRowIdx, topColIdx+1);
                pq.push(temp);
            }
        }
        return ans;
    }


int main(){

    return 0;
}