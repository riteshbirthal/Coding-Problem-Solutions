// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        vector<int> left, right;
        int product_left = 0, product_right = 0, n = arr.size(), ans;
        for(int i = 0; i < n; i++){
            product_left = product_left ? product_left : 1;
            product_right = product_right ? product_right : 1;
            product_left *= arr[i];
            product_right *= arr[n-1-i];
            left.push_back(product_left);
            right.push_back(product_right);
        }
        reverse(right.begin(), right.end());
        ans = left[0];
        for(int i = 0; i < n-1; i++){
            ans = max(ans, max(left[i], max(right[i+1], left[i]*right[i+1])));
        }
        return ans;
    }
};
