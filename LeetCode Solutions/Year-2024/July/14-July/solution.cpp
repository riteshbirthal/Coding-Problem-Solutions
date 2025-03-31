class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> st, st1;
        string element = "", ans = "", count = "", s = formula;
        int n = formula.size(), num;
        for(int i = 0; i < n; i++){
            if(s[i]=='('){
                if(element.size()){
                    if(count.size()){
                        st.push({element, stoi(count)});
                    }else{
                        st.push({element, 1});
                    }
                }
                st.push({"", 0});
                element = "", count = "";
            }else if(s[i]>='0' && s[i]<='9'){
                count += s[i];
            }else if(s[i]>='a' && s[i]<='z'){
                element += s[i];
            }else if(s[i]>='A' && s[i]<='Z'){
                if(element.size()){
                    if(count.size()){
                        st.push({element, stoi(count)});
                    }else{
                        st.push({element, 1});
                    }
                }
                element = "", count = "";
                element += s[i];
            }else if(s[i]==')'){
                if(element.size()){
                    if(count.size()){
                        st.push({element, stoi(count)});
                    }else{
                        st.push({element, 1});
                    }
                }
                element = "", count = "";
                i++;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    count += s[i];
                    i++;
                }
                num = 1;
                if(count.size()){
                    num = stoi(count);
                }
                while(st.top().first.size()){
                    st1.push({st.top().first, num*st.top().second});
                    st.pop();
                }
                st.pop();
                while(!st1.empty()){
                    st.push(st1.top());
                    st1.pop();
                }
                element = "", count = "", i--;
            }
        }
        if(element.size()){
            if(count.size()){
                st.push({element, stoi(count)});
            }else{
                st.push({element, 1});
            }
        }
        map<string, int> mp;
        while(!st.empty()){
            if(mp.find(st.top().first)!=mp.end()) mp[st.top().first] += st.top().second;
            else mp[st.top().first] = st.top().second;
            st.pop();
        }
        for(auto x = mp.begin(); x != mp.end(); x++){
            if(x->second==1){
                ans += x->first;
            }else{
                ans += x->first + to_string(x->second);
            }
        }
        return ans;
    }
};