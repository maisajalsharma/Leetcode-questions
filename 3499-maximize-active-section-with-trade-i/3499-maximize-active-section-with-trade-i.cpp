class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int n = s.size();

        int active = count(begin(s) , end(s) , '1');
        vector<int>inactive;

        int i = 0;

        while(i < n)
        {
            if(s[i] == '0')
            {
                int st = i;

                while(i < n && s[i] == '0') i++;

                inactive.push_back(i - st);
            }
            else
            {
                i++;
            }
        }

        int max_pairsum = 0;

        for(int i = 1; i < inactive.size();i++)
        {
            max_pairsum = max(max_pairsum , inactive[i] + inactive[i-1]);
        }

        return max_pairsum + active;
    }
};