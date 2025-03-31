class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        int k = original.size();
        vector<int> temp;
        if(m*n != k)
            return ans;
        for(int i = 0; i < k; i += n){
            for(int j = i; j < i+n; j++){
                temp.push_back(original[j]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};