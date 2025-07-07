#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty()) return 0.00;
        if(nums1.empty()){
            int size = nums2.size();
            if(size&1)
                return nums2[size/2];
            else
                return (nums2[(size/2)-1] + nums2[size/2])/2.0;
        }
        if(nums2.empty()){
            int size = nums1.size();
            if(size&1)
                return nums1[size/2];
            else
                return (nums1[(size/2)-1] + nums1[size/2])/2.0;
        }
        int size = nums1.size() + nums2.size();
        if(size&1){
            int ptr1 = 0 , ptr2 = 0 ;
            size /= 2;
            while(size > 0){
                if (nums1[ptr1] > nums2[ptr2])
                    ptr2++;
                else
                    ptr1++;
                size--;
            }
            return double((nums1[ptr1] > nums2[ptr2])? nums2[ptr2] : nums1[ptr1]);
        }
        else{
            int ptr1 = 0 , ptr2 = 0 ;
            size /= 2;
            while(size > 1){
                if (nums1[ptr1] > nums2[ptr2])
                    ptr2++;
                else
                    ptr1++;
                size--;
            }
            return (nums1[ptr1]+nums2[ptr2])/2.0;
        }
    }
};


int main(){
    Solution *obj = new Solution;
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {6,7,8,9,10,11,12,13,14,15,16,17};
    cout<<double(obj->findMedianSortedArrays(nums1,nums2))<<endl;
}