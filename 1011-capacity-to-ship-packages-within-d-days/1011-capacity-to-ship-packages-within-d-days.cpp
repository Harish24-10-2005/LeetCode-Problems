class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(),weights.end());
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        int ans = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            int day = 0;
            int maxx = 0;
            for(int i:weights)
            {
                if(maxx+i > mid){
                    maxx = i;
                    day+=1;
                }
                else{
                    maxx+=i;
                }
            }
            if(maxx > 0)day+=1;
            cout<<mid<<" "<<day<<endl;
            if(day > days)
            {
                l = mid+1;
            }
            else{
                ans = min(ans,mid);
                r = mid -1;
            }
        }
        return ans;

    }
};