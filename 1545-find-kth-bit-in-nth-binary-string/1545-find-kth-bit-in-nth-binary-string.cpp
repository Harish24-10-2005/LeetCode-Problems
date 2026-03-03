class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=0;i<n-1;i++){
            int temp = s.size();
            s+="1";
            int j = temp-1;
            while(j>=0){
                if(s[j] == '0')s+="1";
                else s+="0";
                j--;
            }
        // cout<<s<<endl;
        }
        return s[k-1];
    }
};