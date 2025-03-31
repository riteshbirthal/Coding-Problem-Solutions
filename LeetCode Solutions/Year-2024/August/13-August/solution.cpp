class Solution {
public:
    void func(vector<int>& candidates, int idx, int target, vector<int>& vec, map<vector<int>, int>& mp){
        if((idx<0 && target) || (target<0)) return ;
        if(target==0){
            vector<int> temp = vec;
            sort(temp.begin(), temp.end());
            mp[temp]++;
            return ;
        }
        if(candidates[idx]==1 && idx+1<target) return;
        if(candidates[idx]==1 && idx+1>=target){
            int temp1 = target;
            while(temp1){
                vec.push_back(1);
                temp1--;
            }
            func(candidates, idx-target+1, 0, vec, mp);
            temp1 = target;
            while(temp1){
                vec.pop_back();
                temp1--;
            }
            return ;
        }
        if(candidates[idx]>target){
            func(candidates, idx-1, target, vec, mp);
            return ;
        }
        func(candidates, idx-1, target, vec, mp);
        vec.push_back(candidates[idx]);
        func(candidates, idx-1, target-candidates[idx], vec, mp);
        vec.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        map<vector<int>, int> mp;
        vector<int> vec;
        func(candidates, candidates.size()-1, target, vec, mp);
        vector<vector<int>> answer;
        for(auto x = mp.begin(); x != mp.end(); x++) answer.push_back(x->first);
        return answer;
    }
};