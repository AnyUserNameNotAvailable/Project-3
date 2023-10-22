#include "Queue.hpp"
#include <iostream>

bool BinaryQueue::isempty(){
    return front == nullptr;
}
void BinaryQueue::deQueue(int &value){
    if(isempty()){
        throw std::runtime_error("Queue is Empty");
    } else{
        value = front->val;
        QueueNode *temp = front;
        front = front->next;
        delete temp;
    }
}
void BinaryQueue::enQueue(int value) {
    QueueNode* newNode = new QueueNode;
    newNode->val = value;
    newNode->next = nullptr;

    if (isempty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}
void BinaryQueue::displayQueue() const {
    QueueNode* nodePtr = front;
    while (nodePtr) {
        std::cout << nodePtr->val;
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}
void BinaryQueue::clear() {
    while (!isempty()) {
        int value;
        deQueue(value);
    }
}
