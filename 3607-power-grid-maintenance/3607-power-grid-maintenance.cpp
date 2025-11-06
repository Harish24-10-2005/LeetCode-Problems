class Solution {
public:
    
    vector<int> par;
    
    int find(int x) {
        if (x != par[x])
            par[x] = find(par[x]);
        
        return par[x];
    }
    
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x != y) par[y] = x;
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        par.resize(c + 1);
        
        for (int i = 1; i <= c; i++) par[i] = i;

        for (auto& c : connections) {
            unite(c[0], c[1]);
        }

        unordered_map<int, set<int>> onN;
        
        for (int i = 1; i <= c; i++) {
            int comp = find(i);
            onN[comp].insert(i);
        }

        vector<int> res;

        for (auto& q : queries) {
            int ty = q[0];
            int x = q[1];
            int comp = find(x);

            if (ty == 1) {
                if (onN[comp].count(x)) {
                    res.push_back(x);
                } else if (!onN[comp].empty()) {
                    res.push_back(*onN[comp].begin());
                } else {
                    res.push_back(-1);
                }
            } else {
                onN[comp].erase(x);
            }
        }

        return res;
    }
};
