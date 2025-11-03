class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        stack<pair<int,int>>st;
        st.push({colors[0],neededTime[0]});
        for(int i=1;i<n;i++)
        {
            int t = st.top().first;
            int c = st.top().second;
            if(t == colors[i])
            {
                if(c < neededTime[i])
                {
                    ans+=c;
                    st.pop();
                    st.push({colors[i],neededTime[i]});
                }
                else
                {
                    ans+=neededTime[i];
                }
            }
            else
            {
                st.push({colors[i],neededTime[i]});
            }
        }
        return ans;
    }
};