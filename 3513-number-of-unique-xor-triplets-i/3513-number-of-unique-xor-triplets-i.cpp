class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        // nearest 2 ki power

        int n = nums.size();

        if(n == 1 || n == 2) return n;

        int ans = 1;

        while(ans <= n)
        {
            ans *= 2;
        }

        return ans;
    }
};