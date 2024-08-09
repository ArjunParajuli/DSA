#include<bits/stdc++.h>
using namespace std;

/*
very much similar to reorganize string question
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

    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<Container, vector<Container>, cmp> pq;
        // insert into pq
        if(a > 0){
         pq.push({'a', a});   
        }
        if(b > 0){
         pq.push({'b', b});   
        }
        if(c > 0){
         pq.push({'c', c});   
        }

        // insert further only when pq has 2 or more elms
        while(pq.size() > 1){
            Container top = pq.top(); pq.pop();
            Container secondTop = pq.top(); pq.pop();

            // count is 2 or more then insert twice
            if(top.count >= 2){ 
                ans.push_back(top.elm);
                ans.push_back(top.elm);
                top.count -= 2;
            }else{  // count is only one
                ans.push_back(top.elm);
                top.count -= 1;
            }

            // same for second top but we want longest string, for that we insert twice only if secondtop.count is more than top.count
            if(secondTop.count >= 2 && secondTop.count >= top.count){ 
                ans.push_back(secondTop.elm);
                ans.push_back(secondTop.elm);
                secondTop.count -= 2;
            }else{ 
                ans.push_back(secondTop.elm);
                secondTop.count -= 1;
            }

            if(top.count > 0){
                pq.push(top);
            }
            if(secondTop.count > 0){
                pq.push(secondTop);
            }

            if(pq.size() == 1){
                Container top = pq.top(); pq.pop();
                if(top.count >= 2){ 
                    ans.push_back(top.elm);
                    ans.push_back(top.elm);
                    top.count -= 2;
                }else{  // count is only one
                    ans.push_back(top.elm);
                    top.count -= 1;
                }
            }
        }
        // for case when a=0, b=0, c=2 then it wont enter while loop and just print "", instead we wanna print "cc"
        if(pq.size() == 1){
                Container top = pq.top(); pq.pop();
                if(top.count >= 2){ 
                    ans.push_back(top.elm);
                    ans.push_back(top.elm);
                    top.count -= 2;
                }else{  // count is only one
                    ans.push_back(top.elm);
                    top.count -= 1;
                }
            }
        return ans;
    }