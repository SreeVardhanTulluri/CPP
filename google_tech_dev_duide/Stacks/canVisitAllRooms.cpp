#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> roomQueue;
        vector<bool> visited(rooms.size(),false);
        roomQueue.push(0);
        while(!roomQueue.empty()){
            if(visited[roomQueue.front()] == true)
                roomQueue.pop();
            else{
                vector<int> curr_keys = rooms[roomQueue.front()];
                visited[roomQueue.front()] = true;
                roomQueue.pop();
                for(int key : curr_keys){
                    if(visited[key] == false){
                        roomQueue.push(key);
                    }
                }
            } 
        }
        for(bool b : visited)
            cout<<b<<'\t';
        return (find(visited.begin(),visited.end(),false) == visited.end());
    }
};


int main(){
    vector<vector<int>> rooms = {
        {1,3,2},
        {3,0,1},
        {2},
        {0},
    };

    Solution *sol = new Solution();
    string result = sol->canVisitAllRooms(rooms) ? "TRUE" : "FALSE";
    cout<<result<<endl;
}