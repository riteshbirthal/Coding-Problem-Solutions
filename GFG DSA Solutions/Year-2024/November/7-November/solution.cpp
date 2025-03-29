// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int sum = 0, idx = -1, currSum = 0, n = arr.size();
        for(auto x : arr){
            sum += x;
        }
        if(sum%3) return {-1, -1};
        sum /= 3;
        for(int i = 0; i < n; i++){
            currSum += arr[i];
            if(idx!=-1 && currSum==2*sum)
                return {idx, i};
            else if(currSum==sum)
                idx = i;
        }
        return {-1, -1};
    }
};