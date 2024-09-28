#include <iostream>
#include "functions.h"
using namespace std;

int main(){

    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    myQueue.printQueue();

    myQueue.dequeue();

    myQueue.printQueue();


    
    return 0;
}
