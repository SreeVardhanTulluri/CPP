#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events based on start day
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int day = 0, index = 0, n = events.size(), result = 0;
        
        while (!minHeap.empty() || index < n) {
            if (minHeap.empty()) {
                day = events[index][0];
            }
            while (index < n && events[index][0] <= day) {
                minHeap.push(events[index][1]);
                index++;
            }
            minHeap.pop();
            result++;
            day++;
            
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }
        return result;
    }
};

int main(){
    vector<vector<int>> event_list = {{1,4},{4,4},{2,2},{3,4},{1,1}};

    cout<<(new Solution)->maxEvents(event_list)<<endl;
}