class MyCalendar {
private: 
    vector<pair<int,int>> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto p : bookings){
            if(max(p.first,start)<min(p.second,end)) return false;
        }
        
        bookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */