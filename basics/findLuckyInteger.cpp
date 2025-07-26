#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> counter;
        for(int number : arr){
            if(counter.count(number) == 0)
                counter[number] = 1;
            else
                counter[number] = counter.at(number)+1;
        }
        int max = -1;
        for (const auto& pair : counter)
            if(pair.first == pair.second)
            max = (max > pair.first) ? max : pair.first;

        return max;
    }
};