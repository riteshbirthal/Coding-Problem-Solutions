class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size(), left = 1, right = *max_element(arr.begin(), arr.end()), mid, res = INT_MAX, hrs;
        while(left<=right){
            mid = (left + right) / 2;
            hrs = k;
            for(int i = 0; i < n; i++){
                hrs -= (arr[i]/mid + ((arr[i]%mid)==0 ? 0 : 1));
            };
            if(hrs<0)
                left = mid + 1;
            else
                res = mid, right = mid - 1;
        }
        return res;
    }
};
