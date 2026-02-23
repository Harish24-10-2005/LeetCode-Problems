class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>=s.size()) return false;
        // unordered_map<string,bool>mpp;
        unordered_set<string>st;
        int num = pow(2,k);
        // for(int bit=0;bit<num;bit++){
        //     string b(k,'0');
        //     for(int i=0;i<k;i++){
        //         if((1<<i) & bit){
        //             b[i] = '1';
        //         }
        //     }
        //     // cout<<b<<endl;
        //     mpp[b] = false;
        // }
        // cout<<"............"<<endl;
        for(int i=0;i<=s.size()-k;i++){
            string t = s.substr(i,k);
            st.insert(t);
        }
        if(st.size() != num) return false;
        return true;
    }
};