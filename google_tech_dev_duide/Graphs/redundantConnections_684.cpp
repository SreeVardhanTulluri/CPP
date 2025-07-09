#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int find(vector<int> array, int index){
        if(array[index] == -1)
            return index;
        return find(array,array[index]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> disjointSetUnionFind(n+1,-1);
        for(vector<int> edge: edges){
            int parent_x = find(disjointSetUnionFind, edge[0]);
            int parent_y = find(disjointSetUnionFind, edge[1]);

            if(parent_x == parent_y)
                return edge;
            disjointSetUnionFind[parent_x] = parent_y;
        }
        return {0,0};
    }
};

int main(){
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};

    vector<int> result = (new Solution)->findRedundantConnection(edges);

    cout << result[0] << " -> " <<result[1]<<endl;
}