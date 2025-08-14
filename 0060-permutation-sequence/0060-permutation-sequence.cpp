class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char>nums;
        int f = 1;
        for(int i=1;i<n;i++)
        {
            f*=i;
            nums.push_back(i + '0');
        }
        nums.push_back(n + '0');
        k-=1;
        string s = "";
        while(true)
        {
            s+=(nums[k/f]);
            nums.erase(nums.begin()+(k/f));
            if(nums.size() == 0) break;
            k = k % nums.size();
            f = f / nums.size();
        }
        return s;
    }
};