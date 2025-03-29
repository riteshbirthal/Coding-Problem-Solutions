// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++)
            pq.push(arr[i]);
        for(int i = k; i < n; i++){
            pq.push(arr[i]);
            arr[i-k] = pq.top();
            pq.pop();
        }
        for(int i = 0; i < k; i++){
            arr[n-k+i] = pq.top();
            pq.pop();
        }
    }
};