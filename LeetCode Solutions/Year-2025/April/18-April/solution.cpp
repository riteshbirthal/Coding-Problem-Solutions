class Solution {
public:
    string countAndSay(int n) {
        string res = "1", new_res;
        char ele;
        int count, siz;
        for(int i = 1; i < n; i++){
            ele = res[0];
            count = 1, siz = res.size();
            new_res = "";
            for(int j = 1; j < siz; j++){
                if(res[j]==ele){
                    count++;
                }else{
                    new_res += to_string(count) + ele;
                    ele = res[j], count = 1;
                }
            }
            new_res += to_string(count) + ele;
            res = new_res;
        }
        return res;
    }
};
