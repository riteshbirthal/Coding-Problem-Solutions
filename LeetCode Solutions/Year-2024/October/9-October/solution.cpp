class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, openings = 0;
        for(auto & ch : s){
            if(ch=='('){
                openings++;
            }else if(openings){
                openings--;
            }else{
                ans++;
            }
        }
        ans += openings;
        return ans;
    }
};