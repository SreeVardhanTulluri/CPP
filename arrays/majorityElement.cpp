#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counterDict;
        int n = nums.size();
        for(int num : nums){
            counterDict[num]++;
            if(counterDict.at(num) > n/2)
                return num;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {3,2,3};
    cout<<(new Solution)->majorityElement(nums)<<endl;
}