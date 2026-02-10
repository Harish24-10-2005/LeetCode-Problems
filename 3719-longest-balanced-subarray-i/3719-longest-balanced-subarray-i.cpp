class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>e,o;
            for(int j=i;j<n;j++){
                if(nums[j]%2 == 0)e[nums[j]]++;
                else o[nums[j]]++;
                // cout<<e.size() <<" "<<o.size()<<endl;
                if(e.size() == o.size()){
                    ans = max(ans,j - i + 1);
                }
            }
            cout<<"---------------"<<endl;
        }
        return ans;
    }
};