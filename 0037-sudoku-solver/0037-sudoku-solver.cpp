class Solution {
private:
    bool isvalid(int r,int c,char ch,vector<vector<char>>&g)
    {   
        for(int i=0;i<9;i++)
        {
            if(g[i][c] == ch) return false;
            if(g[r][i] == ch) return false;
        }
        int sr = r - (r%3);
        int sc = c - (c%3);
        for(int i=sr;i<sr+3;i++)
        {
            for(int j=sc;j<sc+3;j++)
            {
                if(g[i][j] == ch) return false;
            }
        }
        return true;
    }
    bool rec(int idx,vector<vector<char>>&grid)
    {
        if(idx == 81) return true;
        int r = idx/9;
        int c = idx%9;
        if(grid[r][c] != '.') return rec(idx+1,grid);
        for(char ch = '1';ch<='9';ch++)
        {
            if(isvalid(r,c,ch,grid))
            {
                grid[r][c] = ch;
                if(rec(idx+1,grid)) return true;
                grid[r][c] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        rec(0,board);
    }
};