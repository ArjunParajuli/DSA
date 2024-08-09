#include <iostream>
#include <queue>
using namespace std;

/*
# similar to merge k sorted lists
we need to find the smallest range having atleast one elm from all lists
algo:
- create a heap for finding max elm and min elm among first elm of all lists
- find range(max-min) and remove min elm and insert next elm of that removed min elm (maxm ko update karo at the time if inserting)
- do this and update range until anyone list goes empty and then return the min range among all the ranges
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

    struct comp {
    bool operator()(const Container &a, const Container &b){
        return a.data > b.data;
    }
    };

    vector<int> smallestRange(vector<vector<int>>& nums){
        priority_queue<Container, vector<Container>, comp> pq;
        int maxm = INT_MIN;
        int minm; 
        int k = nums.size();
        // create min heap with first elms from k lists
        for(int i=0;i<k;i++){
            int elm = nums[i][0];
            maxm = max(maxm, elm); // update maxm
            Container temp(elm, i, 0);
            pq.push(temp);
        }
        minm = pq.top().data;

        // initial range
        int startRange = minm;
        int endRange = maxm;
        
        while(!pq.empty()){
            Container top = pq.top();
            int topData = top.data;
            int topRowIdx = top.rowIdx;
            int topColIdx = top.colIdx;
            pq.pop();

            minm = top.data; // update min elm
            // we already have maxm val
            // compare current range with previous range
            if(maxm-minm < endRange-startRange){
                endRange = maxm;
                startRange = minm;
            }

            // insert next index elm of the min elm 
            if(topColIdx+1 < nums[topRowIdx].size()){
                 Container temp(nums[topRowIdx][topColIdx+1], topRowIdx, topColIdx+1);
                 pq.push(temp);
                 maxm = max(maxm, nums[topRowIdx][topColIdx+1]);  // update maxm after inserting
            }else{
                break;      // index goes out of bound
            }
        }
        return {startRange, endRange};
    }
