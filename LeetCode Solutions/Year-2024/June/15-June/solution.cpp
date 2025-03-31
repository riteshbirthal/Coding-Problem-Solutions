class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), idx = 0;
        vector<vector<int>> vec;
        for(int i = 0; i < n; i++)
            vec.push_back({capital[i], profits[i]});
        sort(vec.begin(), vec.end());
        priority_queue<int> pq;
        vector<int> temp = {INT_MAX, INT_MIN};
        for(int i = 0; i < k; i++){
            for(; idx < n; idx++){
                if(vec[idx][0]<=w)
                    if(temp[1]<vec[idx][1])
                        if(temp[1]!=INT_MIN)
                            pq.push(temp[1]), temp = vec[idx];
                        else
                            temp = vec[idx];
                    else
                        pq.push(vec[idx][1]);
                else
                    break;
            }
            if(temp[0]>w)
                break;
            else
                w += temp[1];
                if(pq.empty())
                    temp = {INT_MAX, INT_MIN};
                else
                    temp = {w, pq.top()}, pq.pop();
        }
        return w;
    }
};