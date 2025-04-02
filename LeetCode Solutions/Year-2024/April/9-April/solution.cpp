class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<vector<int>> q;
        for(int i = 0; i < tickets.size(); i++){
            if(i==k) q.push({tickets[i], 1});
            else q.push({tickets[i], 0});
        }
        int ans = 0;
        while(true){
            if(q.front()[0]==1 && q.front()[1]){
                ans++;
                break;
            }else if(q.front()[0]==1){
                q.pop();
            }else{
                q.push({q.front()[0]-1, q.front()[1]});
                q.pop();
            }
            ans++;
        }
        return ans;
    }
};