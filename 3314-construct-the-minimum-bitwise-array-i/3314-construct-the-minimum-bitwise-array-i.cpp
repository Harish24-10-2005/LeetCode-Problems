class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec;
        for(int i=0;i<n;i++){
            bool f = false;
            for(int j=0;j<nums[i];j++){
                if((j | (j+1)) == nums[i]){
                    f = true;
                    vec.push_back(j);
                    break;
                }
            }
            if(!f) vec.push_back(-1);

        }
        return vec;
    }
};