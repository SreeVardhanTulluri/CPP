#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isNumber(string s){
        return all_of(s.begin(),s.end(),::isdigit);
    }
    string decodeString(string s) {
        stack<char> charStack;
        for(char ch : s){
            if(ch == ']'){
                string substr = "";
                while(charStack.top() != '['){
                    substr = charStack.top() + substr;
                    charStack.pop();
                }
                charStack.pop();
                string count = "";
                while(!charStack.empty() && isdigit(charStack.top())){
                    count = charStack.top() + count;
                    charStack.pop();
                }
                int number = stoi(count);
                count = "";
                for(int i = 0 ; i < number ; i++)
                    count += substr;
                for(char c : count)
                    charStack.push(c);
                
            }
            else
                charStack.push(ch);
        }
        string result = "";
        while(!charStack.empty()){
            result = charStack.top() + result;
            charStack.pop();
        }
        return result;
    }
};


int main(){
    Solution *sol = new Solution();
    cout << sol->decodeString("3[a]2[bc]") << endl;
}