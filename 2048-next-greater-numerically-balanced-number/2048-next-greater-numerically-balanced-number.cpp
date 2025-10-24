class Solution {
public:
    bool isBeautiful(int num) {
        string s = to_string(num);
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (auto &p : freq) {
            if ((p.first - '0') != p.second)
                return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        if(n >= 666666) return 1224444;
        for (int i = n + 1; ; i++) {
            if (isBeautiful(i))
                return i;
        }
    }
};
