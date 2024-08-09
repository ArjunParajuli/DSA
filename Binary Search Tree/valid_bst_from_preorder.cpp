#include <iostream>
#include<algorithm>
using namespace std;

/*

soln is very much same as construct bst from preorder.
- use the same soln and at the end check if preIndex has traversed all the elms in the array or not
- if yes then that means valid bst was created using all the nodes
- else some elms were not used as nodes of bst, so valid bst can't be constructed from that traversal 

*/

  int preIndex = 0;
  void construct(int preorder[], int minm, int maxm, int &n){
        if(preIndex >= n || preorder[preIndex] > maxm || preorder[preIndex] < minm){
            return;
        }

        // no need to actually construct a bst bcoz we only need the preIndex posn at end to find our ans
            int currRootVal = preorder[preIndex++];
            construct(preorder, minm, currRootVal, n);  // update range
            construct(preorder, currRootVal, maxm, n);
        
    }
  
    int canRepresentBST(int arr[], int n) {
        int minm=INT_MIN, maxm=INT_MAX;
        construct(arr, minm, maxm, n);
        if(preIndex >= n)
            return 1;
        else
            return 0;
    }