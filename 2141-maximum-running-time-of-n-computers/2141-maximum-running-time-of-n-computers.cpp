class Solution {
private:
    bool can(int n,long long m,vector<int>&b)
    {
        long long t = 0;
        for(auto a:b)
        {
            t += min((long long)a,m);
        }
        return t >= (long long )n*m;
    }
public:
    long long maxRunTime(int n, vector<int>& b) {
        // sort(b.begin(),b.end());
        long long summ = accumulate(b.begin(),b.end(),0LL);
        long long ans = 0;
        long long l = *min_element(b.begin(),b.end());
        long long r = summ/n;
        while(l<=r)
        {
            long long m = (long long)l + (r - l)/2;
            if(can(n,m,b))
            {
                ans = m;
                l = m + 1;
            }
            else{
                r = m-1;
            }
        }
        return ans;
    }
};