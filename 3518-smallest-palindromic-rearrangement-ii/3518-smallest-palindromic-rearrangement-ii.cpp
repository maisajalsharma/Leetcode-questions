class Solution {
public:

    long long nCr(int n , int r , int k)
    {
        // nCr = nC(n-r)
        r = min(r , n-r);
        long long result = 1;

        for(int i = 1;i <= r;i++)
        {
            result = result * (n-r+i)/i;

            if(result >= k) return k;
        }

        return result;
    }
    string smallestPalindrome(string s, int k) {
        
        int n = s.size();

        char mid = ' ';

        if(n % 2 == 1)
        {
            mid = s[n/2];
        }

        vector<int>count(26,0);

        for(int i = 0; i < n;i++)
        {
            if(n % 2 == 1 && i == n/2) continue; // mid char skip
            count[s[i] - 'a']++;
        }

        //half freq is used to build arr

        for(int i = 0; i < 26;i++)
        {
            count[i] /= 2;
        }

        string halfresult = "";
        int half = n/2;

        for(int i = 0 ; i < half;i++)
        {
            //for fix ith char
            bool placeholder = false;
            for(int j = 0; j < 26;j++) // which char fix
            {
                if(count[j] > 0)
                {
                    count[j] -= 1;

                    //no. of ways

                    long long ways = 1;
                    int letters = 0;

                    for(int c = 0 ; c < 26;c++)
                    {
                        letters += count[c];
                    }

                    for(int c = 0;c < 26;c++)
                    {
                        if(count[c] > 0)
                        {
                            ways *= nCr(letters , count[c] , k);
                            letters -= count[c];
                        }

                        if(ways >= k) break;
                    }

                    // contain kth char

                    if(ways >= k)
                    {
                        halfresult.push_back(j + 'a');
                        placeholder = true;;
                        break;
                    }

                    k -= ways;
                    count[j] += 1;
                }
            }

            if(!placeholder) return "";
        }

        string rev = halfresult;

        reverse(rev.begin() , rev.end());

        if(mid != ' ')
        {
            halfresult.push_back(mid);
        }  

        return halfresult + rev;


    }
};