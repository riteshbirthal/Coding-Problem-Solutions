class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;
        vector<vector<int>> vec;
        int n = positions.size();
        for(int i = 0; i < n; i++){
            if(directions[i]=='R'){
                vec.push_back({positions[i], healths[i], 1});
            }else{
                vec.push_back({positions[i], healths[i], -1});
            }
        }
        sort(vec.begin(), vec.end());
        stack<vector<int>> st;
        for(int i = 0; i < n; i++){
            if(!st.empty() && vec[i][2]==-1 && st.top()[2]==1){
                while(true){
                    if(!st.empty() && vec[i][2]==-1 && st.top()[2]==1){
                        if(st.top()[1]<vec[i][1]){
                            vec[i][1]--;
                            st.pop();
                        }else if(st.top()[1]>vec[i][1]){
                            st.top()[1]--;
                            break;
                        }else{
                            st.pop();
                            break;
                        }
                    }else{
                        st.push(vec[i]);
                        break;
                    }
                }
            }else{
                st.push(vec[i]);
            }
        }
        map<int, int> mp;
        while(!st.empty()){
            mp[st.top()[0]] = st.top()[1];
            st.pop();
        }
        for(int i = 0; i < n; i++){
            if(mp.find(positions[i])!=mp.end())
                ans.push_back(mp[positions[i]]);
        }
        return ans;
    }
};