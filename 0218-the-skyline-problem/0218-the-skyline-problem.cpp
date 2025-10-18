class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>res;
        multiset<int>active;
        vector<pair<int,int>>e;
        for(auto a:buildings)
        {
           e.push_back({a[0],a[2]});
           e.push_back({a[1],-a[2]});
        }
        sort(e.begin(),e.end(),[](auto &a,auto &b)
        {
            if(a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        int pre = 0;
        active.insert(0);
        for(auto a:e)
        {
            int x = a.first;
            int h = a.second;
            if(h > 0)
            {
                active.insert(h);
            }
            else
            {
                active.erase(active.find(-h));
            }
            int cur = *active.rbegin();
            if(cur != pre)
            {
                res.push_back({x,cur});
                pre = cur;
            }
        }
        return res;
    }
};