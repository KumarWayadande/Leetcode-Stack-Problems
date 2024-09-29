#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    vector<int> stack;
    int size, top;

public:
    Stack() {}
    Stack(int);
    static void notify(string, int);
    bool isOverflow();
    bool isUnderFlow();
    void push(int);
    int pop();
    void display();
    int peek();
    bool search(int);
};

bool Stack ::search(int key)
{
    for (int x : this->stack)
    {
        if (x == key)
            return true;
    }

    return false;
}

int Stack ::pop()
{
    int data = this->stack[top--];
    return data;
}

void Stack ::display()
{
    for (int i = this->top; i >= 0; i--)
        cout << this->stack[i] << endl;
}

int Stack ::peek()
{
    return this->stack[this->top];
}

void Stack ::push(int data)
{
    this->top++;
    this->stack[this->top] = data;
}

bool Stack ::isUnderFlow()
{
    if (this->top == -1)
        return true;
    return false;
}

bool Stack ::isOverflow()
{
    if (this->top == this->size - 1)
        return true;
    return false;
}
Stack ::Stack(int size)
{
    this->stack = vector<int>(size);
    this->size = size;
    this->top = -1;
}
void Stack ::notify(string message, int data = 0)
{
    cout << endl
         << "!!! " << message << " !!!";
}

int main()
{
    Stack *stack = nullptr;
    int choice = 0;

    while (choice != 11)
    {
        cout << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << endl
             << "~~~~~~~~~~~~~~   Stack    ~~~~~~~~~~~~";
        cout << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << endl
             << "1. Create Stack";
        cout << endl
             << "2. Display Stack";
        cout << endl
             << "3. Push";
        cout << endl
             << "4. Pop";
        cout << endl
             << "5. Peek";
        cout << endl
             << "10. Search";
        cout << endl
             << "11. Exit";
        cout << endl
             << "  Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (stack == nullptr)
            {
                stack = new Stack(10);
                Stack::notify("Stack created with the size of 10");
            }
            else
                Stack::notify("Stack is already created");
            break;
        case 2:
            if (stack != nullptr)
            {
                if (!stack->isUnderFlow())
                {
                    cout << "!!! Stack !!!" << endl;
                    stack->display();
                }
                else
                    Stack::notify("Stack is empty");
            }
            else
                Stack::notify("Please create stack first");
            break;
        case 3:
            if (stack != nullptr)
            {
                if (!stack->isOverflow())
                {
                    cout << "Enter data : ";
                    int data;
                    cin >> data;
                    stack->push(data);
                    Stack::notify("Data Inserted in the Stack");
                }
                else
                    Stack::notify("Stack is full");
            }
            else
                Stack::notify("Please create stack first");
            break;
        case 4:
            if (stack != nullptr)
            {
                if (!stack->isUnderFlow())
                    cout << "\n Deleted Element : " << stack->pop();
                else
                    Stack::notify("Stack is empty");
            }
            else
                Stack::notify("Please create stack first");
            break;
        case 5:
            if (stack != nullptr)
            {
                if (!stack->isUnderFlow())
                    cout << "\n Peek Element : " << stack->peek();
                else
                    Stack::notify("Stack is empty");
            }
            else
                Stack::notify("Please create stack first");
            break;
        case 10:
            if (stack != nullptr)
            {
                if (!stack->isUnderFlow())
                {

                    cout << "\nEnter key : ";
                    int key;
                    cin >> key;
                    if (stack->search(key))
                        cout << "\n Key Found";
                    else
                        cout << "\n Key Not Found";
                }
                else
                    Stack::notify("Stack is empty");
            }
            else
                Stack::notify("Please create stack first");
            break;
        case 11:
            Stack::notify("Thank You Visit Again");
            break;

        default:
            Stack::notify("Please enter correct choice");
            break;
        }
    }
    return 0;
}