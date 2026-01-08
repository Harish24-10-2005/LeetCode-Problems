class Solution {
private:
    int n,m;
    int rec(int i,int j,int si,vector<int>& nums1,vector<int>&nums2){
        if(i == n || j == m){
            if(si == 0) return INT_MIN;
            return 0;
        }
        int take = INT_MIN;
        int temp = rec(i+1,j+1,si+1,nums1,nums2);
        if(temp != INT_MIN) take = nums1[i] * nums2[j] + temp;
        // int take = nums1[i] * nums2[j] + rec(i+1,j+1,si+1,nums1,nums2);
        int nottake = max(rec(i,j+1,si,nums1,nums2) , rec(i+1,j,si,nums1,nums2));
        return max(take,nottake);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        return rec(0,0,0,nums1,nums2);
    }
};