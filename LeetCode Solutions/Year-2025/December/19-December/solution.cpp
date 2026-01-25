class Solution {
private:
    static bool compareFunc(vector<int> a, vector<int> b){
        if (a[2]<b[2]){
            return true;
        }else if(a[2]==b[2] && a[0]<b[0]){
            return true;
        }else if(a[2]==b[2] && a[0]==b[0] && a[1]<b[1]){
            return true;
        }else return false;
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int a, b;
        for(int i = 0; i<meetings.size(); i++){
            a = meetings[i][0], b = meetings[i][1];
            if(a>b) meetings[i][0] = b, meetings[i][1] = a;
        }
        sort(meetings.begin(), meetings.end(), compareFunc);
        map<int, int> mp;
        mp[0]++, mp[firstPerson]++;
        vector<int> vec;
        int time, flag = 0;
        vector<set<int>> vec_set;
        set<int> st;
        for(int i = 0; i<meetings.size(); i++){
            time = meetings[i][2];
            while(i<meetings.size() && time==meetings[i][2]){
                a = meetings[i][0], b = meetings[i][1];
                if(mp.find(a)!=mp.end() || mp.find(a)!=mp.end()){
                    mp[a]++, mp[b]++;
                }else{
                    flag = 1;
                    for(int j = 0; j<vec_set.size(); j++){
                        if(vec_set[j].find(a)!=vec_set[j].end() || vec_set[j].find(b)!=vec_set[j].end()){
                            vec_set[j].insert(a), vec_set[j].insert(b);
                            flag = 0;
                        }
                    }
                    if(flag){
                        st.insert(a), st.insert(b);
                        vec_set.push_back(st);
                        st.clear();
                    }
                }
                i++;
            }
            i--;
            for(int j = 0; j<vec_set.size(); j++){
                st = vec_set[j];
                flag = 0;
                for(auto x = st.begin(); x != st.end(); x++){
                    if(mp.find(*x)!=mp.end()) flag = 1;
                }
                if(flag){
                    for(auto x = st.begin(); x != st.end(); x++){
                        mp[*x]++;
                    }
                }
                st.clear();
            }
            if(flag){
                for(int j = 0; j<vec.size(); j++) mp[vec[j]]++;
            }
            vec_set.clear();
            st.clear();
        }
        for(auto x = mp.begin(); x != mp.end(); x++) vec.push_back(x->first);
        return vec;
    }
};
