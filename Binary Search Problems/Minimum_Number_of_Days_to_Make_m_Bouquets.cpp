    
    
    // check if mid value can make m bouquests or not, acc to this eliminate the search space
    // Time Complexity: O(log(max(arr[])-min(arr[])+1) * N)
    bool checkPossibleAns(vector<int>& bloomDay, int mid, int m, int k){
        int adjcnt = 0;
        int bcnt = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid) adjcnt++;
            else adjcnt=0;
            if(adjcnt == k){
                bcnt++;
                adjcnt=0;
            }
        }
        if(bcnt >= m) return 1;
        else return 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(checkPossibleAns(bloomDay, mid, m, k)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return ans;
    }