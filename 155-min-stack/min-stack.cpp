class MinStack {
public:
    stack<long long> st;
    long long minval;

    MinStack() {
    }
    
    void push(int value) {
        if(st.empty())
        {
            st.push(value);
            minval = value;
        }
        else if(value >= minval)
        {
            st.push(value);
        }
        else
        {
            st.push(2LL * value - minval);
            minval = value;
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < minval)
        {
            minval = 2LL * minval - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        long long t = st.top();

        return t < minval ? minval : t;
    }
    
    int getMin() {
        return minval;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */