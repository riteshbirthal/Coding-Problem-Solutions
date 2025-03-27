class Solution {
    public:
        typedef pair<int , pair<int,int>> pp;
        vector<vector<int>> directions = {{0,-1}, {0,1} , {-1,0} , {1,0}};
        int trapRainWater(vector<vector<int>>& heightMap) {
            int n = heightMap[0].size();
            int m = heightMap.size();
            priority_queue<pp, vector<pp>, greater<>> boundaryCell;
            vector<vector<bool>> visited (m, vector<bool>(n,false));
            for(int row =0 ;row <m; row++){
                for(int col : {0,n-1}){
                    boundaryCell.push({heightMap[row][col], {row,col}});
                    visited[row][col] = true;
                }
            }
            for(int col =0 ;col <n; col++){
                for(int row : {0,m-1}){
                    boundaryCell.push({heightMap[row][col], {row,col}});
                    visited[row][col] = true;
                }
            }
            int water = 0;
            while(!boundaryCell.empty()){
                pp p1= boundaryCell.top();
                boundaryCell.pop();
                int height = p1.first;
                int i = p1.second.first;
                int j = p1.second.second;
    
    
                for(vector<int> &dir : directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(i_ >0 && j_ > 0 && i_ < m && j_ < n && !visited[i_][j_]){
                        water += max((height - heightMap[i_][j_]) , 0 );
                        boundaryCell.push({max(height , heightMap[i_][j_]) , {i_,j_}});
                        visited[i_][j_] = true;
                    }
                }
            }
            return water;
        }
    };