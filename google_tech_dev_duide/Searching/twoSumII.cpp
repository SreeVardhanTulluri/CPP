#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        while(start < end){
            if(numbers[start] + numbers[end] == target)
                return {++start,++end};
            else if(numbers[start] + numbers[end] > target)
                end--;
            else
                start++;
        }
        return {1,1};
    }
};

int main(){
    vector<int> numbers = {2,7,11,15};
    vector<int> result = (new Solution)->twoSum(numbers, 9);
    cout<<result[0]<<'\t'<<result[1]<<endl;
}