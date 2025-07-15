#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if((target >= letters.back()) || (target< letters.front()))
            return letters.front();
        for(int i = 0; i < letters.size(); i++)
            if(target < letters[i])
                return letters[i];
        // while(!letters.empty())
        //     if(letters.front() <= target)
        //         letters.erase(letters.begin());
        //     else
        //         return letters.front();
        // return letters.front();
    }
};

int main(){
    vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cout<<(new Solution)->nextGreatestLetter(letters,'h')<<endl;
}