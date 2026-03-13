class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long res = 0;
        priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
        for(int x : workerTimes)
            pq.push({x, {1, x}});
        pair<long long, pair<long long, long long>> pr, newPair;
        long long t, wkt;
        while(mountainHeight){
            pr = pq.top(), pq.pop();
            t = pr.second.first, wkt = pr.second.second;
            newPair = { pr.first + wkt * (t + 1), {t+1, wkt}};
            pq.push(newPair);
            mountainHeight--;
        }
        while(pq.size()){
            pr = pq.top(), pq.pop();
            t = pr.second.first, wkt = pr.second.second;
            if(t>1){
                res = max(res, wkt * (t * t - t) / 2 );
            }
        }
        return res;
    }
};
