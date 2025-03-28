class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> u(a.begin(), a.end()), v(b.begin(), b.end());
        vector<int> res;
        for(auto x = v.begin(); x != v.end(); x++){
            if(u.find(*x)!=u.end()){
                res.push_back(*x);
            }
        }
        return res;
    }
};