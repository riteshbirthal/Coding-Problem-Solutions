class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        vector<int> res{0, 0};
        int left, right, mid, m = arr2.size(), min_diff = INT_MAX;
        for(int a : arr1){
            left = 0, right = m-1;
            while(left<=right){
                mid = (left + right) / 2;
                if(a + arr2[mid] == x){
                    res[0] = a, res[1] = arr2[mid];
                    return res;
                }else if(a + arr2[mid] > x){
                    if(min_diff > a + arr2[mid] - x)
                        res[0] = a, res[1] = arr2[mid], min_diff = a + arr2[mid] - x;
                    right = mid - 1;
                }else{
                    if(min_diff > x - a - arr2[mid])
                        res[0] = a, res[1] = arr2[mid], min_diff = x - a - arr2[mid];
                    left = mid + 1;
                }
            }
        }
        return res;
    }
};
