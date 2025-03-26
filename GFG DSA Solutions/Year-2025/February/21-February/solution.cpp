
class Solution {
    public:
      bool isBalanced(string& s) {
          // code here
          stack<char> st;
          for(char &ch : s){
              if(ch=='(' || ch=='{' || ch=='[')
                  st.push(ch);
              else if(st.size()==0)
                  return false;
              else if(ch==')')
                  if(st.top()=='(')
                      st.pop();
                  else
                      return false;
              else if(ch=='}')
                  if(st.top()=='{')
                      st.pop();
                  else
                      return false;
              else if(ch==']')
                  if(st.top()=='[')
                      st.pop();
                  else
                      return false;
          }
          return st.size()==0;
      }
  };