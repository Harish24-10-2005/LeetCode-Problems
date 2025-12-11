class Solution {
private:    
    int n;
    vector<int>arr1,arr2;
    void rec(int l,int r,int summ,vector<int>&nums,bool f){
        if(l == r){
            if(f)arr1.push_back(summ);
            else arr2.push_back(summ);
            return;
        }
        rec(l+1,r,summ,nums,f);
        rec(l+1,r,summ+nums[l],nums,f);
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        n = nums.size();
        int h = n/2;
        rec(0,h,0,nums,true);
        // cout<<h<<" "<<n<<endl;
        rec(h,n,0,nums,false);
        sort(arr1.begin(),arr1.end());
        int ans = INT_MAX;
        // for(auto a:arr1) cout<<a<<" ";
        // cout<<endl;

        // for(auto a:arr2) cout<<a<<" ";

        for(int i=0;i<arr2.size();i++){
            int tar = goal - arr2[i];
            int idx = lower_bound(arr1.begin(),arr1.end(),tar) - arr1.begin();
            int need = INT_MAX;

            if(idx < arr1.size()){
                need = arr1[idx];
                ans = min(ans,abs(goal - (arr2[i] + need)));
            }

            if(idx -1 >=0){
                need = arr1[idx-1];
                ans = min(ans,abs(goal - (arr2[i] + need)));
            }
            // cout<<arr2[i] <<" "<<need<<endl;
        }
        return ans;
    }
};