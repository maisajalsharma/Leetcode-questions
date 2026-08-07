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
    int count = 1;
    int min_val = INT_MAX;
    int minDepth(TreeNode* root) {

        if(root == NULL) return 0;

        if(!root ->left && !root ->right)
        {
            min_val = min(min_val , count);
        }

        if(root ->left) count++;
        minDepth(root ->left);

        if(root ->right) count++;
        minDepth(root ->right);
        count--;


        return min_val;
        
    }
};