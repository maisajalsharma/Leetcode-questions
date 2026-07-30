class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.size();
        if(n <= 8) return n;

        int a = n/8;
        int b = n%8;

        int ans = 0;
        int i = 1;

        while(i <= a)
        {
            ans += 8*i;
            i++;
        } 

        ans += b*i;

        return ans;


    }
};