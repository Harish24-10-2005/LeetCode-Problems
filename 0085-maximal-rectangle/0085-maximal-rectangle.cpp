class Solution {
private:
    int n,m;
    vector<int>h;
    int findMax(){
        vector<int>pre(m,-1),suf(m,m);
        stack<int>st;
        for(int i= 0;i<m;i++){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }
            if(!st.empty()) pre[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i= m-1;i>=0;i--){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }
            if(!st.empty()) suf[i] = st.top();
            st.push(i);
        }
        // for(int i:suf){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int rec = 0;
        for(int i=0;i<m;i++){
            int lft = i - pre[i] - 1;
            int ryt = suf[i] - i;
            // cout<<"{"<<h[i]<<" "<<lft<<" "<<ryt<<"}";
            rec = max(rec,h[i] * (lft + ryt));
        }
        cout<<endl;
        return rec;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int ans = 0;
        h.assign(m,0);
        for(int i=0;i<n;i++){
            // for(int i:h) cout<<i<<" ";
            // cout<<endl;
            for(int j =0;j<m;j++){
                if(matrix[i][j] == '1') h[j]+=1;
                else h[j] = 0;
            }
            int height = findMax();
            ans = max(ans,height);
        }
        return ans;
    }
};