class Solution {
private:
    bool issafe(int r,int c,int n, vector<string>&board)
    {
        int dr = r;
        int dc = c;
        while(dr >=0 && dc >=0)
        {
            if(board[dr][dc] == 'Q') return false;
            dr--;
            dc--;
        }
        dr = r;
        dc = c;
        while(dr < n && dc >=0)
        {
            if(board[dr][dc] == 'Q') return false;
            dc--;
            dr++;
        }
        dr = r;
        dc = c;
        while(dc >=0)
        {
            if(board[dr][dc] == 'Q') return false;
            dc--;
        }
        return true;
    }
    void rec(int c,int n,vector<string>&board,vector<vector<string>>&res)
    {
        if(c == n)
        {
            res.push_back(board);
        }
        for(int r = 0;r<n;r++)
        {
            if(issafe(r,c,n,board))
            {
                board[r][c] = 'Q';
                rec(c+1,n,board,res);
                board[r][c] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>board(n,s);
        vector<vector<string>>res;
        rec(0,n,board,res);
        return res;
    }
};