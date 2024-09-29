class MyStack {
public:
    vector<int> queue;
    int front, rear, currSize, maxSize;
    MyStack() {
        queue = vector<int>(10000);
        currSize = 0;
        maxSize = 0;
        front = -1;
        rear = -1;
    }

    void push(int x) {
        this->currSize++;
        if(rear == -1){
            front = 0;
            rear = 0;
        }
        else
            rear += 1;
        
        if(currSize > 0){
            vector<int> temp;
            int i = 0;
            while(i < currSize){
                temp.insert(temp.end(), this->queue[i++]);
            }
            this->queue[0] = x;
            i = 1; 
            int j = 0;
            while(j < temp.size()){
                this->queue[i] = temp[j];
                i++;j++;
            }
        }
        else{
            this->queue[0] = x;
        }
    }

    int pop() {
        
        int i = 0;
        int item = this->queue[0];
        while( i < (currSize - 1)){ 
            this->queue[i] = this->queue[i + 1];
            i++;
        }
        rear--;
        currSize--;
        return item;
    }

    int top() {
        return this->queue[front];
    }

    bool empty() {
        if (rear == -1 || currSize == 0)
            return true;
        return false;
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