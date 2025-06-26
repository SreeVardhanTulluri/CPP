#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for(char ch : s){
            switch (ch){
                case '[':
                case '{':
                case '(':   charStack.push(ch);
                            break;
                case ']':
                case '}':
                case ')':   if(charStack.empty()) return false;
                            if((ch == ']' && charStack.top() == '[') || (ch == '}' && charStack.top() == '{') || (ch == ')' && charStack.top() == '(')) charStack.pop();
                            else return false;
                            break;
            }
        }
        return charStack.empty();
    }
};