#include <Queue>
#include <iostream>
using namespace std;    // provide a scope to identifiers inside a namespace

bool check_rotation(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    queue<char> q1;
    for (int i = 0; i < s1.size(); i++) {   // insert s1 in queue1
        q1.push(s1[i]);
    }
    queue<char> q2;
    for (int i = 0; i < s2.size(); i++) {   // insert s2 in queue2
        q2.push(s2[i]);
    }
    int k = s2.size();
    while(k--){
        int popped = q2.front();    // pop q2's front elm
        q2.pop();                   
        q2.push(popped);            // pushing that last elm into q2 at last pos
        if(q1 == q2)                // check if rotated queue2 matches queue1
            return true;
    }
    return false;

}

int main(){
    string str1="BALL";
    string str2="LLBA";
    cout<<check_rotation(str1, str2);

    return 0;
}