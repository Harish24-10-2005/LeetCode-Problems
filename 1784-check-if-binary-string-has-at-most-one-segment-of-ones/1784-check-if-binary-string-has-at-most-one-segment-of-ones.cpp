class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int o = 0;
        int i = 0;
        while(i < n){
            if(s[i] == '1'){
                while(i < n && s[i]!='0'){
                    i++;
                }
                o++;
                continue;
            }
            i++;
        }
        cout<<o<<endl;
        return o > 1? false: true;

    }
};