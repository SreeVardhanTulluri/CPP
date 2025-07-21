#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<TreeNode*> reccFunc(int left, int right){
        vector<TreeNode*> result;
        if(1 > left || left > right){
            result.push_back(nullptr);
        }
        else if(left == right){
            result.push_back(new TreeNode(left));
        }
        else{
            for(int curr = left; curr <= right; curr++){
                vector<TreeNode*> left_trees = reccFunc(left, curr-1);
                vector<TreeNode*> right_trees = reccFunc(curr+1, right);

                for(TreeNode* lfSubTree : left_trees)
                    for(TreeNode* rtSubTree : right_trees)
                        result.push_back(new TreeNode(curr, lfSubTree, rtSubTree));
            }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return reccFunc(1, n);
    }
};

int main(){
    vector<TreeNode*> result = (new Solution)->generateTrees(3);
    cout<<result.size()<<endl;
}