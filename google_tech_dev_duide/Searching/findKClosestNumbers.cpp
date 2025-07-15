#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

int closest(int a, int b, int X){
    return ((abs(a - X) < abs(b - X))|| ((abs(a-X) == abs(b-X)) && (a<b)))? a : b;
}
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == k)
            return arr;

        int i = 0, j = arr.size()-1;
        while((j - i) >= k){
            if(closest(arr[i],arr[j],x) == arr[i])
                j--;
            else
                i++;
        }
        vector<int> result;
        for(int index = i; index <= j; index++)
            result.push_back(arr[index]);

        return result;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    int k = 4 , x = 3;

    vector<int> result = (new Solution)->findClosestElements(nums, k, x);
    for(int i : result)
        cout<<i<<endl;
}