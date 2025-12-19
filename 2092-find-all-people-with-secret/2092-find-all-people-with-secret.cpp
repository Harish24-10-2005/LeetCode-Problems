// class D{
//     vector<int>size;
//     vector<int>par;
//     D(int n){
//         par.resize(n);
//         size.assign(n,1);
//         for(int i=0;i<n;i++){
//             par[i] = i;
//         }
//         int findpar(int n){
//             if(n == par[n]) return n;
//             return par[n] = findpar(par[n]);
//         }
//         int unionsize(int u,int v){
//             int uu = par[u];
//             int vu = par[v];
//             if(s[uu] < s[vu]){
//                 par[uu] = vu;
//                 s[uv] += s[uu];
//             }
//             else{
//                 par[vu] = uu;
//                 s[uu] += s[vu];
//             }
//         }
//     }
// };
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,unordered_set<int>>mpp;
        // res.assign(n,0);
        vector<int>res;
        unordered_set<int>kn;
        kn.insert(0);
        kn.insert(firstPerson);
        for(auto a:meetings){
            mpp[a[2]].insert(a[0]);
            mpp[a[2]].insert(a[1]);
        }
        for(auto a:mpp){
            // if(a.first < time) continue;
            bool f = false;
            for(auto c:a.second){
                if(f) break;
                if(kn.count(c)){
                    for(auto vec:a.second){
                        kn.insert(vec);
                    }
                    f = true;
                }
            }
        }
        for(int i:kn){
            res.push_back(i);
        }
        return res;
    }
};