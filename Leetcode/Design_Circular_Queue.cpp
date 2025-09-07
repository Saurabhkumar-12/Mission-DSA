class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        data.resize(k);
        head = -1;
        tail = -1;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            head = 0;
            tail = 0;
            data[tail] = value;
        } else {
            tail = (tail + 1) % capacity;
            data[tail] = value;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % capacity;
        }
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return data[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};  
