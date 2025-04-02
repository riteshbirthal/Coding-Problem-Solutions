class Solution {
public:
    string changeState(string currentState, int pos, int change){
        currentState[pos] = '0' + (currentState[pos] - '0' + change + 10)%10;
        return currentState;
    }

    int openLock(vector<string>& deadends, string target) {
        string currentState = "0000";
        int res = 0;
        unordered_set<string> dds(deadends.begin(), deadends.end()), visited;
        queue<string> q;
        if(dds.find(currentState)==dds.end())
            q.push("0000"), visited.insert("0000");
        while(!q.empty()){
            int k = q.size();
            while(k--){
                currentState = q.front(), q.pop();
                if(currentState==target)
                    return res;
                for(int i = 0; i < 4; i++){
                    string nextState = changeState(currentState, i, 1);
                    if(dds.find(nextState)==dds.end() && visited.find(nextState)==visited.end()){
                        q.push(nextState);
                        visited.insert(nextState);
                    }
                }
                for(int i = 0; i < 4; i++){
                    string nextState = changeState(currentState, i, -1);
                    if(dds.find(nextState)==dds.end() && visited.find(nextState)==visited.end()){
                        q.push(nextState);
                        visited.insert(nextState);
                    }
                }
            }
            res += 1;
        }
        return -1;
    }
};