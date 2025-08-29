/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        int val = node->val;
        Node* head = new Node(val);
        unordered_map<Node*,Node*>mpp;

        mpp[node] = head;
        queue<Node*>q;
        
        q.push(node);

        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            Node* cur = mpp[a];
            for(auto vec:a->neighbors)
            {
                if(mpp.find(vec) == mpp.end())
                {
                    Node* newNode = new Node(vec->val);
                    mpp[vec] = newNode;
                    cur->neighbors.push_back(newNode);
                    q.push(vec);
                }
                else cur->neighbors.push_back(mpp[vec]);
            }
        }
        return head;
    }
};