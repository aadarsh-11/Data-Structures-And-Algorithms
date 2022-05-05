class MyStack {
public:
    queue<int> q2;
    bool full = 0;
    int tp;
    MyStack() {
        
    }
    
    void push(int x) {
        if(full)
        {
            q2.push(tp);
        }
        tp = x;
        full = 1;
    }
    
    int pop() {
        
        int rt = tp;
        queue<int> q3;
        if(q2.empty())
        {
            full = 0;
            return tp;
        }
        while(q2.size() > 1)
        {
            int y = q2.front();
            q3.push(y);
            q2.pop();
        }
        tp = q2.front();
        q2 = q3;
        
        return rt;
    }
    
    int top() {
        return tp;
    }
    
    bool empty() {
        return full == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */