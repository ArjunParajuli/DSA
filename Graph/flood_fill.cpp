#include<bits/stdc++.h>
using namespace std;

// very similar to number of islands

    bool canMove(int i, int j, vector<vector<int>>& image, int prevColor){
        int n = image.size();
        int m = image[0].size();
        if(i>=0 && i<n && j>=0 && j<m && image[i][j] == prevColor)
            return true;
        return false;
    }

    void bfs(vector<vector<int>>& image, int sr, int sc, int color){
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            pair<int, int> front = q.front(); 
            q.pop();
            int tempx = front.first;
            int tempy = front.second;
            
            int cx[]={-1, 0, 1, 0};
            int cy[]={0, 1, 0, -1};
            for(int k=0;k<4;k++){
                int newx = tempx+cx[k];
                int newy = tempy+cy[k];
                if((newx != sr || newy != sc) && canMove(newx, newy, image, image[sr][sc])){
                    q.push({newx, newy});
                    image[newx][newy] = color;
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color){
            bfs(image, sr, sc, color);
            image[sr][sc] = color;
        }
        return image;
    }