#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
int n;
bool hascycle;
void topo(unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<bool>&inrec,int u,stack<int>&st)
{
 vis[u]=true;
 inrec[u]=true;
 for(auto &v:adj[u])
 {
    if(inrec[v]==true)
    {
        hascycle=true;
        return;
    }
    if(!vis[v]) 
    {
        topo(adj,vis,inrec,v,st);
    }
 }
 st.push(u);
 inrec[u]=false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        n=numCourses;
        vector<bool>inrec(n,false);
        vector<bool>vis(n,false);
        for(auto &vec:prerequisites)
        {
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
        }
        stack<int>st;
       for(int i=0;i<n;i++)
       {
        if(!vis[i])
        {
            topo(adj,vis,inrec,i,st);
        }
       }
       if(hascycle==true) return {};
       vector<int>res;
       while(!st.empty())
       {
        res.push_back(st.top());
        st.pop();
       }
       return res;

    }
};


int main(){
    // int numCourses = 2;
    // vector<vector<int>> prerequisites = {{1,0}};
    // int numCourses = 1;
    // vector<vector<int>> prerequisites = {};
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    // vector<vector<int>> prerequisites = {{1,0},{0,1}};

    vector<int> result = (new Solution)->findOrder(numCourses,prerequisites);
    for(int res : result)
        cout << res <<'\t' ;
    cout<<endl;
}