class Solution {
public:
    int maxProduct(int n) {

        vector<int>ans;

        while( n > 0)
        {
            int r = n % 10;
            ans.push_back(r);
            n = n / 10;
        }

        sort(ans.begin(),ans.end());

        return ans[ans.size()-1] * ans[ans.size()-2];
        
    }
};