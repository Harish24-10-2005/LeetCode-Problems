class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        int m = nums2.size();
        if(m < n) return findMedianSortedArrays(nums2,nums1);

        int k = (n+m+1)/2;
        int l = max(0,n-k);
        int r = min(k,n);
        while(l<=r)
        {
            int m1 = l+(r-l)/2;
            int m2 = k - m1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if(m1-1>= 0) l1 = nums1[m1-1];
            if(m2-1>= 0) l2 = nums2[m2-1];

            if(m1<n) r1 = nums1[m1];
            if(m2<m) r2 = nums2[m2];

            if(l1 <= r2 && l2 <= r1)
            {
                if((n+m) % 2 == 0)
                {
                    return (double)(max(l1,l2)+min(r1,r2))/2;
                }
                return (double)max(l1,l2);
            } 
            if(l1 > r2)
            {
                r = m1-1;
            }
            else
            {
                l = m1+1;
            }
        }
        return -1;
    }
};