class Solution {
  public:
    void findPer(vector<int>& arr, vector<int>& vec, set<int>& st, vector<vector<int>>& res){
        if(vec.size()==arr.size()){
            res.push_back(vec);
            return ;
        }
        for(int x : arr){
            if(st.find(x)==st.end()){
                st.insert(x);
                vec.push_back(x);
                findPer(arr, vec, st, res);
                vec.pop_back();
                st.erase(x);
            }
        }
        return ;
    }
    
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        vector<vector<int>> res;
        vector<int> vec;
        set<int> st;
        findPer(arr, vec, st, res);
        return res;
    }
};
