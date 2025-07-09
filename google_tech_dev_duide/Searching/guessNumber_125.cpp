/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
private:
    int pick;
public:
    Solution(int aPick){
        pick = aPick;
    }
    int guess(int n){
        if (n > pick)   return -1;
        else if (n < pick) return 1;
        return 0;
    }
    int guessNumber(int n) {
        int min = 1, max = n;
        while(min <= max){
            int  mid = min + (max - min)/2;
            switch (guess(mid))
            {
            case -1:
                max = mid-1;
                break;
            case 1:
                min = mid+1;
                break;
            case 0:
                return mid;
            }
        }
        return 0;
    }
};

#include <iostream>
using namespace std;

int main(){
    cout << (new Solution(6))->guessNumber(10) << endl;
    cout << (new Solution(1))->guessNumber(1) << endl;
    cout << (new Solution(1))->guessNumber(2) << endl;
}