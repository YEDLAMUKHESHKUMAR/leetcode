class MyCalendarTwo {
public:
    map<int,int> lineSweep;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        // simple example : [10,20], [1,12]  ... if these two are overlapping, 
        // what interval can't be the third one??  
        // it should not be from [10,12] , because this interval, booked 2 times already....

        // using line sweep

        lineSweep[startTime]++;
        lineSweep[endTime]--;
        int overLapping = 0;
        for(auto &i: lineSweep) {
            overLapping += i.second;
            if(overLapping >= 3) {
                lineSweep[startTime]--;
                lineSweep[endTime]++; 
                return false;
            }
        }
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */