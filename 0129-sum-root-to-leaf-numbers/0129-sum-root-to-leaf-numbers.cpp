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
    void findsum(TreeNode* root , int &total_sum , int sum)
    {
        if(root == NULL) return;
        
        if(!root ->left && !root ->right)
        {
            sum += root ->val;
            total_sum += sum;
            return;
        }

        sum += root ->val;

        findsum(root ->left , total_sum , sum*10);
        findsum(root ->right , total_sum , sum*10);

        sum -= root ->val;
    }
    
    int sumNumbers(TreeNode* root) {

        int total_sum = 0;
        if(root == NULL) return total_sum;
        
        findsum(root , total_sum,0);

        return total_sum;
        
    }
};