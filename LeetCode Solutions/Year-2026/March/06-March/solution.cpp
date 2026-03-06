class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        char ch = '1';
        for(char c : s){
            if(c!=ch){
                count++;
                ch = c;
            }
        }
        return count<2;
    }
};
