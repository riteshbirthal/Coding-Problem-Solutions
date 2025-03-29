
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size(), count = 0, maxProfit = 0;
        vector<int> res = {0, INT_MIN};
        vector<vector<int>> vec;
        for(int i = 0; i < n; i++){
            vec.push_back({deadline[i], profit[i]});
        }
        sort(vec.begin(), vec.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(vec[0][1]);
        count = 1, maxProfit = vec[0][1];
        res = {count, maxProfit};
        for(int i = 1; i < n; i++){
            if(pq.size()<vec[i][0]){
                pq.push(vec[i][1]);
                count += 1;
                maxProfit += vec[i][1];
            }else{
                if(pq.top()<vec[i][1]){
                    maxProfit += vec[i][1] - pq.top();
                    pq.pop();
                    pq.push(vec[i][1]);
                }
            }
            res = {count, maxProfit};
        }
        return res;
    }
};
