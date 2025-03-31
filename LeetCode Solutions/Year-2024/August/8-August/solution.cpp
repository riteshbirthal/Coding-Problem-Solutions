class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int dir = 1, itr = 1, siz = 0;
        vector<vector<int>> ans;
        while(siz<rows*cols){
            switch(dir){
                case 1:
                    // code for right direction
                    for(int i = 0; i < itr; i++){
                        if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                            ans.push_back({rStart, cStart});
                            siz++;
                        }
                        cStart++;
                    }
                    dir = 2;
                    break;
                case 2:
                    // code for down direction
                    for(int i = 0; i < itr; i++){
                        if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                            ans.push_back({rStart, cStart});
                            siz++;
                        }
                        rStart++;
                    }
                    itr++;
                    dir = 3;
                    break;
                case 3:
                    // code for left direction
                    for(int i = 0; i < itr; i++){
                        if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                            ans.push_back({rStart, cStart});
                            siz++;
                        }
                        cStart--;
                    }
                    dir = 4;
                    break;
                case 4:
                    // code for top direction
                    for(int i = 0; i < itr; i++){
                        if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                            ans.push_back({rStart, cStart});
                            siz++;
                        }
                        rStart--;
                    }
                    itr++;
                    dir = 1;
                    break;
                default:
                    // default execution
                    break;
            }
        }
        return ans;
    }
};