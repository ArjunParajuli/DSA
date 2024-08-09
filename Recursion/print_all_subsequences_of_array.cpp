#include<iostream>
#include<vector>
using namespace std;

void printAllSubSequences(int i, int n, vector<int> arr, vector<int> temp){
    if(i==n){
        for(auto itr : temp){
            cout << itr;
        }
        cout << endl;
        return;
    }
    // take curr elm
    temp.push_back(arr[i]);
    printAllSubSequences(i+1, n, arr, temp);
    // don't take curr elm
    temp.pop_back();
    printAllSubSequences(i+1, n, arr, temp);
}

int main(){
    vector<int> arr = {3,1,2};
    int i=0, n=arr.size();
    vector<int> temp;
    printAllSubSequences(i, n, arr, temp);

    return 0;
}