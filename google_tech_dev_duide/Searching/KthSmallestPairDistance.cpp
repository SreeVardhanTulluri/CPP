#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int returnPairCount(vector<int>& nums, int k){
        int result = 0;
        int left = 0, right = 1;
        while(left < nums.size()-1 && right <= nums.size()-1){
            if(left != right && abs(nums[left] - nums[right]) <= k){
                result++;
                left++;
            }
            else
                right++;
        }
        return result;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int m_in = 0 ,m_ax = nums.back();
        while(m_in < m_ax){
            int mid = m_in + (m_ax - m_in)/2;
            int counter = returnPairCount(nums, mid);
            if(k == counter)
                return mid;
            else if(counter >= k)
                m_ax = mid;
            else
                m_in = mid;
        }
        return m_ax;
    }
};


int main(){
    vector<int> nums = {1,6,1};

    cout<<(new Solution)->smallestDistancePair(nums,3)<<endl;
}