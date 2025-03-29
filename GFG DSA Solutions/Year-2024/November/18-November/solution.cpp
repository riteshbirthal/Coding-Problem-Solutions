class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        vector<int> vec(n);
        for(int i = 0; i < n; i++){
            vec[i] = arr[(i+d)%n];
        }
        arr = vec;
        return ;
    }
};