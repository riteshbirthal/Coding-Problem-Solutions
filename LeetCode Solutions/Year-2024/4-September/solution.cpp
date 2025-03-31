class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size(), ans = 0, m = obstacles.size(), direction = 0, x = 0, y = 0;
        map<vector<int>, int> mp;
        for(int i = 0; i < m; i++){
            mp[obstacles[i]]++;
        }
        for(auto t : commands){
            if(t==-1){
                direction = (direction + 5) % 4;
            }else if(t==-2){
                direction = (direction + 3) % 4;
            }else{
                for(int i = 0; i < t; i++){
                    if(direction==0){
                        if(mp.find({x, y+1})==mp.end())
                            y++;
                        else
                            break;
                    }else if(direction==1){
                        if(mp.find({x+1, y})==mp.end())
                            x++;
                        else
                            break;
                    }else if(direction==2){
                        if(mp.find({x, y-1})==mp.end())
                            y--;
                        else
                            break;
                    }else{
                        if(mp.find({x-1, y})==mp.end())
                            x--;
                        else
                            break;
                    }
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};