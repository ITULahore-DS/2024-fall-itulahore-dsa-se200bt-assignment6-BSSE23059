#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
using namespace std;


class Node{
private:
    int data;
    // data value
    Node* next;
    // next node reference
public:
    Node(int val) { // parameterized constructor
        this->data = val;
        this->next = nullptr;
    }
    // setting node
    void setNext(Node *val) {
        this->next = val;
    }

    // getting next node
    Node* getNext() {
        return next;
    }

    // Setting data
    void setData(int data) {
        this->data = data;
    }


    // getting data
    int getData() {
        return data;
    }

    // The life of node is not in it's hand.
    ~Node() {}

};

class Stack{
private:
    // The top node to maintain the top of the stack.
    Node* top;
    // count to maintain the size of stack.
    int count;
public:
    // Constructor
    Stack(){
        // top should not have any memory allocated.
        this->top = nullptr;
        // count should be zero.
        this->count = 0;
    }

    bool isEmpty(){
        if(top == nullptr && count == 0){
            return true;  // when stack is empty return true.
        }
        return false;     // otherwise false.
    }

    void push(int data){
        // Made a node a to push in the stack.
        Node* nodeToInsert = new Node(data);
        if (top != nullptr) {
        // Prepend the nodeToInsert
            nodeToInsert->setNext(top);
        }
        // Now, The nodeToInsert is the top.
        top = nodeToInsert;
        // Incrementing count.
        count++;
    }

    void pop(){
        if(isEmpty()){
            // Exception : If stack is empty, there's no need to pop.
            cout << "List is empty." << endl;
        } else {
            // Made a node that points to the next of top.
            Node* next = top->getNext();
            // Deleting the top.
            delete top;
            // Now my next node becomes top.
            top = next;
            // Decrementing count.
            count--;
        }
    }

    int peek(){
        if(isEmpty()){
            return -1;      // If stack is empty, print 
        }
        return top->getData();    // else return the data of top.
    }

    void printStack(){
        // Exception : If the stack is empty, don't print anything.
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        // Just iterate towards the end and print the whole stack from top to bottom.
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    int size(){
        // returning the size of stack.
        return count;
    }

    void clear(){
        // Just iterate through all nodes and delete them.
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
        count = 0;    // Now, stack is empty and count becomes zero.
    }

    ~Stack(){
        // Just iterate through all nodes and delete them.
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
    }
};

class Queue{
private:
    // The top node to maintain the rear of the queue.
    Node* top;
    // count to maintain the size of queue.
    int count;
public:
    // Constructor
    Queue(){
        // top should not have any memory allocated.
        this->top = nullptr;
        // count should be zero.
        this->count = 0;
    }

    bool isEmpty(){
        if(top == nullptr && count == 0){
            return true;        // when stack is empty return true.
        }
        return false;       // otherwise false.
    }

    void enqueue(int data){
        // Made a node a to place at the end the stack.
        Node* nodeToInsert = new Node(data);
        if (top != nullptr) {
            // The node is pushed at end.
            nodeToInsert->setNext(top);
        }
        // The top is the rear of the queue.
        top = nodeToInsert;
        // Incrementing size of the stack.
        count++;
    }

    void dequeue(){
        if(isEmpty()){
             // Exception : Cannot dequeue if queue is empty.
            cout << "Cannot dequeue." << endl;
        } else {
            if(count == 1){
                // If there is only one element the front and rear of the queue are the same,
                // just delete the rear or front.
                Node* temp = top;
                delete top;
                temp = nullptr;
                top = temp;
                
            } else {
                // In this case, the tail of the list is the front of our queue.
                Node* temp = top;
                int curr = 1;
                // Just itearte through the list and delete the last element which is the front
                // of the queue in this case.
                while(curr < count-1){
                    temp = temp ->getNext();
                    curr++;
                }
                Node* tail = temp->getNext();
                delete tail;
                temp->setNext(nullptr);
            }
            count--;     // decrementing count.  
        }
    }

    int peek(){
        if(count == 1){
            // If there is only one element the front and rear of the queue are the same,
            // just return the rear or front.
            return top->getData();
        } else if(isEmpty()) {
            // Exception : If queue is empty return -1,
            return -1;
        } else {
            // In this case, the tail of the list is the front of our queue.
            Node* temp = top;
            int curr = 1;
            // Just itearte through the list and return the last element which is the front
            // of the queue in this case.
            while(curr < count-1){
                temp = temp ->getNext();
                curr++;
            }
            Node* tail = temp->getNext();
            return tail->getData();
        }
        
    }

    void printQueue(){
        // Exception : If the stack is empty, don't print anything.
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        // Just iterate towards the end and print the whole stack from top to bottom.
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    int size(){
        // returning the size of queue.
        return count;
    }

    void clear(){
        // Just iterate through all nodes and delete them.
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
        count = 0;      // Now, queue is empty and count becomes zero.
    }

    ~Queue(){
        // Just iterate through all nodes and delete them.
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
    }

};


#endif