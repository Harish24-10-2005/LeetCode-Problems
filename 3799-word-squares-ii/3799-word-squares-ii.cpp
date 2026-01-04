class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        sort(words.begin(),words.end());
        vector<vector<string>>res;
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j)continue;
                if(words[i][0] != words[j][0]) continue;

                for(int k=0;k<n;k++){
                    if(i == j || j == k) continue;
                    if(words[i][3] != words[k][0]) continue;

                    for(int l=0;l<n;l++){
                        if(i == k||j == k|| k==l) continue;
                        if(words[l][0] != words[j][3] || words[l][3] != words[k][3]) continue;
                        res.push_back({words[i],words[j],words[k],words[l]});
                    }
                }
            }
        }
        return res;
    }
};