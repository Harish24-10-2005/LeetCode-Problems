class Solution {
private:
    vector<int>dx{1,0,0,-1};
    vector<int>dy{0,1,-1,0};
    bool issafe(int x,int y,int n,int m,vector<vector<bool>>&vis)
    {
        if(x>=0 && y>=0 && x<n && y<m && !vis[x][y]) return true;
        return false;
    }
    bool dfs(int i,int j,int idx,string &word,vector<vector<bool>>&vis,vector<vector<char>>&b)
    {
        if(idx == word.size()) return true;
        int n = b.size();
        int m = b[0].size();

        if(!issafe(i,j,n,m,vis) || vis[i][j] || b[i][j] != word[idx]) return false;

        vis[i][j] = true;

        for(int d=0;d<4;d++)
        {
            int nx  = i+dx[d];
            int ny  = j+dy[d];
            if(dfs(nx,ny,idx+1,word,vis,b)) return true;
            
        }
        vis[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(i,j,0,word,vis,board)) return true;
            }
        }
        return false;
    }
};