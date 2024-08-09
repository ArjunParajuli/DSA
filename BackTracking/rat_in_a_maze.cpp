#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// check if from current position we can move to new position or not 
// bool canMove(vector<vector<int>> &m, vector<vector<bool>> visited, int currx, int curry, int newx, int newy, int row, int col){
//     // index not out of bound, current posn isnt visited, 
//     if( newx>=0 && newx<row && newy>=0 && newy<col && visited[newx][newy]==false && m[newx][newy]==1){
//         return true;
//     }else
//     return false;
// }

// void getAllPaths(vector<vector<int>> &m, int row, int col, int currx, int curry, vector<string> &ans, string &output, vector<vector<bool>> visited){
//         // base case
//         // if coordinates at end, then return 
//         if(currx == row-1 && curry == col-1){
//             ans.push_back(output);
//             return;
//         }

//         // solve one case and let recursion do the other
//         //Go up
//         int newx = currx-1;
//         int newy = curry;
//         if(canMove(m, visited, currx, curry, newx, newy, row, col)){
//             // mark visited
//             visited[newx][newy] = true;
//             // recursive call for new position
//             output.push_back('U');
//             getAllPaths(m, row, col, newx, newy, ans, output, visited);
//             // backtracking
//             output.pop_back();
//             visited[newx][newy] = false;
//         }

//         // Go Right         
//         newx = currx;
//         newy = curry+1;
//         if(canMove(m, visited, currx, curry, newx, newy, row, col)){
//             // mark visited
//             visited[newx][newy] = true;
//             // recursive call for new position
//             output.push_back('R');
//             getAllPaths(m, row, col, newx, newy, ans, output, visited);
//             // backtracking
//             output.pop_back();
//             visited[newx][newy] = false;
//         }

//         // Go Down         
//         newx = currx+1;
//         newy = curry;
//         if(canMove(m, visited, currx, curry, newx, newy, row, col)){
//             // mark visited
//             visited[newx][newy] = true;
//             // recursive call for new position
//             output.push_back('D');
//             getAllPaths(m, row, col, newx, newy, ans, output, visited);
//             // backtracking
//             output.pop_back();
//             visited[newx][newy] = false;
//         }

//         // Go Left        
//         newx = currx-1;
//         newy = curry;
//         if(canMove(m, visited, currx, curry, newx, newy, row, col)){
//             // mark visited
//             visited[newx][newy] = true;
//             // recursive call for new position
//             output.push_back('L');
//             getAllPaths(m, row, col, newx, newy, ans, output, visited);
//             // backtracking
//             output.pop_back();
//             visited[newx][newy] = false;
//         }

//     }
    
// vector<string> findPath(vector<vector<int>> &m, int n) {
//         vector<string> ans;
//         string output;
//         int row=n, col=n;
//         vector<vector<bool>> visited(row, vector<bool>(col, false));
//         getAllPaths(m, row, col, 0, 0, ans, output, visited);
//         return ans;
// }


bool isSafe(int x,int y,int n,vector<vector<int>>visited,vector<vector<int>>&m){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }

    void solve(vector<vector<int>>&m,int n,vector<string>&ans,int x,int y,vector<vector<int>>visited,string path){
        //YOu Have reached x,y
        //Base Case
        if(x==n-1&&y==n-1){
            ans.push_back(path);
            return ;
        }
        
        visited[x][y]=1;
        
        //4 choices - D,L,R,U
        
        //down
        int newx=x+1;
        int newy=y;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('D');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        //Left
         newx=x;
         newy=y-1;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('L');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        //Right
         newx=x;
         newy=y+1;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('R');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        //UP
         newx=x-1;
         newy=y;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('U');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        visited[x][y]=0;
    }


    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if(m[0][0]==0){
            return ans;
        }
        
        vector<vector<int>>visited=m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        
        string path="";
        solve(m,n,ans,0,0,visited,path);
        sort(ans.begin(),ans.end());
        return ans;
    }


int main(){
    vector<vector<int>> maze = {
	{1,0,0,0},
	{1,1,0,0},
	{1,1,1,0},
	{1,1,1,1}
	};
    vector<string> ans;
    ans = findPath(maze, 4);
    for(auto itr:ans)
        cout << itr << endl;

    return 0;
}