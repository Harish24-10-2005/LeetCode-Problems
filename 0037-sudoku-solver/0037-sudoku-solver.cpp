class Solution {
private:
    bool isval(int r,int c,int n,char ch,vector<vector<char>>&board)
    {
        int dr = 0;
        while(dr <n)
        {
            if(board[dr][c] == ch) return false;
            dr++;
        }
        int dc = 0;
        while(dc <n)
        {
            if(board[r][dc] == ch) return false;
            dc++;
        }

        int sr = (r/3) * 3;
        int sc = (c/3) * 3;
        for(int i=sr;i<sr+3;i++)
        {
            for(int j = sc;j<sc+3;j++)
            {
                if(board[i][j] == ch) return false;
            }
        }

        return true;

    }
    bool rec(int idx,int n,vector<vector<char>>&board)
    {
        if(idx == n*n) return true;
        int c = idx%n;
        int r = idx/n;

        if(board[r][c] != '.') return rec(idx+1,n,board);
    
        for(int i=1;i<=9;i++)
        {
            char ch = i + '0';
            if(isval(r,c,n,ch,board))
            {
                board[r][c] = ch;
                if(rec(c+1,n,board)) return true;;
                board[r][c] = '.';
            }
        }
        return false;
    
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        rec(0,n,board);
    }
};