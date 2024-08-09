#include <iostream>
#include <algorithm>

using namespace std;

// using mid-2 or mid+2 to avoid comparing of element twice 
int binarySearch(int arr[], int elm, int n){
  int s = 0, e = n-1;
  int mid = s + (e-s)/2;
  while(s <= e){
    if(arr[mid-1] == elm && mid-1>=0)  // so that index doesnt go negative
        return mid-1;
    if(arr[mid] == elm)
        return mid;
    if(arr[mid+1] == elm && mid+1 <= n-1)
        return mid+1;
    if(arr[mid] > elm)
        e = mid-2;
    else    
        s = mid+2;

    mid = s + (e-s)/2;
  }
  return -1;
}

int main()
{
    int arr[] = {20,10,30,50,40,70,60};
    int ans = binarySearch(arr, 60, 7);
    if(ans != -1)
        cout << "Element found at index " << ans << endl;
    else   
        cout << "Element not foumd" << endl;

    return 0;
}