class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt1 = 0,cnt2 = 0;
        bool f = false;
        for(int i=0;i<n;i++){
            if(f){
                if(s[i] != '1')cnt1++;
            }
            else{
                if(s[i] != '0')cnt1++;
            }
            f = !f;
        }
        f = false;
        for(int i=0;i<n;i++){
            if(f){
                if(s[i] != '0')cnt2++;
            }
            else{
                if(s[i] != '1')cnt2++;
            }
            f = !f;
        }
        cout<<cnt1<<" "<<cnt2<<endl;
        return min(cnt1,cnt2);

    }
};