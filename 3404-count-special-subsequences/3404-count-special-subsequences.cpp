class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                // if(i == j) continue;
                for(int k = j+1;k<n;k++){
                    // if(k == i || k == j ) continue;
                    for(int l = k+1;l<n;l++){
                        // if(l == i ||  l == j || l ==k) continue;
                        if((j - i > 1 && k - j > 1 && l - k > 1) && (nums[i] * nums[k]) == (nums[j] * nums[l]))
                        {
                            // cout<<nums[i]<<" "<<nums[k]<<" "<<nums[j]<<" "<<nums[l]<<endl; 
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};