class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int res = 0, left = 0, right = arr.size()-1, mid;
        while(left<right && arr[left]>arr[right]){
            mid = (left + right) / 2;
            if(arr[left]>arr[mid])
                right = mid;
            else
                left = mid+1;
            res = left;
        }
        return res;
    }
};
