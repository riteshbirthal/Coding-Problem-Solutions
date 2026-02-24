class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> u;
        for(int x : a)
            u.insert(x);
        for(int x : b)
            u.insert(x);
        return vector<int>(u.begin(), u.end());
    }
};
