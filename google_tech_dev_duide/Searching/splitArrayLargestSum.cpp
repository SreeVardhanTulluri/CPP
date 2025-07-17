#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int m_in = -1 , m_ax = 0;
        for(int num : nums){
            m_in = max(m_in, num);
            m_ax += num;
        }
        while(m_in < m_ax){
            int mid = m_in + (m_ax - m_in)/2;
            int sum = 0 , pieces = 1;
            for(int i = 0 ; i < nums.size() ; i++){
                if(sum + nums[i] > mid){
                    sum = nums[i];
                    pieces++;
                }
                else
                    sum += nums[i];
            }
            if(pieces <= k)
                m_ax = mid;
            else
                m_in = mid +1;
        }
        return m_in;
    }
};


int main(){
    vector<int> nums = {7,2,5,10,8};
    cout<<(new Solution)->splitArray(nums,4)<<endl;
}