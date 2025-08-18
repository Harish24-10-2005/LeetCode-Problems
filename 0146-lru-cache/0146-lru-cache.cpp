class Node{
public:
    int val;
    int key;
    Node* next;
    Node* pre;
    Node(int k,int v){
        key = k;
        val = v;
        pre = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>mpp;
    int c = 0;
    int cnt = 0;
    Node* st = nullptr;
    Node* end = nullptr;
    LRUCache(int capacity) {
        c = capacity;
        cnt = 0;
        st = nullptr;
        end = nullptr;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end())
        {
            Node* temp = mpp[key];
            int v = temp->val;
            remove(temp);
            insert(temp);
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end())
        {
            Node* temp = mpp[key];
            temp->val = value;
            remove(temp);
            insert(temp);
        }
        else
        {
            Node* a = new Node(key,value);
            if(cnt == c)
            {
                Node* old = st;           
                if (old) {
                    mpp.erase(old->key);  
                    remove(old);          
                    delete old;           
                }
            }
            mpp[key] = a;
            insert(a);
        }
    }
    void insert(Node* root)
    {
        if(end == nullptr)
        {
            st = root;
            end = root;
        }
        else
        {
            end->next = root;
            root->pre = end;
            end = root;
        }
        cnt++;
    }
    void remove(Node* root)
    {
        if(root->pre)
        {
            root->pre->next = root->next;
        } 
        else
        {
            st = root->next;
            // if(st) st->pre = nullptr;
        }
        if(root->next)
        {
            root->next->pre = root->pre;
        }
        else 
        {
            end = root->pre;
            // if(end)end->next = nullptr;
        }
        root->pre = nullptr;
        root->next = nullptr;
        cnt--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */