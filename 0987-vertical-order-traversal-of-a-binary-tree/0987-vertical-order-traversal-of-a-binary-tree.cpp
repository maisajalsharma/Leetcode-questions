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
    void find(TreeNode* root , int pos , int &l , int &r)
    {
        if(!root) return;
        
        l = min(l,pos);
        r = max(r,pos);
        
        find(root->left , pos-1, l ,r);
        find(root->right , pos+1, l ,r);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        int l = 0;
        int r = 0;
        
        find(root , 0 , l , r);
        
        vector<vector<pair<int,int>>>positive(r+1);
        vector<vector<pair<int,int>>>negative(abs(l)+1);
        
        queue<TreeNode*>q;
        queue<pair<int,int>>index;
        
        q.push(root);
        index.push({0,0});
        
        while(!q.empty())
        {
            TreeNode* TreeNode = q.front();
            q.pop();
            int pos = index.front().first;
            int row = index.front().second;
            index.pop();

            if(pos >= 0)
            { 
                positive[pos].push_back({row ,TreeNode ->val});
                
            }
            else
            {
                negative[abs(pos)].push_back({row ,TreeNode ->val});
                
            }
            
            if(TreeNode ->left)
            {
                q.push(TreeNode ->left);
                index.push({pos-1 , row+1});
            }
            
            if(TreeNode ->right)
            {
                q.push(TreeNode ->right);
                index.push({pos+1 ,row+1});
            }
            
        }
        
        vector<vector<int>>final;
        
        for(int i = negative.size()-1;i > 0;i--)
        {
            sort(negative[i].begin(),negative[i].end());

            vector<int>ans;
            for(int j = 0; j < negative[i].size();j++)
            {
                ans.push_back(negative[i][j].second);
            }
            final.push_back(ans);
        }
        
        for(int i = 0;i < positive.size();i++)
        {
            sort(positive[i].begin(),positive[i].end());

            vector<int>ans;
            for(int j = 0; j < positive[i].size();j++)
            {
                ans.push_back(positive[i][j].second);
            }
            final.push_back(ans);
        }
        
        return final;

    }
};