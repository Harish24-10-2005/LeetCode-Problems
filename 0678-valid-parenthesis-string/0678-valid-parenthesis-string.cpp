class Solution {
    vector< vector<int> > dp;
    string s;
    int n;

    bool rec(int i, int sl) {
        if (sl < 0) return false;
        if (sl > n - i) return false;

        if (i == n) {
            return sl == 0;
        }
        int &memo = dp[i][sl];
        if (memo != -1) return memo;

        char c = s[i];
        bool ans = false;
        if (c == '(') {
            ans = rec(i+1, sl+1);
        }
        else if (c == ')') {
            ans = rec(i+1, sl-1);
        }
        else {
            ans = rec(i+1, sl+1)  
               || rec(i+1, sl)
               || rec(i+1, sl-1);
        }

        return memo = ans;
    }

public:
    bool checkValidString(string _s) {
        s = _s;
        n = s.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        return rec(0, 0);
    }
};
