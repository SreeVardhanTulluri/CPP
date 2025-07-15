#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

    int get_min(int start, int end, vector<int>& nums){
        if(start == end)
            return start;
        if(end - start == 1)
            return (nums[start] < nums[end])? start : end;
        int mid = start + (end - start)/2;
        int leftMax = get_min(start, mid, nums);
        int rightMax = get_min(mid+1, end, nums);
        return (nums[leftMax] < nums[rightMax])? leftMax : rightMax;
    }

public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        else if(n == 2)
            return (nums[0] > nums[1]);
        else
            return get_min(0,n-1,nums);
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2,3};
    // vector<int> nums = {2,3};
    int index = (new Solution)->findMin(nums);
    cout<<index<<" -> "<<nums[index]<<endl;
}