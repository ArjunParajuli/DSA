#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    for(int i=0;i<K;i++){
        // process first window and insert index in deque
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    // stores answer of first window in vector
    vector<long long> v;
    if(dq.size()>0){
        v.push_back(A[dq.front()]);
    }else{
        v.push_back(0);
    }
    for(int i=K;i<N;i++){
        //pop element in deque if it is not in the current window
        if(!dq.empty() && i-dq.front()>=K){
            dq.pop_front();
        }
        //push element
        if(A[i]<0){
            dq.push_back(i);
        }
        //stores answer
        if(dq.size()>0){
        v.push_back(A[dq.front()]);
    }else{
        v.push_back(0);
    }
    }
     return v;                              
 }