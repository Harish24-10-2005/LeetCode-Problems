class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        // int k =0;
        for(int i= 0;i<n;i++)
        {
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            // int m = dp.front();
            while(!dq.empty() && dq.front() <= i-k)
            {
                dq.pop_front();
            }
            dq.push_back(i);
            if(i >=k-1 && !dq.empty() && dq.front() > i-k)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};