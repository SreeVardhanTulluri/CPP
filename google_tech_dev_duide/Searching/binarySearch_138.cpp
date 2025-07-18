#include <iostream>
#include <vector>

using namespace std;

class Solution {
   
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {5};
    cout<<(new Solution)->search(nums, 5)<<endl;
}