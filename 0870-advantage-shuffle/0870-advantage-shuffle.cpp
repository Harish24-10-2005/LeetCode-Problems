class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>ans(n,-1);
        sort(nums1.begin(),nums1.end());
        multiset<int>num(nums1.begin(),nums1.end());
        priority_queue<pair<int,int>>pq;
        for(int i =0;i<n;i++)
        {
            auto it = upper_bound(nums1.begin(),nums1.end(),nums2[i]) - nums1.begin();
            if(it <n)
            {
                pq.push({it,i});
            }
        }
        n = n-1;
        while(!pq.empty())
        {
            auto[e,i] = pq.top();
            pq.pop();
            int x=n;
            // cout<<e<<" "<<i<<" "<<n<<" "<<endl;
            if(e<=x){
                ans[i] = nums1[x];
                num.erase(nums1[x]);
                n-=1;
            }
            else ans[i]=-1;
            // for(auto a:ans)
            // {
            //     cout<<a<<" ";
            // }
            // cout<<endl;
        }
        auto it = num.begin();
        if(!num.empty())
        {
            for(int i=0;i<ans.size();i++)
            { 
                // cout<<ans[i]<<" <--"<<endl;
                if(ans[i] == -1)
                {
                    // cout<<"hi "<<" "<<*it<<endl;
                    ans[i] = *it;
                    it++;
                }
            }
        }
    // for(auto i:ans){
        // cout<<i<<" ";
    // }
        return ans;
    }
};