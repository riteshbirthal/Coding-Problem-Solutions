class Solution {
    unordered_set<string> st;
    vector<vector<int>> vec;
    int len;
public:
    void solveInvalidPar(string s, int n, int sum, string curr){
        if(sum  < 0 || s.size()-n + curr.size() < len)
            return;
        if(sum==0 && curr.size()==len){
            st.insert(curr);
            return ;
        }
        if(n==s.size()){
            if(sum==0 && curr.size()==len)
                st.insert(curr);
            return ;
        }
        if(s[n]!='(' && s[n]!=')'){
            curr += s[n], solveInvalidPar(s, n+1, sum, curr), curr.pop_back();
            return ;
        }
        solveInvalidPar(s, n+1, sum, curr);
        if(s[n]=='(' && sum<=vec[n][1])
            curr += '(', sum += 1, solveInvalidPar(s, n+1, sum, curr), curr.pop_back();
        if(s[n]==')')
            curr += ')', sum -= 1, solveInvalidPar(s, n+1, sum, curr), curr.pop_back();
        return ;
    }

    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), sum = 0;
        vec = vector<vector<int>>(n+1, vector<int>(2, 0));
        len = 0;
        for(int i = 0; i < n; i++){
            sum += s[i]=='(' ? 1 : (s[i]==')' ? -1 : 0);
            sum<0 ? sum++ : len++;
            vec[n-i-1] = vec[n-i];
            s[n-1-i]=='(' ? vec[n-1-i][0]++ : (s[n-1-i]==')' ? vec[n-1-i][1]++ : vec[n-1-i][0]);
        }
        len -= sum;
        solveInvalidPar(s, 0, 0, "");
        vector<string> res(st.begin(), st.end());
        if(res.size()==0)
            res.push_back("");
        return res;
    }
};
