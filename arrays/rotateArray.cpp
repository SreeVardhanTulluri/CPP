#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(0 == k)
            return;
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 5;
    (new Solution)->rotate(nums,k);
    for(int num : nums)
        cout<<num<<endl;
}