class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = -1, temp;
        queue<int> q;
        for(int i = 0; i < n; i++)
            q.push(i+1);
        while(!q.empty()){
            ans = q.front();
            for(int i = 1; i < k; i++){
                q.push(q.front()), q.pop();
            }
            q.pop();
        }
        return ans;
    }
};