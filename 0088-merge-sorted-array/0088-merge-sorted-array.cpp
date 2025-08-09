class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<nums1.size();i++)
        {
            // cout<<i<<endl;
            nums1[i] = nums2[i-m];
        }
        if(n == 0) return ;
        int l = m;
        for(int i=0;i<m;i++)
        {
            if(nums1[l] < nums1[i])
            {
                swap(nums1[l],nums1[i]);
                l++;
            }
        }
    }
};