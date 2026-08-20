class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        queue<int>q1;
        queue<int>q2;

        q1.push(nums[0]);
        q2.push(nums[1]);

        for(int i = 2; i < nums.size();i++)
        {
            if(q1.back() > q2.back())
            {
                q1.push(nums[i]);
            }
            else
            {
                q2.push(nums[i]);
            }
        }

        int k = 0;

        while(!q1.empty() || !q2.empty())
        {
            while(!q1.empty())
            {
                nums[k] = q1.front();
                q1.pop();
                k++;
            }

            while(!q2.empty())
            {
                nums[k] = q2.front();
                q2.pop();
                k++;
            }
        }

        return nums;
    }
};