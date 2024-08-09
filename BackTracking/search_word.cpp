#include<bits/stdc++.h>
using namespace std;

/*
algo:
- start searching from the fisrt cell using dfs func

time complexity is O(m * n) and the space complexity is O(word.size()).
*/


// dfs func searches from a specific cell (i, j) on the board to find the given word.
bool dfs(vector<vector<char>>& board, string &word, int i, int j, int currIdx){
    // entire word has been found
        if(currIdx == word.size())
            return true;
    // current cell (i, j) is out of bounds or char in the current cell does not match the character in the word
        if(i==-1 || i==board.size() || j==-1 || j==board[0].size() || board[i][j] != word[currIdx])
            return false;

    // store curr char & overwrite with '*' to avoid checking back the same char 
        char temp = board[i][j];
        board[i][j] = '*';
    // Recursively explore the neighboring cells (up, down, left, right) to find the next character of the word
        bool isFound = dfs(board, word, i, j+1, currIdx+1) || dfs(board, word, i+1, j, currIdx+1) || dfs(board, word, i, j-1, currIdx+1) || dfs(board, word, i-1, j, currIdx+1);
    // backtrack (restore original character in that cell)
        board[i][j] = temp;

    // if char is found in any of the neighbouring cell, isFound will be true
        return isFound;
    }


// this func iterates over each cell of the board and checks if the word can be found starting from that cell using the dfs function.
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }