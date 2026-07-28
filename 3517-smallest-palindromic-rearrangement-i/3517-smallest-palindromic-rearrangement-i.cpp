class Solution {
public:
    string smallestPalindrome(string s) {

        if(s.size() <= 1) return s;
        
        vector<int>ans(26,0);

        for(int i = 0;i < s.size();i++)
        {
            ans[s[i] - 'a']++;
        }

        string result = "";
        string result2 = "";
        int idx = -1;

        for(int i = 0; i < 26;i++)
        {
            int freq = ans[i] / 2;

            while(freq)
            {
                result += char(i + 97);
                result2 += char(i + 97);
                freq--;
            }  

            if(ans[i] % 2 != 0) idx = i;
        }

        if(idx != -1) result += char(idx + 97);
        
        reverse(result2.begin(),result2.end());

        return result + result2;
    }
};