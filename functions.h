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


    ~Node() {}

};

class Stack{
private:
    Node* top;
    int count;
public:
    Stack(){
        this->top = nullptr;
        this->count = 0;
    }

    bool isEmpty(){
        if(top == nullptr && count == 0){
            return true;
        }
        return false;
    }

    void push(int data){
        Node* nodeToInsert = new Node(data);
        if (top != nullptr) {
            nodeToInsert->setNext(top);
        }
        top = nodeToInsert;
        count++;
    }

    void pop(){
        if(isEmpty()){
            cout << "List is empty." << endl;
        } else {
            Node* next = top->getNext();
            delete top;
            top = next;
            count--;
        }
       
    }

    int peek(){
        if(top == nullptr && count == 0){
            return -1;
        }
        return top->getData();
    }

    void printStack(){
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    int size(){
        return count;
    }

    void clear(){
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
        count = 0;
    }

    ~Stack(){
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
    }
};

class Queue{
private:
    Node* top;
    int count;
public:
    Queue(){
        this->top = nullptr;
        this->count = 0;
    }

    bool isEmpty(){
        if(top == nullptr && count == 0){
            return true;
        }
        return false;
    }

    void enqueue(int data){
        Node* nodeToInsert = new Node(data);
        if (top != nullptr) {
            nodeToInsert->setNext(top);
        }
        top = nodeToInsert;
        count++;
    }

    void dequeue(){
        Node* temp = top;
        int curr = 1;
        while(curr < count-1){
            temp = temp ->getNext();
            curr++;
        }
        Node* tail = temp->getNext();
        delete tail;
        temp->setNext(nullptr);
        count--;
    }

    void printQueue(){
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    int size(){
        return count;
    }

    void clear(){
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
        count = 0;
    }

    ~Queue(){
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
    }

};


#endif