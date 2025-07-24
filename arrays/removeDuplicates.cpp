#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums, int val) {
        int counter = nums.size();
        int cmp = 0, it = 1;
        bool duplicateFound = false;
        while(it < nums.size()){
            if(nums[cmp] == nums[it]){
                if(duplicateFound){
                    nums[it] = 1001;
                    counter--;
                }
                else
                    duplicateFound = true;
            }
            else{
                cmp = it;
                duplicateFound = false;
            }
            it++;
        }
        sort(nums.begin(), nums.end());
        return counter;
    }
};


int main(){

    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    cout<<(new Solution)->removeDuplicates(nums,3)<<endl<<endl<<endl;
    for(int num : nums)
        cout<<num<<endl;
}