class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i =1;i<numRows;i++)
        {
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<=i;j++)
            {   
                int t = ans[i-1][j-1];
                if(j <= ans[i-1].size()-1) t+=ans[i-1][j];
                temp.push_back(t);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};