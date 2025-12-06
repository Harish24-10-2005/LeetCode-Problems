class Solution {
private:
    int eat(int m,vector<int>&nums){
        int hr = 0;
        for(auto a:nums){
            hr +=(a/m) + ((a%m != 0)? 1:0);
        }
        return hr;
    }
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int l = 1;
        int r = *max_element(p.begin(),p.end());
        int ans = INT_MAX;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int hr = eat(mid,p);
            // cout<<mid<<" "<<hr<<endl;
            if(hr > h) l = mid + 1;
            else{ 
                ans = min(ans,mid);
                r = mid - 1;
            }
        }
        return ans;
    }
};