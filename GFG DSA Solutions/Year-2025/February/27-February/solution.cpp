
class Solution {
    stack<pair<int, int>> st;
  public:
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(st.empty()){
            st.push({x, x});
            return ;
        }
        st.push({x, min(x, st.top().second)});
        return ;
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty()) return ;
        st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        return st.empty() ? -1 : st.top().first;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        return st.empty() ? -1 : st.top().second;
    }
};
