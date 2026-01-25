class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int res = 0, mx = 0;
        sort(meetings.begin(), meetings.end());
        vector<int> cap(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pair<long long, int> pr;
        for(vector<int> v : meetings){
            while( pq.size() && pq.top().first < v[0]){
                pr = pq.top(), pq.pop();
                pr.first = v[0];
                pq.push(pr);
            }
            if(pq.size()==0 || (pq.size()<n && pq.top().first>v[0])){
                pq.push({v[1], pq.size()});
                continue;
            }
            pr = pq.top(), pq.pop();
            cap[pr.second]++;
            pr.first = max((long long)v[1], pr.first + v[1]-v[0]);
            pq.push(pr);
        }
        for(int i = 0; i < n; i++){
            if(mx < cap[i])
                res = i, mx = cap[i];
        }
        return res;
    }
};
