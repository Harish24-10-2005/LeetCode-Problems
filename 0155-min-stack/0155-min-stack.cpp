class MinStack {
public:
    stack<pair<int,int>>st;
    int minn;
    MinStack() {
        minn = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else{
            minn = min(val,st.top().second);
            st.push({val,minn});
        }
    }
    
    void pop() {
        // if(minn = st.top().second;
        if(!st.empty())
        {
            st.pop(); 
        }
        if(st.empty()) minn = INT_MAX;
        
    }
    
    int top() {
        if(!st.empty()) return st.top().first;
        return -1;
    }
    
    int getMin() {
        if(!st.empty())return st.top().second;
        return INT_MAX;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */