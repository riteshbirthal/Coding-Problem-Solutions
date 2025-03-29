
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        int ans = 1;
        for(int x : arr){
            if(x==ans){
                ans++;
            }else if(x>ans){
                return ans;
            }
        }
        return ans;
    }
};