#include <iostream>
#include <vector>
using namespace std;

class TwoSum{
    public:
        vector <int>  solution (vector <int> &nums , int target){
            for (int i =0;i < sizeof(nums)/sizeof(nums[0]); i++){
                for(int j= i+1 ; j < sizeof(nums)/sizeof(nums[0]); j++){
                    if (nums[i] + nums[j] == target)
                        return {i,j};
                }
            }
            return {0,0};
        }
};

int main(){
    TwoSum t;
    vector <int> nums = {-6,7,11,15};
    for(int number : t.solution(nums,9)){
        cout<<number << endl;
    }

}