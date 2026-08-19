class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int , unordered_set<int>>mp;

        for(auto & rs : reservedSeats)
        {
            int row = rs[0];
            int seat = rs[1];

            mp[row].insert(seat);
        }

        int result = (n - mp.size())*2;

        for(auto& [row , bookedseats] : mp)
        {
            auto isAV = [&](int seat) {
                return bookedseats.find(seat) == bookedseats.end();
            };

            bool g1 = isAV(2) && isAV(3) && isAV(4) && isAV(5);
            bool g2 = isAV(4) && isAV(5) && isAV(6) && isAV(7);
            bool g3 = isAV(6) && isAV(7) && isAV(8) && isAV(9);

            if(g1 && g3) result +=2;
            else if(g1 || g2 || g3 ) result += 1;
        }

        return result;
    }
};