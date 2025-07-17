#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1,nums2);
        vector<int> result;
        for(int i : nums1){
            auto it = find(nums2.begin(), nums2.end(), i);
            if(nums2.end() != it)
            {
                nums2.erase(it);
                result.push_back(i);
            }
        }
        return result;
    }
};


int main(){
    vector<int> nums1 = {1,2,1};
    vector<int> nums2 = {2,2};

    vector<int> result = (new Solution)->intersect(nums1,nums2);

    for(int i : result)
        cout<<i<<endl;
}
