class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                ans.push_back(nums[((nums[i] + i) % n)]);
            }
            else if(nums[i] < 0){
                // cout<<(abs(nums[i]) + n - i) % n<<endl;
                // cout<<(abs(nums[i]) + n - i) <<endl;
                ans.push_back(nums[(n - ((abs(nums[i]) + n - i) % n)) % n]);
            }
            else ans.push_back(nums[i]);
        }
        return ans;
    }
};