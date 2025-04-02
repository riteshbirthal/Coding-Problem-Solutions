class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        for(int i = 0; i < sandwiches.size(); i++) st.push(sandwiches[sandwiches.size()-1-i]);
        for(int i = 0; i < students.size(); i++) q.push(students[i]);
        int flag = 1, init_size, final_size;
        while(!st.empty()){
            init_size = q.size();
            for(int i = 0; i < q.size(); i++){
                if(q.front()==st.top()){
                    q.pop();
                    st.pop();
                }else{
                    q.push(q.front());
                    q.pop();
                }
            }
            if(q.size()==init_size) return q.size();
        }
        return 0;
    }
};