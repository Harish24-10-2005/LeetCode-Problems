class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int ori = 0;
        for(int i:nums){
            if(i == k) ori++;
        }
        int maxx = 0;
        for(int num=1;num<=50;num++){
            int temp = 0;
            int curr = 0;
            for(int& i:nums){
                if(num == i) curr++;
                else if(i == k) curr--;
                if(curr < 0) curr = 0;
                temp = max(temp,curr);
            }
            maxx = max(maxx,temp);
        }
        return maxx + ori;
    }
};