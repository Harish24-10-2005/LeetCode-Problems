class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mpp;
        priority_queue<int>pq;
        for(auto a:tasks)
        {
            mpp[a]++;
        }
        for(auto a:mpp)
        {
            pq.push(a.second);
        }
        int ans = 0;
        while(!pq.empty())
        {
            int cyc = n+1;
            vector<int>temp;
            while(cyc && !pq.empty())
            {
                int fre = pq.top();
                pq.pop();
                if(fre > 1)
                {
                    temp.push_back(fre-1);
                }
                ++ans;
                --cyc;
            }
            for(auto a:temp) pq.push(a);
            if(pq.empty()) break;
            ans+=cyc;
        }
        return ans;
    }
};