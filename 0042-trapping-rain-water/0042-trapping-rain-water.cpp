class Solution {
public:
    int trap(vector<int>& h) {
        int maxx = 0;
        int ans = 0;
        int i =0;
        int j = 0;
        while(j<h.size())
        {
            if(h[j] >= maxx)
            {
                while(i<j)
                {
                    ans+=(maxx - h[i]);
                    i++;
                }
                maxx = h[j];
            }
            j++;
        }
        i = h.size()-1;
        j = h.size()-1;
        maxx = 0;
        while(j>=0)
        {
            if(h[j] >= maxx)
            {
                while(i>j)
                {
                    ans+=(maxx - h[i]);
                    i--;
                }
                maxx = h[j];
            }
            j--;
        }
        return ans;
    }
};