class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay .size();
        int l = 1;
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = INT_MAX;
        while(l<=r)
        {
            int mid = (l + r)/2;
            int b = 0;
            int f = 0;
            for(int i:bloomDay)
            {
                if(i <= mid)
                {
                    f++;
                    if(f == k)
                    {
                        b++;
                        f = 0;
                    }
                }
                else f = 0;
            }
            cout<<mid<<" "<<b<<endl;
            if(b >= m){
                ans = min(ans,mid);
                r = mid -1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans == INT_MAX ? -1 :ans;
    }
};