class Solution {
private:
    vector<int>kmp(string s)
    {
        int n = s.size();
        vector<int>lps(n,0);
        int pre = 0;
        for(int i=1;i<n;i++)
        {
            pre = lps[i-1];
            while(pre > 0 && s[i]!=s[pre])
            {
                pre = lps[pre-1];
            }
            lps[i] = pre + (s[i] == s[pre] ? 1 : 0);
        }
        return lps;
    }
    void findidx(vector<int>&lps,vector<int>&arr,int n)
    {
        for(int i=0;i<lps.size();i++)
        {
            if(lps[i] == n)
            {
                arr.push_back(i-2*n);
                // cout<<(i-2*n)<<endl;
            }
        }
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>lps1;
        vector<int>lps2;

        lps1 = kmp(a+"#"+s);
        lps2 = kmp(b+"#"+s);

        vector<int>arr1;
        vector<int>arr2;

        findidx(lps1,arr1,a.size());
        findidx(lps2,arr2,b.size());

        if(arr2.empty() || arr1.empty()) return {};
        vector<int>res;

        for(auto a:arr1)
        {
            auto it = lower_bound(arr2.begin(),arr2.end(),a);
            if(it == arr2.end()) --it;
            int f = *it;
            int s = *it;
            if(it != arr2.begin()) 
            {
                it--;
                s = *it;
            }
            if(abs(a - f) <= k || abs(a - s) <= k)
            {
                res.push_back(a);
            }
        }
        return res;

    }
};