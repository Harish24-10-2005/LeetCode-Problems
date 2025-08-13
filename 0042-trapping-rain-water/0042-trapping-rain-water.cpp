class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>p(height.size());
        p[0] = height[0];
        for(int i=1;i<height.size();i++)
        {
            p[i] = max(p[i-1] , height[i]);
        }
        vector<int>s(height.size());
        s[height.size()-1] = height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--)
        {
            s[i] = max(s[i+1] , height[i]);
        }
        int ans = 0;
        for(int i =0;i<height.size();i++)
        {
            ans+=(min(p[i],s[i]) - height[i]);
        }
        return ans;
    }
};