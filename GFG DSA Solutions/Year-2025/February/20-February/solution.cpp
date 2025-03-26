class Solution {
    public:
      vector<double> getMedian(vector<int> &arr) {
          // code here
          vector<double> res;
          priority_queue<double> left;
          priority_queue<double, vector<double>, greater<double>> right;
          double median, left_top, right_top;
          for(int x : arr){
              if(left.size()<right.size()){
                  left.push(x);
              }else{
                  right.push(x);
              }
              while(left.size() && right.size() && left.top()>right.top()){
                  left_top = left.top(), left.pop();
                  right_top = right.top(), right.pop();
                  left.push(right_top);
                  right.push(left_top);
              }
              if((left.size()+right.size())%2){
                  median = left.size()>right.size() ? left.top() : right.top();
              }else{
                  median = (left.top() + right.top()) / 2;
              }
              res.push_back(median);
          }
          return res;
      }
  };
  