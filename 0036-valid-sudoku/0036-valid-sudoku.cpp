class Solution {
private:
    bool isvalid(int r,int c,char ch,vector<vector<char>>&board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][c] == ch) return false;
            if(board[r][i] == ch) return false;
        }
        int tr = r - (r%3);
        int tc = c - (c%3);
        for(int i=tr;i<tr+3;i++)
        {
            for(int j=tc;j<tc+3;j++)
            {
                if(board[i][j] == ch) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>&board)
    {
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                if(board[r][c] == '.')
                {
                    for(char i='1';i<='9';i++)
                    {
                        if(isvalid(r,c,i,board))
                        {
                            board[r][c] = i;
                            if(solve(board)) return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};