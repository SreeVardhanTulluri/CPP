#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class FindSumPairs {
public:
    vector<int> n1,n2;
    unordered_map<int, int> frequency_table;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(int n : nums2){
            if(frequency_table.count(n) == 0)
                frequency_table[n] = 1;
            else
                frequency_table[n] = frequency_table.at(n) +1;
        }
    }
    
    void add(int index, int val) {
        frequency_table[n2[index]] -=1;
        n2[index] += val;
        if(frequency_table.count(val) == 0)
            frequency_table[val] = 1;
        else
            frequency_table[val] = frequency_table.at(val) +1;
    }
    
    int count(int tot) {
        int counter = 0;
        for(int num : n1)
            if (frequency_table.count(tot-num) != 0)
            counter += frequency_table.at(tot-num);
        return counter;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

 int main(){
    vector<int> nums1 = {1,1,2,2,2,3};
    vector<int> nums2 = {1,4,5,2,5,4};

    FindSumPairs *obj = new FindSumPairs(nums1,nums2);
    cout<<obj->count(7)<<endl;
    obj->add(3,2);
    cout<<obj->count(8)<<endl;
    cout<<obj->count(4)<<endl;
    obj->add(0,1);
    obj->add(1,1);
    cout<<obj->count(7)<<endl;


 }