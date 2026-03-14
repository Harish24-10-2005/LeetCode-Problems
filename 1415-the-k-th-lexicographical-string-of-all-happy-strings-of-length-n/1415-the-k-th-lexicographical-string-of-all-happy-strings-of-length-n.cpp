class Solution {
private:
    vector<char>ch{'a','b','c'};
    int k;
    string rec(int n,string& s){
        if(n == 0){
            k--;
            // cout<<s<<endl;
            return s;
        }
        if(k == 0) return s;
        string res = "";
        for(char a:ch){
            char temp = s.size() == 0? 'x':s[s.size()-1];
            if(a != temp){
                s+=a;
                res = rec(n-1,s);
                if(k == 0) return res;
                s.pop_back();
            }
        }
        return res;
    }
public:
    string getHappyString(int n, int b){
        k=b;
        string s = "";
        string res = rec(n,s);
        // cout<<k<<endl;
        if(k == 0) return res;
        return "";
    }
};