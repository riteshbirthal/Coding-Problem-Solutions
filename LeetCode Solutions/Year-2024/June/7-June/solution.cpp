class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> vec;
        string ans = "", temp = "";
        unordered_map<string, int> u_mp;
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i]==' '){
                if(temp.size()){
                    vec.push_back(temp);
                    temp.clear();
                }
            }else{
                temp += sentence[i];
            }
        }
        if(temp.size()) vec.push_back(temp);
        for(int i = 0; i < dictionary.size(); i++)
            u_mp[dictionary[i]]++;
        for(int i = 0; i < vec.size(); i++){
            temp = "";
            for(int j = 0; j < vec[i].size(); j++){
                temp += vec[i][j];
                if(u_mp.find(temp)!=u_mp.end()){
                    vec[i] = temp;
                    break;
                }
            }
            ans += vec[i];
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};