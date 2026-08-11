/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void view(TreeNode* root , int level , vector<int>& arr)
    {
        if(root == NULL) return;
        
        if(level == arr.size()) // if level = 2 then already arr has level 1 0r level 0 elements
        {
            arr.push_back(root ->val);
        }
        
        view(root ->right , level+1 , arr);
        view(root ->left , level +1 , arr);
        
    }
    vector<int> rightSideView(TreeNode* root) {

        vector<int>ans;
        if(root == NULL) return ans;
        
        view(root , 0 , ans);
        return ans;
        
    }
};