class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int idx = 0, n = times.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> ar, lv, t;
        priority_queue<int, vector<int>, greater<int>> uocc;

        for(int i = 0; i < n+1; i++)
            uocc.push(i);

        for(auto v : times)
            ar.push({v[0], idx, v[1]}), idx++;
        
        for(int i = 1; i < 1e5 + 1; i++){ 
            while(lv.size() && lv.top()[0]==i)
                uocc.push(lv.top()[1]), lv.pop();
            if(ar.size() && ar.top()[0]==i && ar.top()[1]==targetFriend)
                return uocc.top();
            if(ar.size() && ar.top()[0]==i)
                lv.push({ar.top()[2], uocc.top()}), ar.pop(), uocc.pop();
        }
        return n+1;
    }
};