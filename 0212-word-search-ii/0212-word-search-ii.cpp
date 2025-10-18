class Node{
public:
    Node* links[26];
    bool f = false;
    Node() {
        for(int i=0;i<26;i++) links[i] = nullptr;
    }

    bool iscontain(char a) {
        return links[a-'a'] != nullptr;
    }
    void put(char a,Node* node)
    {
        links[a-'a'] = node;
    }
    Node* get(char a)
    {   
        return links[a-'a'];
    }
    void end()
    {
        f = true;
    }
};

class Trie{
private: Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    Node* getroot()
    {
         return root;
    }
    bool search(string &s)
    {
        Node* node = root;
        for(auto a:s)
        {
            if(!node->iscontain(a))
            {
                return false;
            }
            node = node->get(a);
        }
        return node->f;  
    }
    void insert(string& s)
    {
        Node* node = root;
        for(auto a:s)
        {
            if(!node->iscontain(a))
            {
                node->put(a,new Node());
            }
            node = node->get(a);
        }
        node->end();
    }
};
class Solution {
    int n,m;
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,-1,1};
private:
    void dfs(int i,int j,Node* node, vector<vector<char>>&b,string &path,vector<string>&res)
    {
        char c = b[i][j];
        if(c == '#') return;
        if(!node->iscontain(c)) return;
        path+=c;
        node = node->get(c);
        if(node->f)
        {
            res.push_back(path);
            node->f = false;
        }
        b[i][j] = '#';
        for(int d=0;d<4;d++)
        {
            int nx = dx[d] + i;
            int ny = dy[d] + j;
            if(nx < n && ny <m && nx >=0 && ny >= 0)
            {
                dfs(nx,ny,node,b,path,res);
            }
        }
        b[i][j] = c;
        path.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        n = board.size();
        m = board[0].size();

        for(auto a:words)
        {
            trie.insert(a);
        }
        vector<string>res;
        string path;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dfs(i,j,trie.getroot(),board,path,res);
            }
        }
        return res;
    }
};