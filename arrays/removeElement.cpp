#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int removeElement(vector<int>& nums, int val) {
        // if(nums.size() < 1)return 0;
        // if(1 == nums.size())
        //     return (val != nums[0]);
        // int counter;
        // int left = 0, right = nums.size()-1;
        // while(val == nums[right]){
        //     right--;
        //     counter++;
        // }
        // while(left <= right){
        //     if(nums[left] == val){
        //         swap(nums[left],nums[right]);
        //         right--;counter++;
        //     }
        //     left++;
        // }
        // return nums.size()-counter;
        int counter = nums.size();
        int cmp = 0, it = 1;
        while(it < nums.size()){
            if(nums[cmp] == nums[it]){
                nums[it] = 101;
                counter--;
            }
            else
                cmp = it;
            it++;
        }
        sort(nums.begin(), nums.end());
        return counter;

    }
};


int main(){

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout<<(new Solution)->removeElement(nums,3)<<endl<<endl<<endl;
    for(int num : nums)
        cout<<num<<endl;
}