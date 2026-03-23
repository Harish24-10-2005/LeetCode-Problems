class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        map<int,string>mpp;
        int i = 0;
        while(i < n){
            int j = i;
            for(j;j<i + numRows;j++){
                if(j < n) mpp[j-i]+=s[j];
            }
            i = j;
            int idx = i + numRows-2;
            while(idx > i){
                if(j < n)mpp[idx - i] += s[j];
                // cout<<j<<endl;
                idx--;
                j++;
            }
            i = j;
        }
        string res = "";
        for(auto a:mpp){
            res+=a.second;
        }
        return res;
    }
};