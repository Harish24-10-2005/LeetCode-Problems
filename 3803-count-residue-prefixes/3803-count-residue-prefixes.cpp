class Solution {
public:
    int residuePrefixes(string s) {
        set<int>st;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
            if(((i + 1) % 3)== st.size()){
                ans++;
            }
        }
        return ans;
    }
};