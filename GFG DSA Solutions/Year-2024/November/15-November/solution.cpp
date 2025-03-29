// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        map<int, int> mp;
        for(int x : arr)
            mp[x]++;
        if(mp.size()==1) return -1;
        mp.erase(mp.rbegin()->first);
        return mp.rbegin()->first;
    }
};