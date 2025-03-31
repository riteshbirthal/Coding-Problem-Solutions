class CustomStack {
public:
    int limit;
    stack<int> st;
    CustomStack(int maxSize) {
        limit = maxSize;
    }
    
    void push(int x) {
        if(st.size()<limit)
            st.push(x);
    }
    
    int pop() {
        if(!st.size())
            return -1;
        int ans = st.top();
        st.pop();
        return ans;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        for(int i = 0; i < k && !temp.empty(); i++){
            st.push(temp.top() + val);
            temp.pop();
        }
        while(temp.size()){
            st.push(temp.top());
            temp.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */