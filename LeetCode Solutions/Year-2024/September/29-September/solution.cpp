class AllOne {
public:
    unordered_map<string, int> u;
    map<int, unordered_set<string>> m;
    AllOne() {
        u.clear(), m.clear();
    }
    
    void inc(string key) {
        if(u.find(key)!=u.end()){
            if(m[u[key]].size()==1)
                m.erase(u[key]);
            else
                m[u[key]].erase(key);
            m[u[key]+1].insert(key);
        }else{
            m[1].insert(key);
        }
        u[key]++;
        return ;
    }
    
    void dec(string key) {
        if(u[key]==1){
            u.erase(key);
            if(m[1].size()==1)
                m.erase(1);
            else
                m[1].erase(key);
        }else{
            u[key]--;
            if(m[u[key]+1].size()==1)
                m.erase(u[key]+1);
            else
                m[u[key]+1].erase(key);
            m[u[key]].insert(key);
        }
        return ;
    }
    
    string getMaxKey() {
        if(m.size()){
            auto itr = m.rbegin()->second.begin();
            return *itr;
        }
        return "";
    }
    
    string getMinKey() {
        if(m.size()){
            auto itr = m.begin()->second.begin();
            return *itr;
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */