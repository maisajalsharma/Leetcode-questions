class MyCircularQueue {
public:

    int *arr;
    int front , rear , n;

    MyCircularQueue(int k) {

        n = k;
        arr = new int[n];
        front = rear = -1;    
    }
    
    bool enQueue(int value) {

        if(isEmpty())
        {
            front = rear = 0;
            arr[0] = value;
        }
        else if(isFull())
        {
            return false;
        }
        else
        {
            rear = (rear+1)%n;
            arr[rear] = value;
        }

        return true;

    }
    
    bool deQueue() {

        if(isEmpty())
        {
            return false;
        }
        else if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front+1)%n;
        }

        return true;
        
    }
    
    int Front() {

        if(front == -1) return -1;
        else return arr[front%n];
        
    }
    
    int Rear() {

        if(rear == -1) return -1;
        else return arr[rear%n];
        
    }
    
    bool isEmpty() {

        return front == -1;
        
    }
    
    bool isFull() {

        return (rear+1)%n == front;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */