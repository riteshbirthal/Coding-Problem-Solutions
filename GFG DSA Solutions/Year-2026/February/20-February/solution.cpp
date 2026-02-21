// User function template for C++
class Solution {
  public:
    static bool sort_func(int x, int y){
        return to_string(x) + to_string(y) >= to_string(y) + to_string(x);
    }
    string findLargest(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end(), sort_func);
        string st = "";
        for(int x : arr){
            st += to_string(x);
        }
        reverse(st.begin(), st.end());
        while(st.size() && st[st.size()-1]=='0')
            st.pop_back();
        reverse(st.begin(), st.end());
        return st.size() ? st : "0";
    }
};
