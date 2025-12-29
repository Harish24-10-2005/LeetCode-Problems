class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        multiset<int>st;
        for(int i:hand){
            st.insert(i);
        }
        while(!st.empty()){
            int head = *st.begin();
            st.erase(st.begin());
            int cnt = groupSize-1;
            cout<<head<<endl;
            while(cnt){
                head  = head+1;
                // cout<<head<<endl;
                if(!st.count(head)){
                    return false;
                }
                else{
                    st.erase(st.find(head));
                    // head = head+1;
                }
                cnt--;
            }
        }
        return true;
    }
};