class Solution {
vector<int>seg;
vector<bool>changed;

void build(int idx,int st,int end,string& s){
    if(st == end){
        seg[idx] = 0;
        return;
    }
    int mid = (st + end)/2;
    build(2*idx + 1,st,mid,s);
    build(2*idx + 2,mid + 1,end,s);
    seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    if(s[mid] == s[mid+1]) seg[idx]++;
}
void update(int idx,int st,int end,int i,string& s){
    int mid = (st + end)/2;
    if(st == end){
        if(s[i] =='A') s[i] = 'B';
        else s[i] = 'A'; 
        changed[i] = true;
        return;
    }
    if(i <= mid){
        update(2*idx + 1,st,mid,i,s);
    }
    else update(2*idx + 2,mid + 1,end,i,s);
    seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    if(s[mid] == s[mid+1]) seg[idx]++;
    // else if(changed[mid]){
    //     cout<<mid<<endl;
    //     seg[idx]--;
    //     changed[mid] = false;
    // }
    // else if(changed[mid + 1]){
    //     cout<<mid+1<<endl;
    //     seg[idx]--;
    //     changed[mid + 1] = false;
    // }
}
int query(int idx,int st,int end,int qs,int qe,string& s){
    if(end < qs || st > qe) return 0;
    if(st >= qs && end <= qe) return seg[idx];
    int mid = (st + end)/2;
    int lft = query(2*idx + 1,st,mid,qs,qe,s);
    int ryt = query(2*idx + 2,mid + 1,end,qs,qe,s);
    int ans = lft + ryt;
    if(mid >= qs && mid + 1<= qe){
        if(s[mid] == s[mid+1]) ans++;
    }
    return ans;
}
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        seg.assign(4*n + 1,0);
        changed.assign(n,false);
        build(0,0,n-1,s);
        vector<int>res;
        for(auto a:queries){
            int t,b,c;
            t = a[0];
            if(t == 1){
                b = a[1];
                update(0,0,n-1,b,s);
            }
            else{
                b = a[1];
                c = a[2];
                int ans = query(0,0,n-1,b,c,s);
                res.push_back(ans);
            }
        }
        // for(auto a:seg)cout<<a<<" ";
        // cout<<s<<endl;
        return res;
    }
};