#include <iostream>
using namespace std;
template<class t>
class stack{
    struct node {
        t item;
        node* next;
    };
    node* top;
    

public:
    stack() {
        top = NULL;
    }
    void push(t newItem) {
        
        //1-make a newNode
        node* newItemPtr = new node;
        if (newItemPtr == NULL) {
            cout << "Stack push cannot allocate memory";
        }
        else
        {
            //2-assign the value to the node
            newItemPtr->item = newItem;
            //3-make the newNode point to the last node
            newItemPtr->next = top;
            top = newItemPtr;
        }

    }

    void isEmpty() {
        return top == NULL;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty of pop :(\n";
        }
        else {
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void pop(t&topElement) {
        if (isEmpty()) {
            cout << "Stack is Empty of pop :(\n";
        }
        else {
            topElement = top->item;
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void getTheTopElement(t&topElement) {
        if (isEmpty()) {
            cout << "Stack is Empty :(\n";
        }
        else {
            topElement = top->item;
        }
    }

    void display() {
        cout << "[ ";
        while (top != NULL) {
            cout << top->item <<" ";
            top = top->next;
        }
        cout << "]\n";
    }
};
int main()
{

    stack<int>s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
 

    return 0;
}
