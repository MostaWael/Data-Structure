#include <iostream>
using namespace std;

int MAX_INT[1000],top=-1;
template<class t>
class stack {
public:
    void push(t&value) {
        if(top >= 999){
            cout << "Stack is full" << endl;
        }
        else
        {
            cin >> value;
            top++;
            MAX_INT[top] = value;
        }
    }
    void pop() {
        top--;
    }
    void isImpty() {
        if (top < 0) {
            cout << "Stack is empty\n";
        }
        else {
            cout << "Stack is not empty\n";
        }
    }

    void getTheTop() {
        cout << "The Top Element : "<<MAX_INT[top]<<endl<<endl;
    }
};

int main()
{
    stack<int> s;
    
    while (true)
    {
        int choice;
        cout << "1-push element\n";
        cout << "2-pop element\n";
        cout << "3-get the top element\n";
        cout << "4-Check if Empty Or not\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            s.push(value);
            cout << value << endl;
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.getTheTop();
            break;
        case 4:
            s.isImpty();
            break;
        default:
            cout << "wrong choice ):\n";
            break;
        }
    }
}

