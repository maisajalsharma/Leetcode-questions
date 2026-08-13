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
    void findpath(TreeNode* root , long long &path_count , long long &sum , int &targetSum , unordered_map<long long,int>&m)
    {
        if(root == NULL) return;
        sum += root ->val;
        
        if(m.contains(sum - targetSum))
        {
            path_count += m[sum - targetSum];
        }

        m[sum]++;

        findpath(root ->left , path_count , sum , targetSum , m);
        findpath(root ->right , path_count , sum , targetSum , m);

        m[sum]--;
        sum -= root ->val;
    }
    int pathSum(TreeNode* root, int targetSum) {

        if(root == NULL) return 0;

        unordered_map<long long,int>m;
        m.insert({0 ,1});

        long long path_count = 0;
        long long sum = 0;
        findpath(root , path_count , sum , targetSum , m);
        
        return path_count;
    }
};