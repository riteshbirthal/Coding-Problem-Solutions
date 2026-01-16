class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<int> stk;
        int count = 2;
        for(char &c : s){
            if(c!='(' && c!=')')
                count++;
            else if(c=='(')
                stk.push(count), count = 0;
            else
                if(count<=1)
                    return true;
                else
                    count = stk.top()+1, stk.pop();
        }
        return false;
    }
};
