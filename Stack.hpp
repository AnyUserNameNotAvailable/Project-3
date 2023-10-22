#ifndef Stack_hpp

#define Stack_hpp

#include <iostream>

class BinaryStack {
private:
    struct StackNode {
        int val;
        StackNode *next;
    };
    StackNode *top;
public:
    BinaryStack() {
        top = nullptr;
    }
    ~BinaryStack() {
        clear();
    }
    void push(int);
    void pop(int);
    int peek() const;
    void displayStack() const;
    void clear();
    };

};

#endif /* Stack_hpp */