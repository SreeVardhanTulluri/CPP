#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int maxSquares = sqrt(n);


        vector<int> dp_array(n+1,INT16_MAX);
        dp_array[0] = 0;

        for(int i = 0 ; i <= maxSquares ; i++){
            int square = i*i;

            for(int j = square ; j <=n ; j++){
                dp_array[j] = min(dp_array[j],dp_array[j-square]+1);
            }
        }
        for(int num : dp_array)
            cout<<"==="<<num<<endl;
        return dp_array[n];
    }
};

int main(){
    cout<<(new Solution)->numSquares(13)<<endl;
}