class Solution {
public:
    bool isPalindromic(string s) {

        string result = "";
        for(int i = 0; i < s.size();i++)
        {
            int ascii = 97 + (s[i] - 'a');
            string ans = ""; 

            for(int i = 0; i < 8;i++) ans += '0';

            for(int i = 0 ;i < 8;i++)
            {
                if(ascii % 2 == 1) ans[7-i] = '1';
                ascii /= 2;
            }

            result += ans;
        }

        string ans = result;

        reverse(result.begin(),result.end());

        if(ans == result) return true;

        return false;
    }
};