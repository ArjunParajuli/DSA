#include<bits/stdc++.h>
using namespace std;

void findMaxProfit(vector<int>& prices, int i, int &min_price, int &max_profit){
        if(i == prices.size())
            return;

        if(prices[i] < min_price)
            min_price = prices[i];

        int currentProfit = prices[i]-min_price;
        if(currentProfit > max_profit)
            max_profit = currentProfit;

        findMaxProfit(prices, i+1, min_price, max_profit);
    }

    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;
        int max_profit=INT_MIN;
        findMaxProfit(prices, 0, min_price, max_profit);
        
        return max_profit;
    }

// can do it iteratively also
    int maxProfitIteratively(vector<int>& prices) {
        int min_price=INT_MAX;
        int max_profit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < min_price)
                min_price = prices[i];
            int curr_profit = prices[i]-min_price;
            if(curr_profit > max_profit)
                max_profit = curr_profit;
        }
        return max_profit;
    }

    int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices);

        return 0;
    }