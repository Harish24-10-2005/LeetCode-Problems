class Solution {
private:
    int istri(int a,int b,int c)
    {
        return (a + b > c) && (a+c > b) && (c+ b > a);
    }
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int a = nums[i];
                int b = nums[j];
                int c = nums[k];
                if(istri(a,b,c))
                {
                    ans = max(ans,a+b+c);
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};