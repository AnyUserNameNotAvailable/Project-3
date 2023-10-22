#ifndef Queue_hpp

#define Queue_hpp

class BinaryQueue {
private:
    struct QueueNode {
        int val;
        QueueNode* next;
    };
    QueueNode* front;
    QueueNode* rear;
    int numItems;//number of items in queue
public:
    BinaryQueue(){
        front = nullptr;
        rear = nullptr;
    }
    ~BinaryQueue(){
        clear();
    }
    void enQueue(int);
    void deQueue(int&);
    void displayQueue() const;
    bool isempty();
};
#endif /* Queue_hpp */
