class Solution {
public:
    vector<int> getZero(vector<vector<int>>& vec){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(vec[i][j]==0) return {i, j};
            }
        }
        return {0, 0};
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> vec = {{1,2,3}, {4,5,0}}, temp;
        int ans = 0, k;
        queue<vector<vector<int>>> q;
        q.push(vec);
        map<vector<vector<int>>, int> mp;
        mp[vec]++;
        vector<int> coord, dx, dy;
        dx = {-1, 0, 0, 1};
        dy = {0, -1, 1, 0};
        while(ans<100){
            k = q.size();
            while(k--){
                vec = q.front();
                q.pop();
                if(vec==board)
                    return ans;
                coord = getZero(vec);
                for(int i = 0; i < 4; i++){
                    if(coord[0]+dx[i]>=0 && coord[0]+dx[i]<2 && coord[1]+dy[i]>=0 && coord[1]+dy[i]<3){
                        temp = vec;
                        temp[coord[0]][coord[1]] = temp[coord[0]+dx[i]][coord[1]+dy[i]];
                        temp[coord[0]+dx[i]][coord[1]+dy[i]] = 0;
                        if(mp.find(temp)==mp.end()){
                            mp[temp]++;
                            q.push(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};