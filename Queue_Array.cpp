#include <iostream>
#include <cassert>
using namespace std;
const int MAX_LENGTH = 100;
template <class T>
class arrQueuType {
    int front;
    int rare;
    int count;
    T *arr;
    int maxSize;
public:
    arrQueuType(int sizee) {
        if (sizee < 0) 
            maxSize = 100;
        
        else
            maxSize = sizee;
        
        front = 0;
        arr = new int[maxSize];
        rare = maxSize - 1;
        count = 0;
    }
    bool isEmpty() {
       
        return count==0;
        
    }
    bool isFull() {

        return count == maxSize;
    }
    void enqueue(T num) {
        if (isFull()) {
            cout << "Queue Full Can't Enqueue" << endl;
        }
        else {
            rare = (rare + 1) % maxSize;
            arr[rare] = num;
            count++;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Empty Queue Can't Dequeue ...!" << endl;
        }
        else{
        front = (front + 1) % maxSize;
        --count;
        }
    }

    int getFront() {
        assert(!isEmpty());
        return arr[front];
    }
    int getRare() {
        assert(!isEmpty());
        return arr[rare];
    }
    int getSize() {
        return count;
    }
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty sorry ..." << endl;
        }
        else{
            for (int i = front; i != rare; i = (i + 1) % maxSize) {
                cout << arr[i]<<" ";
            }
            cout << arr[rare] << endl;
        }
    }
    int IndexElement(T element) {
        int pos = -1;
        if (!isEmpty()) {
            for (int i = front; i != rare; i = (i + 1) % maxSize) {
                if (arr[i] == element) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                if (arr[rare] == element) {
                    pos = rare;
                }
            }
        }
        else
        {
            cout << "Queue is Empty ..." << endl;
        }
        return pos;
    }
};

int main()
{
    arrQueuType<int> queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(20);
    queue.enqueue(20);
    queue.enqueue(20);
    queue.enqueue(20);
    queue.enqueue(50);
    if (queue.isEmpty()) {
        cout << "Empty Queue" << endl;
    }
    else {
        cout << "Not Empty yet" << endl;
    }
    queue.dequeue();
    queue.dequeue();
    
    if (queue.isEmpty()) {
        cout << "Empty Queue" << endl;
    }
    else {
        cout << "Not Empty yet" << endl;
    }
    queue.printQueue();
    cout << queue.IndexElement(20);
}
