class Solution {
public:
    bool checkDivisibility(int n) {
        
        int x = n;
        int sum = 0;
        int pro = 1;

        while(x > 0)
        {
            int r = x % 10;
            sum += r;
            pro *= r;
            x /= 10;
        }

        return (sum + pro) != 0 && n % (sum + pro) == 0;
    }
};