class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            vector<int> ans;
            map<int, int> mp, marked;
            int m = queries.size(), x, y;
            for(int i = 0; i < m; i++){
                x = queries[i][0], y = queries[i][1];
                if(mp.find(y)!=mp.end()){
                    if(marked.find(x)!=marked.end()){
                        if(mp[marked[x]]==1) mp.erase(marked[x]);
                        else mp[marked[x]]--;
                    }
                    mp[y]++;
                }else{
                    if(marked.find(x)!=marked.end()){
                        if(mp[marked[x]]==1) mp.erase(marked[x]);
                        else mp[marked[x]]--;
                    }
                    mp[queries[i][1]] = 1;
                }
                marked[queries[i][0]] = queries[i][1];
                ans.push_back(mp.size());
            }
            return ans;
        }
    };