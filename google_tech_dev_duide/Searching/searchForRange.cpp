#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    pair<int,int> binarySearch(int start, int end, vector<int>& nums, int target){
        if(start == end){
            if(nums[start] == target)
                return {start,end};
            else
                return {-1,-1};
        }
        else if ( start < end){
            int result_start = -1, result_end = -1;
            int mid = start + (end - start)/2;
            if(target < nums[mid])
                return binarySearch(start, mid-1, nums, target);
            else if (target > nums[mid])
                return binarySearch(mid+1, end, nums, target);
            else{
                pair<int,int> result_pair;
                int st ,en;
                result_pair = binarySearch(start, mid-1, nums, target);
                if(result_pair.first != -1 && result_pair.second != -1){
                    if(mid > result_pair.first) st = result_pair.first;
                }
                else st = mid;
                result_pair = binarySearch(mid+1, end, nums, target);
                if(result_pair.first != -1 && result_pair.second != -1){
                    if(mid < result_pair.second) en = result_pair.second;
                }
                else en = mid;
                return {st,en};
            }
                
        }
        return {-1,-1};
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //TODO : Binary search with Two Pointer apprach;
        if(nums.size() == 0)
            return {-1,-1};
        pair<int,int> result = binarySearch(0,nums.size()-1, nums, target);
        return {result.first, result.second};
    }
};

int main(){
    vector<int> nums = {8};
    vector<int> result = (new Solution)->searchRange(nums,8);
    cout<<result[0]<<" "<<result[1]<<endl;
}