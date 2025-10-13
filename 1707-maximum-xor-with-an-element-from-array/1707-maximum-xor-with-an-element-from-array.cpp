struct Node{
    Node* links[2];
    bool iscontain(int bit)
    {
        return links[bit] != NULL;
    }   
    void put(int bit,Node* node)
    {
        links[bit] = node;
    }
    Node* get(int bit)
    {
        return links[bit];
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
            int bit = (num>>i) & 1; 
            if(!node->iscontain(bit))
            {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num)
    {
        int res = 0;
        Node* node = root;
        if(!node->links[0] && !node->links[1]) return -1;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            if(node->iscontain(1-bit))
            {
                res|= (1<<i);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int>res(n,-1);
        sort(nums.begin(),nums.end());
        vector<vector<int>>temp(n);
        
        Trie trie;
        for(int i=0;i<n;i++)
        {
            int m = queries[i][1];
            int x = queries[i][0];
            temp[i] = {m,x,i};
        }
        sort(temp.begin(),temp.end());
        int j = 0;
        for(auto a : temp)
        {
            int m = a[0];
            int x = a[1];
            int i = a[2];
            while(j<nums.size() && m >= nums[j])
            {
                trie.insert(nums[j]);
                j++;
            }
            if(j!=0) res[i] = trie.getMax(x);
            else res[i] = -1;
        }
        return res;
    }
};