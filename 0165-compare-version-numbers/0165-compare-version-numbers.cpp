class Solution {
private:
    void find(string s,vector<int>&arr)
    {
        string st= "";
        for(auto a:s)
        {
            if(a == '.')
            {
                arr.push_back(stoi(st));
                st = "";
            }
            else st+=a;
        }
        arr.push_back(stoi(st));
    }
public:
    int compareVersion(string version1, string version2) {
        // return 0;
        vector<int>arr1,arr2;
        find(version1,arr1);
        find(version2,arr2);
        int n = arr1.size();
        int m = arr2.size();
        for(int i = 0;i<max(n,m);i++)
        {
            int v1 = 0;
            int v2 = 0;
            if(i < n) v1 = arr1[i];
            if(i < m) v2 = arr2[i];
            // cout<<v1<<" "<<v2<<endl;
            if(v1 > v2 ) return 1;
            if(v2 > v1) return -1;
        }
        return 0;
    }
};