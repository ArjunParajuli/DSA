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

Time Complexity: O(K^2 * log K), Insertion and deletion in a Min Heap requires log K time and for all K^2 elements it takes (K^2 * log K) time.
Auxiliary Space: O(K), If Output vector is ignored then the only space required is the Min-Heap of K elements.
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