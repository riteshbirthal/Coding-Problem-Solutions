class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int mx = 1;
        vector<int> vec;
        unordered_set<int> sum_possible, sqrs, arr2;
        for(int x : arr)
            sqrs.insert(x*x), arr2.insert(x), mx = max(mx, x);
        for(int i = 1; i <= mx; i++){
            for(int j = 1; j <= mx; j++)
                if(arr2.find(i)!=arr2.end() && arr2.find(j)!=arr2.end() && sqrs.find(i*i + j*j)!=sqrs.end())
                    return true;
        }
        return false;
    }
};
