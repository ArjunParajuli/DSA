#include<iostream>
#include<queue>
using namespace std;

/*
- for every character in string:- 
- update its frequency in hash map
- insert into queue
- check frequency of front elm of queue, if freq == 1 then append it to answer else 
- pop front elm from queue until elm with freq==1 found. After popping reqd elms, if queue empty append # else append front elm
*/

	string FirstNonRepeating(string s){
            queue<char> q;
            int freq[256]={0};
            string ans="";
            for(int i=0;i<s.size();i++){
                char ch = s[i];
                freq[ch]++;
                q.push(ch);
                if(freq[q.front()] == 1){
                    ans+=q.front();
                }else{
                    while(!q.empty() && freq[q.front()]!=1)
                        q.pop();
                    if(q.empty())
                        ans+="#";
                    else 
                        ans+=q.front(); 
                }
            }
            return ans;
		}

int main(){
    cout << FirstNonRepeating("aabc");

    return 0;
}