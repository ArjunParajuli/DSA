#include<bits/stdc++.h>
using namespace std;

/*
Greedy means thinking about present and not about the future/optimal
some greedy data structures and algorithms are priority_queues, sorting, set

Note: Mostly in greedy approaches, we use either of these: sorting, max_heap, min_heap, sets,etc
*/

// problem link: https://www.spoj.com/problems/DEFKIN/

/*
algo:
- store diff betn each x & y coordinates of each tower
- now find the largest gap i.e. 
*/


int main(){
    int row=8, col=15, tower=3;
    vector<pair<int, int>> loc(3);
    loc[0] = {3, 8};
    loc[1] = {11, 2};
    loc[2] = {8, 6};


    // answer starts here

    // store x coordinates 
    vector<int> xDim;
    // store first and last coordinates
    xDim.push_back(0);
    xDim.push_back(col+1);
    // store all given coordinates
    for(int i=0;i<loc.size();i++){
        xDim.push_back(loc[i].first);
    }
    // sort to keep them linearly
    sort(xDim.begin(), xDim.end());


    // store y coordinates 
    vector<int> yDim;
    // store first and last coordinates  
    yDim.push_back(0);
    yDim.push_back(row+1);
    // store all given coordinates
    for(int i=0;i<loc.size();i++){
        yDim.push_back(loc[i].second);
    }
    // sort to keep them linearly
    sort(yDim.begin(), yDim.end());


    // store difference between each tower's x coordinates
    vector<int> xAns;
    for(int i=1;i<xDim.size();i++){
        int diff = xDim[i]-xDim[i-1]-1;
        xAns.push_back(diff);
    }

    // store difference between each tower's y coordinates
    vector<int> yAns;
    for(int i=1;i<yDim.size();i++){
        int diff = yDim[i]-yDim[i-1]-1;
        yAns.push_back(diff);
    }

    // find maximum gap between coordinates of each tower
    int maxm = INT_MIN;
    for(int i=0;i<xAns.size();i++){
        for(int j=0;j<yAns.size();j++){
            int product = xAns[i] * yAns[j];
            maxm = max(maxm, product);
        }
    }
    cout << maxm << endl;


    return  0;
}