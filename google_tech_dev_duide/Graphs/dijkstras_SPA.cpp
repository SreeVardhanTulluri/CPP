#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution{
    public:
        vector<int> dijkstras_spa(int src, int V, vector<vector<int>> edges){
            vector<int> minDisatance(V,INT16_MAX);
            unordered_map<int,vector<pair<int,int>>> adj_Matrix;
            stack<pair<int,int>> nodeStack;
            for(vector<int> edge : edges){
                adj_Matrix[edge[0]].push_back({edge[1],edge[2]});
            }
            nodeStack.push({src,0});
            minDisatance[src] = 0;
            while(!nodeStack.empty()){
                int tos = nodeStack.top().first;
                nodeStack.pop();
                for(pair<int,int> neighbour : adj_Matrix[tos]){
                    if(minDisatance[neighbour.first] > minDisatance[tos] + neighbour.second){
                        minDisatance[neighbour.first] = minDisatance[tos] + neighbour.second;
                        nodeStack.push({neighbour.first, minDisatance[tos]});
                    }
                }
                
            }
            return minDisatance;
        }
};

int main(){

    int src = 0 , V = 5;
    vector<vector<int>> edges = {{0,1,4},{0,2,8},{2,3,2},{3,4,10},{1,4,6}};

    vector<int> distances = (new Solution)->dijkstras_spa(src, V, edges);
    for(int i = 0 ; i < V ; i++)
        cout<< i <<" : "<<distances[i]<<endl;
}