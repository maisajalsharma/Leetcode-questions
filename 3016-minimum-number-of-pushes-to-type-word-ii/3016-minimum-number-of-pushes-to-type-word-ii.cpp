class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.size();
        
        vector<int>freq(26,0);
        for(int i = 0  ; i< n;i++)
        {
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(),freq.end() , greater<int>());

        int idx = 0;
        int i = 1;
        int ans = 0;

        while(idx < 26)
        {
            if(freq[idx] == 0) break;

            ans += freq[idx] * i;

            if(idx % 8 == 7)
            {
                i++;
            }

            idx++;
        }

        return ans;
        







    }
};