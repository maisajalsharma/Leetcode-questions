class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size();
        int xor_ans = 0;
        bool check_zero = false;

        for(int i = 0; i < n;i++)
        {
            xor_ans = xor_ans ^ nums[i];
            
            if(nums[i] != 0) check_zero = true;
        }

        if(!check_zero) return 0;
        else if(xor_ans == 0) return n-1;
        else return n;

        return -1;
    }
};