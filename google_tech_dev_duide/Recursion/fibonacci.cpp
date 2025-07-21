#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int,int> cache;    
public:

    int fib(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else{
            if( 0 == cache[n])
                cache[n] = fib(n-1) + fib(n-2);
            return cache[n];
        }
    }
};

int main(){
    cout<<(new Solution)->fib(44)<<endl;
}