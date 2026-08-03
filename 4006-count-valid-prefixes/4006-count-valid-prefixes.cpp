class Solution {
public:
    int countValidPrefixes(string s) {
        
        int zero_count = 0;
        int one_count  =  0;
        int prefix = 0;

        for(int i = 0 ; i < s.size();i++)
        {
            if(s[i] == '0') zero_count++;
            else one_count++;

            if(zero_count == one_count) prefix++;
            else if(zero_count + 1 == one_count) prefix++;
            else if(zero_count == one_count + 1) prefix++;
        }

        return prefix;

        


    }
};