class Solution {
public:
    int minOperations(string s) {
        string t1 = s;
        string t2 = s;
        sort(s.begin(),s.end());
        if(t1.size() == 2){
            return (t1[0] <= t1[1] ? 0:-1);
        }
        if(t1 == s) return 0;

        int ans1 = 0;
        if(t1.substr(0,t1.size()-1) != s.substr(0,t1.size()-1)){
            sort(t1.begin(),t1.begin()+ t1.size()-1);
            ans1++;
        }
        if(t1.substr(1) != s.substr(1)){
            sort(t1.begin() + 1,t1.end());
            ans1++;
        }
        if(s != t1)ans1++;
        int ans2 = 0;
        if(t2.substr(1) != s.substr(1)){
            sort(t2.begin() + 1,t2.end());
            ans2++;
        }
        if(t2.substr(0,t2.size()-1) != s.substr(0,t2.size()-1)){
             sort(t2.begin(),t2.begin()+ t2.size()-1);
            ans2++;
        }
        if(s != t2)ans2++;
        return min(ans1,ans2);
    }
};