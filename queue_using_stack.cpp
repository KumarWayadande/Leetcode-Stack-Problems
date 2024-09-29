class MyQueue {
public:
    vector<int> stack;
    int currSize, top;
    MyQueue() {
        stack = vector<int>(10000);
        top = -1;
        currSize = 0;
    }

    void push(int x) {
        top++;

        if (currSize == 0) {
            cout << "currSize = 0" << endl;
            this->stack[top] = x;
        } else {
            cout << "currSize = 1" << endl;
            vector<int> temp;
            for (int i = 0; i < currSize; i++) {
                cout << "item : " << this->stack[i] << endl;
                temp.insert(temp.end(), this->stack[i]);
            }
            this->stack[0] = x;
            int j = 1;
            for (auto item : temp) {
                this->stack[j] = item;
                j++;
            }
        }
        cout << "Push" << endl;
        currSize++;
    }

    int pop() {
        int item = this->stack[top];
        top--; currSize--;
        return item;
    }

    int peek() {
        return this->stack[top];
    }

    bool empty() {
        if(top == -1 || currSize == 0)
            return true;
        return false;
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