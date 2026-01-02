class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(char a:s){
            if(a == '*' && !st.empty()) st.pop();
            else st.push(a);
        }
        string res ="";
        while(!st.empty()){
            char a = st.top();
            st.pop();
            res.push_back(a);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};