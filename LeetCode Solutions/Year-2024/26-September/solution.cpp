class MyCalendar {
public:
    map<vector<int>, int> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(!cal.size() || cal.begin()->first[0]>=end || cal.rbegin()->first[1]<=start){
            cal[{start, end}]++;
            return true;
        }
        auto itr = cal.begin();
        vector<int> prev, nxt;
        prev = itr->first;
        itr++;
        for(; itr != cal.end(); itr++){
            nxt = itr->first;
            if(prev[1]<=start && end<=nxt[0]){
                cal[{start, end}]++;
                return true;
            }
            prev = nxt;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */