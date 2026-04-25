class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int> res;
        for(int x : arr){
            int n = res.size();
            while(true){
                n = res.size();
                if(n==0){
                    res.push_back(x);
                    break;
                }else if(res[n-1]*x < 0){
                    if(res[n-1]+x==0){
                        res.pop_back();
                        break;
                    }else{
                        if(abs(x) < abs(res[n-1])){
                            break;
                        }else
                            res.pop_back();
                    }
                }else{
                    res.push_back(x);
                    break;
                }
            }
        }
        return res;
    }
};
