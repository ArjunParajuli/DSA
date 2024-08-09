#include<bits/stdc++.h>
using namespace std;

/*
codehelp - heaps class 4
algo:
- count freq of all chars and push all chars in maxheap(minheap won't work), maxheap contains elm and its count
- now insert the max and second max frequency elm in ans string. (we insert two elms so that side by side same elm na ho)
-  
*/

 class Container{
        public:
        char elm;
        int count;

        Container(char elm, int count){
            this->elm = elm;
            this->count = count;
        }
    };

    class cmp{
        public:
        bool operator()(Container x, Container y){
            return x.count < y.count;
        }
    };

    string reorganizeString(string s) {
        int hash[26] = {0};
        // store freq
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        priority_queue<Container, vector<Container>, cmp> pq;
        // insert in maxheap
        for(int i=0;i<26;i++){
            if(hash[i] > 0){
                Container temp(i+'a', hash[i]);
                pq.push(temp);
            }
        }
        string ans="";
        // insert first two elms in ans
        while(pq.size() > 1){ // >1 bcoz we need two top elms 
            Container top = pq.top(); pq.pop();
            Container secondTop = pq.top(); pq.pop();
            ans += top.elm;
            top.count--;
            ans += secondTop.elm;
            secondTop.count--;
            // count is reamining then push the elm back
            if(top.count > 0)
                pq.push(top);
            if(secondTop.count > 0)
                pq.push(secondTop);
        }
        // single elm left then 
        if(pq.size() == 1){
            Container top = pq.top(); pq.pop();
            ans += top.elm;
            top.count--;
            // count still remaining means that elm will definitely come side by side
            if(top.count != 0)
                return "";
        }

        return ans;
    }