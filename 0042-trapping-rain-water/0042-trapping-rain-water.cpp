class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>suf(n);
        suf[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suf[i] = max(height[i],suf[i+1]);
            cout<<suf[i]<<" ";
        }
        cout<<endl;
        int pre = height[0];
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            pre = max(pre,height[i]);
            ans+=(min(pre,suf[i]) - height[i]);
            cout<<pre<<" ";
        }
        return ans;
    }
};