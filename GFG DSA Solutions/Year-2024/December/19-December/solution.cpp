// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size(), count = 0, left, right, mid, flag;
        for(int i = 1; i < arr[n-1] + k; i++){
            flag = false, left = 0, right = n-1;
            while(left<=right){
                mid = (left + right) / 2;
                if(arr[mid]==i){
                    flag = true;
                    break;
                }else if(arr[mid]<i){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            if(!flag)
                count++;
            if(count==k)
                return i;
        }
        return arr[n-1] + k;
    }
};