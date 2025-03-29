// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        unordered_set<int> u;
        int n = arr.size();
        for(int i = 0; i < k; i++){
            if(u.find(arr[i])!=u.end()) return true;
            u.insert(arr[i]);
        }
        for(int i = k; i < n; i++){
            if(u.find(arr[i])!=u.end()) return true;
            u.insert(arr[i]);
            u.erase(arr[i-k]);
        }
        return false;
    }
};