class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int summ = accumulate(apple.begin(),apple.end(),0);
        int ans = 0;
        sort(capacity.rbegin(),capacity.rend());
        for(int i:capacity){
            if(summ - i < 0){
                ans++;
                break;
            }
            else{
                summ-=i;
            }
            ans++;
        }
        return ans;
    }
};