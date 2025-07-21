#include <iostream>

using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        k--;
        int counter = 0;
        while(0 < k){
            if(1 == k%2)
                counter++;
            k /= 2;
        }
        return counter%2;
    }  
};

int main(){
    cout<<(new Solution)->kthGrammar(3,3)<<endl;
}