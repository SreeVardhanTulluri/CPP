#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
private:

    int get_max(int start, int end, vector<int>& nums){
        if(start == end)
            return start;
        if(end - start == 1)
            return (nums[start] > nums[end])? start : end;
        int mid = start + (end - start)/2;
        int leftMax = get_max(start, mid, nums);
        int rightMax = get_max(mid+1, end, nums);
        return (nums[leftMax] > nums[rightMax])? leftMax : rightMax;
    }

public:
    int findPeakElement(vector<int>& nums){
        if(nums.empty())
            return -1;
        return get_max(0,nums.size()-1,nums);
    }
};

int main(){
    vector<int> nums = {9,9,1};
    int index = (new Solution)->findPeakElement(nums);
    cout<<index<<endl;
    // cout<<index<<" -> "<<nums[index]<<endl;
}