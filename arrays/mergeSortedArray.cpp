#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>result;
        int i = 0 , j  = 0 ;
        while(i < m && j < n){
            if(nums2[j] < nums1[i]){
                result.push_back(nums2[j]);
                j++;
            }
            else{
                result.push_back(nums2[i]);
                i++;
            }
        }
        while(i < m){
            result.push_back(nums1[i]);
            i++;
        }
        while( j < n){
            result.push_back(nums2[j]);
            j++;
        }
        nums1 = result; 
    }
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        int counter;
        for(int i = 0; i < k ; i++){
            if(val == nums[i]){
                nums.erase(nums.begin()+i);
                nums.push_back(-1);
                counter++;
            }
        }
        return k-counter;
    }
};


int main(){
    // vector<int> nums1 = {2,0};
    vector<int> nums1 = {3,2,2,3};
    // vector<int> nums2 = {1};
    // vector<int> nums2 = {};
    // nums1.emplace(nums1.begin() + 3,9);
    // (new Solution)->merge(nums1,1,nums2,1);
    cout<<(new Solution)->removeElement(nums1,3)<<endl<<endl<<endl;
    for(int num : nums1)
        cout<<num<<endl;
}