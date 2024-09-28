#include <iostream>
#include "functions.h"
using namespace std;

void displayMenu() {
    cout << "=========================================" << endl;
    cout << "                  LAB-06                 " << endl;
    cout << "=========================================" << endl;
    cout << "1. Stack Operations" << endl;
    cout << "2. Queue Operations" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
}

void stackMenu(Stack& stack) {
    int choice, value;
    do {
        cout << "=========================================" << endl;
        cout << "             Stack Operations            " << endl;
        cout << "=========================================" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print Stack" << endl;
        cout << "4. Check Size" << endl;
        cout << "5. Clear Stack" << endl;
        cout << "6. Go Back" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.printStack();
                break;
            case 4:
                cout << "Current size: " << stack.size() << endl;
                break;
            case 5:
                stack.clear();
                cout << "Stack cleared." << endl;
                break;
            case 6:
                cout << "Going back to main menu..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 6);
}

void queueMenu(Queue& queue) {
    int choice, value;
    do {
        cout << "=========================================" << endl;
        cout << "             Queue Operations            " << endl;
        cout << "=========================================" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print Queue" << endl;
        cout << "4. Check Size" << endl;
        cout << "5. Clear Queue" << endl;
        cout << "6. Go Back" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.printQueue();
                break;
            case 4:
                cout << "Current size: " << queue.size() << endl;
                break;
            case 5:
                queue.clear();
                cout << "Queue cleared." << endl;
                break;
            case 6:
                cout << "Going back to main menu..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 6);
}

int main() {
    Stack stack;
    Queue queue;
    int mainChoice;

    do {
        system("clear");
        displayMenu();
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                stackMenu(stack);
                break;
            case 2:
                queueMenu(queue);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (mainChoice != 3);

    return 0;
}