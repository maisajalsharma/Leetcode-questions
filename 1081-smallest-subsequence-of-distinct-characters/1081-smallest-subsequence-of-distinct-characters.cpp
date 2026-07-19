class Solution {
public:
    string smallestSubsequence(string s) {
        
        int n = s.size();
        stack<char>st;
        unordered_map<int,int>m;
        vector<int>st_freq(26,0);

        for(int i = 0; i < s.size();i++)
        {
            m[s[i]]++;
        }

        for(int i = 0; i < n;i++)
        {
            m[s[i]]--;

            if(st_freq[s[i] - 'a']) continue;

            while(!st.empty() && st.top() > s[i] && m[st.top()] > 0)
            {
                if(m[st.top()] > 0)
                {
                    st_freq[st.top() - 'a'] = 0;
                    st.pop();   
                }
            }

            st.push(s[i]);
            st_freq[s[i] - 'a'] = 1;
        }

        string result = "";

        while(!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }

        return result;

    }
};