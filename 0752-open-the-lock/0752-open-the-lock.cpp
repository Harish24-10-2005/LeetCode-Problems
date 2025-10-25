class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string>st(deadends.begin(),deadends.end()),vis;
        if(st.find("0000") != st.end()) return -1;
        queue<pair<string,int>>q;
        int cnt= 0;
        q.push({"0000",0});
        vis.insert("0000");
        while(!q.empty())
        {
            string s = q.front().first;
            int cnt = q.front().second; 
            q.pop();

            if(s == target) return cnt;
            for(auto &a:s)
            {
                char ori = a;
                a = (a == '9' ? '0' : a + 1);
                if(st.find(s) == st.end() && vis.find(s) == vis.end())
                {
                    q.push({s,cnt+1});
                    vis.insert(s);
                }
                a = ori;
                a = (a == '0' ? '9' : a - 1);
                if(st.find(s) == st.end() && vis.find(s) == vis.end())
                {
                    q.push({s,cnt+1});
                    vis.insert(s);
                }
                a = ori;
            }
        }
        return -1;
    }
};