class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            vector<string> res, curr;
            queue<vector<string>> q;
            unordered_set<string> sup(supplies.begin(), supplies.end());
            int n = recipes.size(), k, flag = 1, isReceipePossible, anyChange, siz;
            for(int i = 0; i < n; i++){
                vector<string> v = {recipes[i]};
                for(string igr : ingredients[i])
                    v.push_back(igr);
                q.push(v);
            }
            while(flag){
                k = q.size();
                anyChange = 0;
                while(k--){
                    curr = q.front(), q.pop();
                    siz = curr.size();
                    isReceipePossible = 1;
                    for(int i = 1; i < siz; i++){
                        isReceipePossible = isReceipePossible && (sup.find(curr[i])!=sup.end());
                    }
                    anyChange = anyChange || isReceipePossible;
                    if(isReceipePossible){
                        sup.insert(curr[0]);
                        res.push_back(curr[0]);
                    }else{
                        q.push(curr);
                    }
                }
                if(!anyChange)
                    flag = 0;
            }
            return res;
        }
    };