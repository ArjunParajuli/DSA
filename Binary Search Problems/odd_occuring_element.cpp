#include <iostream>
#include <algorithm>

using namespace std;

int oddOccuringElement(int arr[],int n){
  int s = 0, e = n-1;
  int mid = s + (e-s)/2;
  while(s <= e){
    // single elm case
    if(s == e)
        return arr[s];

        //if mid is in odd index
        if(mid & 1){ // if true then, it denotes odd
            if(mid-1 >=0 && arr[mid] == arr[mid-1]) // we are at left part so go right
                s = mid+1;
            else     // we are at right
                e = mid-1;
        }else{ // mid is in even index 
            if(mid+1 < n && arr[mid] == arr[mid+1])  // we are in left so go right
                s = mid+2; // to avoid checking it twice
            else    // we are at right or we are at the answer index, thats why e = mid
            e = mid;  // e = mid-1 se ans lost hosakta hai
        }
        mid = s + (e-s)/2;
  }
  return -1;
}

int main()
{
    int arr[] = {10,10,50,50,70,70,60,60,70};
   cout << oddOccuringElement(arr, 9);

    return 0;
}