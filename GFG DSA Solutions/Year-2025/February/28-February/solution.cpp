
class Solution {
    public:
      int evaluate(vector<string>& arr) {
          // code here
          stack<int> st;
          int a, b;
          for(string s : arr){
              if(s=="+" || s=="-" || s=="*" || s=="/"){
                  a = st.top(), st.pop(), b = st.top(), st.pop();
                  st.push(s=="+" ? (a+b) : (s=="-" ? (b-a) : (s=="*" ? (a*b) : (b/a))));
              }else{
                  st.push(stoi(s));
              }
          }
          return st.top();
      }
  };
  