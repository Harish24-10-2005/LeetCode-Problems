class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // map<string, string> mpp;
        // for (auto a : words) {
        //     string temp = a;
        //     sort(temp.begin(), temp.end());
        //     if (mpp.find(temp) == mpp.end()) {
        //         mpp[temp] = a;
        //     }
        // }
        int n = words.size();
        string pre = words[0];
        string a = pre;
        sort(pre.begin(),pre.end());
        vector<string> res;
        for(int i=1;i<n;i++)
        {
            string b = words[i];
            sort(b.begin(),b.end());

            if(pre != b)
            {
                res.push_back(a);
                a = words[i];
                pre = b;
            }
        }
        res.push_back(a);
        // for (auto a : mpp) {
        //     res.push_back(a.second);
        // }
        return res;
    }
};