#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int min = 0 , max = INT8_MAX;
        while(min <= max){
            int mid = min + (max - min)/2;
            if(mid*mid == x)    return mid;
            else if (mid * mid > x)
                max = mid-1;
            else 
                min = mid +1;
        }
        return min-1;
    }
};


int main(){
    cout<<(new Solution)->mySqrt(1)<<endl;
}