class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<string, int> mpp{
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900},
            {"M",1000}
        };
        int ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(i-1>=0 && mpp.find(s.substr(i-1,2))!=mpp.end())
            {
                // cout<<s.substr(i-1,2)<<endl;
                ans+=mpp[s.substr(i-1,2)];
                i--;
            } 
            else
            {
                // cout<<s.substr(i,1)<<endl;
                ans+=mpp[s.substr(i,1)];
            }
        }
        return ans;

    }
};