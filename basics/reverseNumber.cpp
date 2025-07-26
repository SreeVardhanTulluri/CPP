#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        string number = to_string(x);
        string result = "";
        if(number[0] == '-'){
            result = "-";
            number.erase(0,1);
        }
        while(!number.empty()){
            result.push_back(number.back());
            number.pop_back();
        }
        try
        {
            return stoi(result);
        }
        catch(const std::exception& e)
        {
            return 0;
        }
         
    }
};