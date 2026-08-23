class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }
        else{
            int presMin = st.top().second;
            int finalMin = min(presMin, val);
            st.push({val, finalMin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
