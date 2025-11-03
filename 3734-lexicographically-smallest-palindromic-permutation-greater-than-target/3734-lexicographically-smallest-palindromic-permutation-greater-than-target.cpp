class Solution {
    string ans = "";
    string mid = "";
    string fullTarget = "";
    vector<int> cnt;
    int n;
private:
    bool rec(int idx, string &temp, const string &targetHalf, bool perfect) {
        if (idx == n) {
            if (!perfect) {
                ans = temp;
                return true;
            }
            string rev = temp;
            reverse(rev.begin(), rev.end());
            string pal = temp + mid + rev;
            if (pal > fullTarget) {
                ans = temp;
                return true;
            }
            return false;
        }

        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) continue;
            char c = 'a' + i;
            if (perfect && c < targetHalf[idx]) continue;

            bool nextPerfect = perfect && (c == targetHalf[idx]);
            temp.push_back(c);
            cnt[i]--;

            if (rec(idx + 1, temp, targetHalf, nextPerfect)) return true;

            cnt[i]++;
            temp.pop_back();
        }
        return false;
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        fullTarget = target;
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        int distinct = 0;
        for (int f : freq) if (f > 0) distinct++;
        if (distinct == 1) return s > target ? s : "";

        int oddCount = 0;
        cnt.assign(26, 0);
        mid = "";
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid = string(1, char('a' + i));
                oddCount++;
            }
            cnt[i] = freq[i] / 2;
        }
        if (oddCount > 1) return "";

        n = s.size() / 2;
        string targetHalf = target.substr(0, n);

        string temp = "";
        if (!rec(0, temp, targetHalf, true)) return "";

        string rev = ans;
        reverse(rev.begin(), rev.end());
        string res = ans + mid + rev;
        return (res > target) ? res : "";
    }
};
