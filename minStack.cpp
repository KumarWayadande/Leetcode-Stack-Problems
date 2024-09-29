class MinStack {
public:
    int min;
    vector<int> stack1;
    int topPointer;
    MinStack() {
        stack1 = vector<int>(10000);
        topPointer = -1;
        min = -1;
    }
    
    void setMinimum(){
        if(topPointer != -1){
            auto min1 = min_element(stack1.begin(), stack1.begin() + topPointer + 1);
            cout << *min1;
            this->min = *min1;
        }
    }

    void push(int val) {
        cout << "Pushed";
        if(topPointer == -1){
            min = val;
            topPointer = 0;
        }else{
            topPointer++;
        }
        stack1[topPointer] = val;
        setMinimum();
    }
    
    void pop() {
        topPointer--;
        setMinimum();
    }
    
    int top() {
        return stack1[topPointer];
    }
    
    int getMin() {
        return this->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */