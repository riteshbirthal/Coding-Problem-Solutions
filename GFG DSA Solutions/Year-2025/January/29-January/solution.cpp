// User function Template for C++
class Solution {
    public:
      double power(double b, int e) {
          // code here
          if(e<0)
              b = double(1)/b;
          e = abs(e);
          if(e==0)
              return 1;
          if(e==1)
              return b;
          double res = power(b, e/2);
          if(e%2){
              res = res*res*b;
          }else{
              res = res*res;
          }
          return res;
      }
  };