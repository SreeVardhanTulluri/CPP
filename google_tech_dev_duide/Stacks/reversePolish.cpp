#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> counter;
        for(string token : tokens){
            try
            {
                counter.push(stoi(token));
            }
            catch(const std::invalid_argument& e)
            {
                int a = counter.top();
                counter.pop();
                int b = counter.top();
                counter.pop();
                switch(token[0]){
                    case '+':
                        counter.push(a+b);
                        break;
                    case '/':
                        counter.push(floor(a/b));
                        break;
                    case '-':
                        counter.push(a-b);
                        break;
                    case '*':
                        counter.push(a*b);
                        break;
                }
            }
            
        }
        return counter.top();
    }
};


int main(){
    return 0;
}