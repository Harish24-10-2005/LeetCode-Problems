class Solution {
private:
    // vector<vector<int>>dp;
    bool eval(string& e,int st, int end)
    {
        if (st > end) return false;
        if(st == end)
        {
            return e[st] == 't';
        }
        // for(int i=st;i<=end;i++)
        // {
        //     cout<<e[i];
        // }
        // cout<<endl;
        // cout<<st<<" "<<end;
        char ch = e[st];
        bool res = ch == '&' ? true: false;
        int d = 0;
        int l = st + 2;
        if(ch == '!')
        {
            return !eval(e,l,end-1);
        }
        for(int i=st+2;i<end;i++)
        {
            if(e[i] == '(') d++;
            if(e[i] == ')') d--;
            if(e[i] == ',' && d == 0)
            {
                bool val = eval(e,l,i-1);
                if(ch == '&')
                {
                    if(val == false) return false;
                    res = res && val;
                }
                else
                {
                    if( val == true) return true;
                    res = res || val;
                }
                l = i+1;
            }
        }
        bool val = eval(e,l,end-1);
        if(ch == '&') res = res && val;
        else res = res || val;
        return res;
    }
public:
    bool parseBoolExpr(string e) {
    //    dp.assign(e.size(),vector<int>(e.size(),-1));
       return eval(e,0,e.size()-1);
    }
};