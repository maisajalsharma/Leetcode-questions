class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
        int max_sub = 0;
        int j = 0;

        unordered_map<int,int>m;

        for(int i = 0; i < n;i++)
        {
            m[nums[i]]++;

            while(m[nums[i]] > k)
            {
                m[nums[j]]--;
                j++;
            }

            max_sub = max(max_sub , i - j+1); 
        }

        return max_sub;
    }
};