#include<iostream>
#include<stack>
#include<vector>
// #include<pair>
using namespace std;

// all operations in O(1) time
// This is achieved using a vector of pairs, where each pair contains the element and the minimum value up to that element.
 
  vector<pair<int, int>> s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            pair<int, int> elm;
            elm.first = val;
            elm.second = val;
            s.push_back(elm);
        }else{
            pair<int, int> elm;
            elm.first = val;
            int prevMin = s.back().second;
            elm.second = min(prevMin, val);
            s.push_back(elm);
        }
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        int topElm = s.back().first;
        return topElm;
    }
    
    int getMin() {
        int minElm = s.back().second;
        return minElm;
    }