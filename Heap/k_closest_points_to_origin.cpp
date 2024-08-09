#include<bits/stdc++.h>
using namespace std;

/*
algo: (we have to find k closest points to origin)
- make a min heap and push elms using a comparetor such that elm with smallest (distance) remains at top
- pop elms k times  from min heap to get the ans 
*/

class comp{
        public:
        // min heap so (d1>d2)
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            int dist1 = a.first*a.first + a.second*a.second;
            int dist2 = b.first*b.first + b.second*b.second;

            return dist1 > dist2;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        // pq of type pair in it
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for(int i=0;i<points.size();i++){
            // insert each inner array in the pq according to the given comparetor
            pair<int, int> temp;
            temp.first = points[i][0];
            temp.second = points[i][1];

            pq.push(temp);
        }
        // pop out elms from pq
        while(k--){
            pair<int, int> temp = pq.top();
            pq.pop();
            ans.push_back({temp.first, temp.second});
        }
        return ans;
    }


int main(){
    vector<vector<int>> points = {
        {3,3},{5,-1},{-2,4}
    };

    vector<vector<int>> ans = kClosest(points, 2);
    for(int i=0;i<points.size();i++){
        for(int j=0;j<2;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}