class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        unordered_set<int>st;
        st.insert(0);
        for(int i=1;i<5000;i++)
        {
            bitset<13>bin(i);
            string s = bin.to_string();
                // cout<<s<<endl;
            int j = 0;
            while(j < s.size() && s[j] != '1'){ 
                j++;
            }
            s = s.substr(j,s.size());
            // cout<<s<<endl;
            string t = s;
            reverse(t.begin(),t.end());
            if(t == s) {
                st.insert(i); 
            }
        }
        vector<int>res;
        for(auto a:nums)
        {
            if(st.count(a))
            {
                res.push_back(0);
                continue;
            }
            int p = a + 1;
            int m = a - 1;
            int cnt = 1;
            while(p<= 5000 || m >= 1) 
            {
                if(st.count(m))
                {
                    res.push_back(cnt);
                    break;
                }
                if(st.count(p))
                {
                    res.push_back(cnt);
                    break;
                }
                p+=1;
                m-=1;
                cnt++;
            }
        }
        return res;
    }
};