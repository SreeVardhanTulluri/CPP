#include <iostream>
#include <string>

using namespace std;
char pop(string &s, int i){
    char ch = s.at(i);
    s.erase(s.begin() + i);
    return ch;
}
class Solution{
    public:
        string robotTuring(string &s){
            string t,result;
            while(s.length() > 0){
                char max = '\0';
                for(char ch : s){
                    if (max == '\0'){
                        max = ch;
                    }
                    else if (ch > max){
                        max = ch;
                    }
                }
                int index = s.find(max);
                t += max;
                max = '\0';
                s.erase(s.begin() + index);
            }
            for(int i = t.length()-1 ; i > -1 ; i--) {result += pop(t,i);}
            return result;
        }
};

int main(){
    string greet = "azz";
    Solution robot;
    cout << greet <<endl;
    cout << robot.robotTuring(greet) <<endl;
    cout << greet <<endl;
}
