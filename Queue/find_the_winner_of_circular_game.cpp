#include<iostream>
#include<queue>
using namespace std;

 int findTheWinner(int n, int k) {
       queue<int> q;
       for(int i=1;i<=n;i++){
           q.push(i);
       }
       int count=0;
       while(!q.empty()){
           if(q.size() == 1)
                return q.front();
            int elm = q.front();
            q.pop();
            count++;
            if(count%k != 0)
                q.push(elm);
       }
       return -1;
    }

    int main(){
        cout << findTheWinner(5, 2);

        return 0;
    }