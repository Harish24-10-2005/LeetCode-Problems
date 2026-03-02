class Solution {
public:
    int minSwaps(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=n-1;j>=0;j--){
                if(mat[i][j] == 1) break;
                else cnt++;
            }
            temp.push_back(cnt);
        }
        for(int i:temp){
            cout<<i<<" ";
        }
        cout<<endl;
        int ans = 0;
        int cnt = n-1;
        for(int i =0;i<n;i++){
            if(temp[i] >= cnt){
                cnt--;
                continue;
            }
            int idx = i+1;
            int j=i+1;
            for(j;j<n;j++){
                if(temp[j] >=cnt){
                    idx = j;
                    break;
                }
            }
            cout<<j<<endl;
            if(j == n) return -1;
            while(idx - 1 >= i){
                swap(temp[idx-1],temp[idx]);
                ans++;
                idx--;
            }
            cnt--;
        }
        // for(int i:temp){
        //     cout<<i<<" ";
        // }
        return ans;
    }
};