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
    vector<vector<int>>ans;
    vector<int>arr;
    int sum = 0;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        if(root == NULL) return ans;

        arr.push_back(root ->val);
        sum += root ->val;

        if(!root ->left && !root ->right && sum == targetSum)
        {
            ans.push_back(arr);
        }

        pathSum(root ->left , targetSum);
        pathSum(root ->right , targetSum);
        sum -= root ->val;
        arr.pop_back();

        return ans;
        
    }
};