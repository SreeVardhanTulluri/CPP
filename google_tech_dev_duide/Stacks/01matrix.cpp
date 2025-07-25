#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (mat[r][c] == 0) q.emplace(r, c);
                else mat[r][c] = -1; // Marked as not processed yet!

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
        return mat;
    }
};


int main(){
    vector<vector<int>> mat = {
        {1,1,0,0,1,0,0,1,1,0},
        {1,0,0,1,0,1,1,1,1,1},
        {1,1,1,0,0,1,1,1,1,0},
        {0,1,1,1,0,1,1,1,1,1},
        {0,0,1,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,0,1,1,1},
        {0,1,1,1,1,1,1,0,0,1},
        {1,1,1,1,1,0,0,1,1,1},
        {0,1,0,1,1,0,1,1,1,1},
        {1,1,1,0,1,0,1,1,1,1}
    };
    int m = mat.size(),n = mat[0].size();
    Solution *sol = new Solution();
    vector<vector<int>> result = sol->updateMatrix(mat);
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++)
            cout<<result[i][j]<<'\t';
        cout<<endl;
    }

}

                   