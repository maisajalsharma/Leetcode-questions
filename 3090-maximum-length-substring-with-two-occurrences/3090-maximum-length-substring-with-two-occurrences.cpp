class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n = s.size();
        int max_sub = 0;

        vector<int>freq(26,0);
        int j = 0;

        for(int i = 0; i < n;i++)
        {
            freq[s[i] - 'a']++;

            if(freq[s[i] - 'a'] > 2)
            {
                while(j < i && s[j] != s[i])
                {
                    freq[s[j] - 'a']--;
                    j++;
                }
                freq[s[j] - 'a']--;
                j++;

            }

            max_sub = max(max_sub , i - j+1); 
        }

        return max_sub;
    }
};