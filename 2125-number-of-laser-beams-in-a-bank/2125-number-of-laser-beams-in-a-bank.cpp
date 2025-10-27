class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int last = 0;
        int ans = 0;
        vector<int>temp;
        for(auto a:bank)
        {
            int cnt = 0;
            for(auto ch:a)
            {
                if(ch =='1') cnt++;
            }
            temp.push_back(cnt);
        }
        for(auto a:temp)
        {
            if(a > 0)
            {
                ans += last*a;
                last = a;
            }
        }
        return ans;
    }
};