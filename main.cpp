#include <iostream>
#include "functions.h"
using namespace std;

int main(){

    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.clear();
    myStack.printStack();
    cout << "Empty Status :" << myStack.isEmpty() << endl;
    cout << "Size of Stack :" << myStack.size() << endl;


    
    return 0;
}
