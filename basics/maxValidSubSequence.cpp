#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
bool helper(vector<int>& nums, int k){
    
}
public:
    int maximumLength(vector<int>& nums, int k) {
        int m_in = 2, m_ax = nums.size();
        while(m_in < m_ax){
            int mid = m_in + (m_ax - m_in)/2;

        }
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    cout<<(new Solution)->maximumLength(nums,2)<<endl;
}