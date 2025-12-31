class D{
public:
    vector<int>par;
    vector<int>s;
    D(int n){
        s.assign(n,1);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }

    int findPar(int node){
        if(node == par[node]) return node;
        return par[node] = findPar(par[node]);
    }

    void unionByS(int u,int v){
        int up = findPar(u);
        int vp = findPar(v);

        if (up == vp) return;

        if (s[up] < s[vp]) {
            s[vp] += s[up];
            par[up] = vp;
        } else {
            s[up] += s[vp];
            par[vp] = up;
        }
    }

};

class Solution {
private:
    bool valid(int r,int c,int nx,int ny){
        return nx >= 0 && ny >= 0 && nx < r && ny < c;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<int>dx{1,0,-1,0,1,-1,1,-1};
        vector<int>dy{0,1,0,-1,1,-1,-1,1};
        int t = row * col;
        D d(t);
        int i = 0;
        unordered_set<int>water;
        for(i;i<cells.size();i++){
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            int node = (x * col) + y;
            water.insert(node);
            // cout<<i<<" "<<x <<" "<<y<<" "<<node<<endl;
            for(int j=0;j<8;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(!valid(row,col,nx,ny)){
                    continue;
                }
                int nnode = (nx * col) + ny;
                // cout<<node<<" "<<nnode<<endl;
                if(!water.count(nnode)) continue;
                // int up = d.findPar(node);
                // int vp = d.findPar(nnode);
                d.unionByS(node,nnode);
            }
            // cout<<node<<endl;
            unordered_set<int>par;
            for(int r=0;r<row;r++){
                int no = d.findPar(r * col);
                par.insert(no);
            }
            bool f = false;
            // for(int i:par) cout<<i<<" ";
            // cout<<endl;
            for(int r= 0;r<row;r++){
                // cout<<(r*col) + col-1<<endl;
                int no = d.findPar((r*col) + col-1);
                if(par.count(no)){
                    f = true;
                    break;
                }
            }
            if(f) break;
        }

        return i;
    }
};