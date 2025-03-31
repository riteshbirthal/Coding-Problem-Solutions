class Solution {
public:
    vector<int> func(string s, int l, int r, map<pair<int, int>, vector<int>> & mp){
        if(l>r)
            return {0};
        if(l==r || l==r-1){
            return {stoi(s.substr(l, r-l+1))};
        }
        if(mp.find({l, r})!=mp.end()) return mp[{l, r}];
        vector<int> vec, v1, v2;
        for(int i = l; i < r; i++){
            if(s[i]<'0' || s[i]>'9'){
                v1 = func(s, l, i-1, mp);
                v2 = func(s, i+1, r, mp);
                if(s[i]=='+'){
                    for(int j = 0; j < v1.size(); j++){
                        for(int k = 0; k < v2.size(); k++){
                            vec.push_back(v1[j]+v2[k]);
                        }
                    }
                }else if(s[i]=='-'){
                    for(int j = 0; j < v1.size(); j++){
                        for(int k = 0; k < v2.size(); k++){
                            vec.push_back(v1[j]-v2[k]);
                        }
                    }
                }else{
                    for(int j = 0; j < v1.size(); j++){
                        for(int k = 0; k < v2.size(); k++){
                            vec.push_back(v1[j]*v2[k]);
                        }
                    }
                }
            }
        }
        return mp[{l, r}] = vec;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> vec;
        if(expression[0]=='-' || expression[0]=='+') 
            expression = "0" + expression;
        int n = expression.size();
        map<pair<int, int>, vector<int>> mp;
        vec = func(expression, 0, n-1, mp);
        return vec;
    }
};