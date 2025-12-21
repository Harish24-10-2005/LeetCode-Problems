class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<vector<bool>>row(n);
        vector<bool>col(m,false);
        for(int i=0;i<n;i++) row[i].push_back(false);
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(col[j]) continue;
                bool pre = row[i-1].back();
                if(strs[i][j] < strs[i-1][j] && !pre){
                    for(int r = i-1;r>=0;r--)row[r].pop_back();
                    col[j] = true;
                }
                if(strs[i][j] > strs[i-1][j]) row[i-1].push_back(true);
                else row[i-1].push_back(pre);
            }
        }
        for(auto a:row){
            for(auto b:a){
                cout<<b<<" --";
            }
            cout<<endl;
        }
        int ans = 0;
        for(auto b:col){
            cout<<b<<" ";
            if(b)ans++;
        }
        return ans;
    }
};