#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 // we can do either: power gawakar score increase or score gawakar power increase
// sort array so that, jab score badhana hai suruse kam power gawalo and
// jab power badhana hai then last se greater power lekar score lose karlo

int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i=0, j=tokens.size()-1, score = 0, maxScore=0;
        while(i<=j){
            if(power >= tokens[i]){ 
                power -= tokens[i++];
                score += 1;
                maxScore = max(maxScore, score);  // maintain maxScore bcoz score can become 0 also even if it was higher once and we must return the maxm one
            }else if(score >= 1){
                power += tokens[j--];
                score -= 1;
            }else{
                return maxScore;
            }
        }
        return maxScore;
    }

int main(){
    vector<int> arr = {100, 200, 300, 400};
    int power = 200;
    cout << bagOfTokensScore(arr, power);

    return 0;
}