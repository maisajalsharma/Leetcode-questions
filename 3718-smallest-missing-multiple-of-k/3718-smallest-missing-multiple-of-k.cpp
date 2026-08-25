class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_map<long long,long long>m;
        
        for(int i = 0;i < nums.size();i++)
        {
            m[nums[i]] = 1;
        }

        for(int i = 1; i <= nums.size();i++)
        {
            if(!m.contains(i*k)) return i*k;
        }

        return (nums.size()+1)*k;
    }
};