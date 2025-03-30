class Solution {
public:
    vector<string> wordsFunc(string sentence){
        string st = "";
        vector<string> vec;
        for(auto ch : sentence){
            if(ch==' '){
                if(st.size())
                    vec.push_back(st);
                st = "";
            }else{
                st += ch;
            }
        }
        if(st.size())
            vec.push_back(st);
        return vec;
    }

    bool areSimilar(vector<string>& v1, vector<string>& v2){
        int n1 = v1.size(), n2 = v2.size(), count = 0, flag = 0, idx = 0, i = 0;
        for( ; i < n1 && idx<n2; i++, idx++){
            if(v1[i]!=v2[idx]){
                count++;
                while(idx<n2 && v1[i]!=v2[idx]){
                    idx++;
                }
            }
            if(idx==n2) break;
        }
        if(count>1) return false;
        if(count==1 && (i<n1 || idx<n2)) return false;
        cout << count << " " << i << " " << idx << endl;
        return true;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1, v2;
        v1 = wordsFunc(sentence1);
        cout << endl;
        v2 = wordsFunc(sentence2);
        int n1 = v1.size(), n2 = v2.size();
        if(n1==n2){
            return v1==v2;
        }else{
            if(n1<n2){
                bool ans = areSimilar(v1, v2);
                if(ans) return true;
                reverse(v1.begin(), v1.end());
                reverse(v2.begin(), v2.end());
                return areSimilar(v1, v2);
            }else{
                bool ans = areSimilar(v2, v1);
                if(ans) return true;
                reverse(v1.begin(), v1.end());
                reverse(v2.begin(), v2.end());
                return areSimilar(v2, v1);
            }
        }
        return true;
    }
};