#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"

void convertToStack(BinaryStack &S, int num);
void convertAndEnqueue(BinaryQueue &Q, double decimal, int precision);

int main() {
    BinaryStack S;
    BinaryQueue Q;
    double value;
    int decimalPrecision;//Determines Decimal Precision of queue
    std::cout << "Enter a value: ";
    std::cin >> value;
    std::cout << "How many decimal places: ";
    std::cin >> decimalPrecision;
    int integerVal = static_cast<int>(value); //converts double into interger value
    double decimal = value - integerVal; //leaves decimal value

    // Convert integer part to binary and push it into the stack
    convertToStack(S, integerVal);

    // Convert decimal part to binary and enqueue it
    convertAndEnqueue(Q, decimal, decimalPrecision);
    
    // Display the binary representation from the stack
    std::cout << "Binary representation: ";
    S.displayStack();

    // Display the decimal point
    std::cout << ".";

    // Display the binary representation from the queue
    Q.displayQueue();
    
    return 0;

}

void convertToStack(BinaryStack &S, int num) {
    if (num == 0) {
        return;
    } else {
        S.push(num % 2);
        convertToStack(S, num / 2);
    }
}

void convertAndEnqueue(BinaryQueue &Q, double decimal, int precision) {
    if (precision == 0) {
        return;
    } else {
        decimal *= 2;
        int bit = static_cast<int>(decimal);
        Q.enQueue(bit);
        decimal -= bit;
        convertAndEnqueue(Q, decimal, precision - 1);
    }
}
