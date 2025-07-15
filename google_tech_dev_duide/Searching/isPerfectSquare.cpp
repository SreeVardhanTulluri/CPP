#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if( 1 == num )return true;
        int start = 0 , end = num;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(mid == num/mid && num%mid == 0)
                return true;
            else if(mid > num/mid)
                end = mid-1;
            else
                start = mid+1;
        }
        return false;
    }
};

int main(){
    cout<<(new Solution)->isPerfectSquare(5)<<endl;
}