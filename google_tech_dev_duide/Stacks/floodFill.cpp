#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

void fill(vector<vector<int>>& image, int sr, int sc, int color,vector<vector<bool>>& visited){
    int directions[5] = {-1,0,1,0,-1};
    if(!visited[sr][sc] && (image[sr][sc] != color)){
        visited[sr][sc] = true;
        for(int i=0 ; i< 4 ; i++){
            int newRow = sr+directions[i];
            int newCol = sc+directions[i+1];
            if(newRow >= 0 && newRow < image.size() && newCol >= 0 && newCol < image[0].size())
                if(image[newRow][newCol] == image[sr][sc])
                    fill(image,newRow,newCol,color,visited);
        }
        image[sr][sc] = color;
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        fill(image,sr,sc,color,visited);
        return image;
    }
};


int main(){
    Solution *sol = new Solution;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> result = sol->floodFill(image,1,1,2);
    for(vector<int> vec : result){
        for(int val : vec)
            cout<<val<<"\t";
        cout<<endl;
    }
}