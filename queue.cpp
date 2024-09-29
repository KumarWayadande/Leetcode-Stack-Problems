#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
    vector<int> queue;
    int maxSize, currSize, front, rear;

public:
    Queue() {}
    Queue(int);
    void push(int);
    void display();
    bool isFull();
    bool isEmpty();
    int pop();
    int peek();
    bool search(int);
    static void notify(string, int);
};

bool Queue ::search(int key)
{
    int i = 0;
    int f = front;
    while (i < currSize)
    {
        if (this->queue[f] == key)
            return true;
        f = (f + 1) % maxSize;
    }

    return false;
}

int Queue ::peek()
{
    return this->queue[front];
}

void Queue ::display()
{
    int i = 0;
    int f = front;
    while (i < currSize)
    {
        cout << this->queue[f] << "  ";
        f = (f + 1) % maxSize;
        i++;
    }
}

bool Queue ::isFull()
{
    if (this->currSize >= this->maxSize)
        return true;

    return false;
}

bool Queue ::isEmpty()
{
    if (front == -1 || currSize == 0)
        return true;
    return false;
}

Queue::Queue(int size)
{
    queue = vector<int>(size);
    maxSize = size;
    currSize = 0;
    front = -1;
    rear = -1;
}

void Queue ::push(int data)
{
    if (front == -1)
    {
        rear = 0;
        front = 0;
    }
    else
        rear = (rear + 1) % maxSize;

    currSize++;
    this->queue[rear] = data;
}

int Queue ::pop()
{
    currSize--;
    int deletedItem = this->queue[front];
    front = (front + 1) % maxSize;
    return deletedItem;
}
void Queue ::notify(string message, int data = -999)
{
    cout << endl
         << "!!! " << message << ((data != -999) ? " " + data : "") << "!!!";
}
int main()
{

    Queue *queue = nullptr;

    int choice = 0;

    while (choice != 11)
    {
        cout << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << endl
             << "~~~~~~~~~~~~~~   Queue    ~~~~~~~~~~~~";
        cout << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << endl
             << "1. Create Queue";
        cout << endl
             << "2. Display Queue";
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
            if (queue == nullptr)
            {
                cout << "\nEnter Size : ";
                int size;
                cin >> size;
                queue = new Queue(size);
                Queue::notify("Queue created with the size of", size);
            }
            else
                Queue::notify("Queue is already created");
            break;
        case 2:
            if (queue != nullptr)
            {
                if (!queue->isEmpty())
                {
                    cout << "!!! Queue !!!" << endl;
                    queue->display();
                }
                else
                    Queue::notify("Queue is empty");
            }
            else
                Queue::notify("Please create Queue first");
            break;
        case 3:
            if (queue != nullptr)
            {
                if (!queue->isFull())
                {
                    cout << "Enter data : ";
                    int data;
                    cin >> data;
                    queue->push(data);
                    Queue::notify("Data Inserted in the Queue");
                }
                else
                    Queue::notify("Queue is full");
            }
            else
                Queue::notify("Please create queue first");
            break;
        case 4:
            if (queue != nullptr)
            {
                if (!queue->isEmpty())
                    cout << "\n Deleted Element : " << queue->pop();
                else
                    Queue::notify("Queue is empty");
            }
            else
                Queue::notify("Please create queue first");
            break;
        case 5:
            if (queue != nullptr)
            {
                if (!queue->isEmpty())
                    cout << "\n Peek Element : " << queue->peek();
                else
                    Queue::notify("Queue is empty");
            }
            else
                Queue::notify("Please create queue first");
            break;
        case 10:
            if (queue != nullptr)
            {
                if (!queue->isEmpty())
                {

                    cout << "\nEnter key : ";
                    int key;
                    cin >> key;
                    if (queue->search(key))
                        cout << "\n Key Found";
                    else
                        cout << "\n Key Not Found";
                }
                else
                    Queue::notify("Queue is empty");
            }
            else
                Queue::notify("Please create queue first");
            break;
        case 11:
            Queue::notify("Thank You Visit Again");
            break;

        default:
            Queue::notify("Please enter correct choice");
            break;
        }
    }

    return 0;
}