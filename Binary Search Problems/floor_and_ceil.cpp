#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	pair<int, int> ans;
	if(x < a[0]){
		return {-1, a[0]};
	}
	if(x > a[n-1]){
		return {a[n-1], -1}; 
	}
	int start=0, end=n-1;
	int fl=-1, cl=-1;
	while(start <= end){
		int mid = start + (end-start)/2;
		if(a[mid] == x){
			return {a[mid], a[mid]};
		}else if(a[mid] < x){
			start=mid+1;
			fl = mid;
			cl = mid+1;
		}else{
			end=mid-1;
			fl=mid-1;
			cl=mid;
		}
	}
	ans.first=a[fl];
	ans.second=a[cl];
	return ans;
}

int main(){
    vector<int> a={3,4,4,7,8,10};
    pair<int, int> ans;
    ans = getFloorAndCeil(a, a.size(), 5);
    cout << ans.first << " " << ans.second;

    return 0; 
}