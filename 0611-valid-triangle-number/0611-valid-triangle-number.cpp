class Solution {
private:
    bool istri(int a,int b,int c)
    {
        return (b + c > a) && (b + a > c) && (a + c > b);
    }
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<n-2;i++)
        {
            // int j=i+1;
            // int k=n-1;
            // while(j<k)
            // {
            //     if(istri(nums[i],nums[j],nums[k]))
            //     {
            //         ans++;
            //         cout<<nums[i]<<","<<nums[j]<<","<<nums[k]<<endl;
            //     }
            //     j++;
            // }
            // j=i+1;
            // k=n-2;
            // while(j<k)
            // {
            //     if(istri(nums[i],nums[j],nums[k]))
            //     {
            //         ans++;
            //         cout<<nums[i]<<","<<nums[j]<<","<<nums[k]<<endl;
            //     }
            //     k--;
            // }
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(istri(nums[i],nums[j],nums[k]))
                    {
                        ans++;
                        cout<<nums[i]<<","<<nums[j]<<","<<nums[k]<<endl;
                    }
                    else break;
                }
            }
            
        }
        return ans;
    }
};