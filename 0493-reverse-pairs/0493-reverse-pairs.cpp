class Solution {
private:
    int cnt = 0;
    void merge(int l,int m,int h,vector<int>&nums)
    {
        int j=l;
        for(int i=m+1;i<=h;i++)
        {
            for(j;j<=m;j++)
            {
                if(nums[j] > (long long)2*nums[i])
                {
                    // cout<<"(" << nums[j]<<" , "<<nums[i]<<")"<<endl;
                    cnt+=(m-j+1);
                    break;
                }
            }
        }
        int i = l;
        j = m +1;
        vector<int>temp;
        while(i<=m && j<=h)
        {
            if(nums[i] < nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=h)
        {
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=l;i<=h;i++)
        {
            nums[i] = temp[i-l];
        }
    }
    void ms(int l,int h,vector<int>&nums)
    {   
        if(l==h) return;
        int mid = l + ((h-l)/2);
        ms(l,mid,nums);
        ms(mid+1,h,nums);
        merge(l,mid,h,nums);
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        ms(0,n-1,nums);
        // for(int i=0;i<n;i++) cout<<nums[i]<<" ";
        return cnt;
    }
};