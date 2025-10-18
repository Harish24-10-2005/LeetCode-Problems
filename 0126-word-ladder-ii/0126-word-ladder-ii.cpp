class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (wordSet.find(endWord) == wordSet.end()) return res;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> levelVisited;
            for (int i = 0; i < size; ++i) {
                string word = q.front(); q.pop();
                string original = word;
                for (int j = 0; j < word.size(); ++j) {
                    char ori = word[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == ori) continue;
                        word[j] = ch;
                        if (wordSet.find(word) != wordSet.end()) {
                            if (!visited.count(word)) {
                                if (!levelVisited.count(word)) {
                                    q.push(word);
                                    levelVisited.insert(word);
                                }
                                parents[word].push_back(original);
                                if (word == endWord) found = true;
                            }
                        }
                    }
                    word[j] = ori;
                }
            }
            for (const auto& w : levelVisited) visited.insert(w);
        }

        if (!found) return res;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, res);
        return res;
    }

    void dfs(string word, string& beginWord, unordered_map<string, vector<string>>& parents,
             vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }
        for (const string& p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};
