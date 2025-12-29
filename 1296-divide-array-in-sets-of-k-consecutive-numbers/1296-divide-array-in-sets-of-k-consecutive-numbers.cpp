class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        map<int,int>st;
        for(int i:nums){
            st[i]++;
        }
        while(!st.empty()){
            int head = st.begin()->first;
            st[head]--;
            if(st[head] == 0) st.erase(head);
            int cnt = k-1;
            // cout<<head<<endl;
            while(cnt){
                head  = head+1;
                // cout<<head<<endl;
                if(!st.count(head)){
                    return false;
                }
                else{
                    st[head]--;
                    if(st[head] == 0) st.erase(head);
                    // head = head+1;
                }
                cnt--;
            }
        }
        return true;
    }
};