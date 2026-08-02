class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int n = nums.size();

        int odd_count = 0;
        int even_count = 0;
        int sub_arr = 0;

        for(int i = 0 ; i  < n;i++)
            {
                even_count = 0;
                odd_count = 0;
                
                if(nums[i] % 2 == 0) even_count++;
                else odd_count++;

                if(odd_count != 0)
                {
                    if(odd_count > 0 && even_count*b <= odd_count*a)
                    {
                        sub_arr++;
                    }
                }
                
                for(int j = i + 1 ; j < n;j++)
                    {
                        if(nums[j] % 2 == 0) even_count++;
                        else odd_count++;

                        if(odd_count != 0)
                        {
                            if(odd_count > 0 && even_count*b <= odd_count*a)
                            {
                                sub_arr++;
                            }
                        }
                    }
            }

        return sub_arr;
    }
};