
// Longest Repeating Character Replacement

/*
brute force: 

*/

/*
for each english upper char, apply the longestOnes ques. This gives us length of longest substring for each char.
And we take the maxm betn all the 26 chars.
*/

int longestOnes(string nums, int k, char ch) {
       int count0=0, currlen=0, maxlen=0, j=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i] != ch){
               count0++;
           }
           while(count0 > k){
               if(nums[j]!=ch){
                   count0--;
               }
               j++;
           }
           currlen = i-j+1;
           maxlen = max(maxlen, currlen);
       }
       return maxlen;
    }
    
    int characterReplacement(string s, int k) {
        int ans = INT_MIN;
        for(int i=0;i<26;i++){
            // This gives us length of longest substring after replacing k chars with our current alphabet. 
            // i.e. length of substr after replacing k chars with a, b, c ...
            int currans = longestOnes(s, k, i+'A');
            ans = max(ans, currans);
        }
        return ans;
    }