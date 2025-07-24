#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int totalDays = prices.size();
        // int profit = 0;
        // for(int i = 0 ; i< totalDays; i++)
        //     for(int j = i+1; j < totalDays; j++)
        //         profit = max(profit,(prices[j]-prices[i]));
        
        // return profit;
        int buyDate = 0, sellDate = 1, profit = 0;
        int totalDays = prices.size();
        while(buyDate < totalDays-1 && sellDate < totalDays){
            profit = max(profit, prices[sellDate] - prices[buyDate]);
            if(prices[sellDate] < prices[buyDate])
                buyDate = sellDate;
            sellDate++;
        }
        return profit;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<(new Solution)->maxProfit(prices)<<endl;
}