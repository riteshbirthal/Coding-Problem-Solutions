class MyCalendarTwo {
public:
    vector<pair<int, int>> sgl, dbl;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto &p : dbl){
            if(start < p.second && p.first < end){
                return false;
            }
        }

        for(auto &p : sgl){
            if(start < p.second && p.first < end){
                dbl.push_back({max(start, p.first), min(end, p.second)});
            }
        }
        sgl.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */