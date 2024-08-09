#include<iostream> 
#include<vector>
using namespace std;

// striver
// time : O(2^n) bcoz for every index, we have two options
// space : O(2^n)
/*
 for every index elm, we once take it and once don't take it
*/


void f(int ind, int n, int a[], vector<int>& arr, int k, int sum) {
    if (ind == n) {
        if (k == sum) {
            // print subsequence
            for (int i = 0; i < arr.size(); ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    // take
    arr.push_back(a[ind]);
    sum += a[ind];
    f(ind + 1, n, a, arr, k, sum);

    // don't take
    arr.pop_back();
    sum -= a[ind];
    f(ind + 1, n, a, arr, k, sum);
}

int main() {
    int a[] = {1, 2, 3};
    vector<int> arr;
    int n = 3;
    int k = 5;
    int sum = 0;
    f(0, n, a, arr, k, sum);

    return 0;
}
