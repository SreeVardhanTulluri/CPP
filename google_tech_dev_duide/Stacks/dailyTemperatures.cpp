#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int daysCount = temperatures.size();
        vector<int> ans(daysCount,0);
        stack<int> stk;

        for(int i = 0; i < daysCount ; i++){
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                int prev = stk.top();
                ans[prev] = i - prev;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};