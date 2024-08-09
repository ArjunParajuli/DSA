#include <iostream>
#include <vector>
using namespace std;

// print all subarray iteratively time: O(n^3)
void subArray(vector<int> arr, int n)
{
    // Pick starting point
    for (int i=0; i<n; i++)
    {
        // Pick ending point
        for (int j=i; j<n; j++)
        {
            // Print subarray between current starting
            // and ending points
            for (int k=i; k<=j; k++)
                cout << arr[k] << " ";
 
            cout << endl;
        }
    }
}

// recursively time: O(n^2) and space:O(n)

void subarraysFromEachStart(vector<int> &v, int start, int end){
    // base case
    if(end == v.size())
        return;
    // solve one case
    for(int i=start;i<=end;i++){
        cout << v[i];
    }
    cout << endl;
    // recursion
    subarraysFromEachStart(v, start, end+1);
    
}

void recursivePrint(vector<int> &v){
    for(int start=0;start<v.size();start++){
        int end = start;
        subarraysFromEachStart(v, start, end);
    }
} 

int main() {
    vector<int> v = {1,2,3,4,5};
    recursivePrint(v);

    return 0;
}