class Solution {
private:
int n,m;
int check(int i,int j,string& s){
    while(i >= 0 && j<n && (s[i] == s[j])){
        i--;
        j++;
    }
    int cnt = 0;
    int l = i-1;
    int r = j;
    if(i >= 0){
        while(l >= 0 && r<n && (s[l] == s[r])){
            l--;
            r++;
        }
        cnt = (r-1) - (l+1) + 1;
    }
    else {
        cnt = j - i - 1;
    }

    l = i;
    r = j+1;
    if(j < n){
        while(l >= 0 && r<n && (s[l] == s[r])){
            l--;
            r++;
        }
        cnt = max(cnt ,(r-1) - (l+1) + 1);
    }
    else{
        cnt = max(cnt ,j - i - 1);
    }
    return cnt;
}
public:
    int almostPalindromic(string s) {
        n = s.size();
        int maxx = 0;
        for(int i=0;i<n;i++){
            maxx = max(check(i,i,s),maxx);
            if(i+1 < n) maxx = max(check(i,i+1,s),maxx);
        }
        return maxx;
    }
};