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
    int max_val = INT_MIN;
    int maxDepth(TreeNode* root) {

        if(root == NULL) return 0;

        if(!root ->left && !root ->right)
        {
            max_val = max(max_val , count);
        }

        if(root ->left) count++;
        maxDepth(root ->left);

        if(root ->right) count++;
        maxDepth(root ->right);
        count--;


        return max_val;
    }
};