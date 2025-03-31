class Solution {
public:
    void func(string st, vector<int> &vec, int n){
        if(stoi(st)>n) return ;
        vec.push_back(stoi(st));
        st += '0';
        for(int i = 0; i < 10; i++){
            st[st.size()-1] += i;
            func(st, vec, n);
            st[st.size()-1] -= i;
        }
        st.pop_back();
        return ;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> vec;
        string st = "0";
        for(int i = 1; i < 10; i++){
            st[st.size()-1] += i;
            func(st, vec, n);
            st[st.size()-1] -= i;
        }
        return vec;
    }
};