class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    void reverse(int x){
        if(s.empty()){
            s.push(x);
            return;
        }
        int peek=s.top();
        s.pop();
        reverse(x);
        s.push(peek);
        return;
    }
    void push(int x) {
        reverse(x);
    }
    
    int pop() {
        int popped=s.top();
        s.pop();
        return popped;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */