class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int left = 0, right = arr.size()-1, ele;
        while(left<right){
            ele = arr[left];
            arr[left] = arr[right];
            arr[right] = ele;
            left++, right--;
        }
        return ;
    }
};