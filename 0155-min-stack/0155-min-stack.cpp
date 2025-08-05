class MinStack {
public:
    stack<int>st;
    stack<int>minn;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minn.empty())
        {
            minn.push(val);
        }
        else minn.push(min(minn.top(),val));
    }
    
    void pop() {
        if(!st.empty())
        {
            st.pop();
            minn.pop();
        }    
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minn.top();
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