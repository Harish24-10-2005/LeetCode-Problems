struct Node{
    Node* links[2];
    bool iscontain(int need)
    {
        return links[need] != NULL;
    }
    Node* get(int need)
    {
        return links[need];
    }
    void put(int bit,Node* node)
    {
        links[bit] = node;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num >> i) & 1;
            if(!node->iscontain(bit))
            {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getmax(int num)
    {
        int res = 0;
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num >> i) & 1;
            if(node->iscontain(1-bit))
            {
                res |= (1<<i);
                node = node->get(1-bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for(auto a:nums)
        {
            trie.insert(a);
        }
        int ans = 0;
        for(auto a:nums)
        {
            ans = max(ans,trie.getmax(a));
        }
        return ans;
    }
};