class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int res = 0, n = arr.size(), left = 0, right = *min_element(arr.begin(), arr.end()) + k, mid, sum, limit;
        vector<int> vec(n+1, 0);
        while(left<=right){
            mid = (left + right) / 2;
            sum = 0, limit = k;
            for(int i = 0; i < n; i++){
                sum += vec[i];
                if(sum + arr[i] < mid){
                    vec[min(i+w, n)] -= mid - (sum + arr[i]);
                    limit -= mid - (sum + arr[i]);
                    sum += mid - (sum + arr[i]);
                }
                vec[i] = 0;
            }
            vec[n] = 0;
            if(limit>=0)
                res = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        return res;
    }
};
