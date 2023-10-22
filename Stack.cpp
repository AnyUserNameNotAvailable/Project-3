#include "Stack.hpp"
#include <iostream>

void BinaryStack::push(int value){
    StackNode* newNode = new StackNode;
    newNode->val = value;
    newNode->next = top;
    top = newNode;
}
void BinaryStack::pop(int value){
    if (top != nullptr){
        StackNode *temp = top;
        top = top->next;
        delete temp;
    }
}
int BinaryStack::peek() const{
    if (top == nullptr) {
        return 0;
    } else {
        return top->val;
    }
}
void BinaryStack::clear(){
    while (top != nullptr){
        pop();
    }
}
void BinaryStack::displayStack() const{
    StackNode *nodePtr = top;
    while (nodePtr){
        std::cout << nodePtr ->val;
        nodePtr = nodePtr->next;
    }
}