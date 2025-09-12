class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1;
        int mid = m-1;
        int k = n-1;
        while(k >=0  && mid >=0)
        {
            if(nums2[k] > nums1[mid])
            {
                nums1[i] = nums2[k];
                k--;
                i--;
            }
            else 
            {
                nums1[i]=nums1[mid];
                mid--;
                i--;
            }
        }
        if(mid < 0 && k>=0)
        {

            // cout<<"hi"<<endl;
            for(i;i>=0;i--)
            {
                nums1[i] = nums2[k];
                k--;
            }
        }
    }
};