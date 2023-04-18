// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class arrayList {
    int* arr;
    int maxsize;
    int index;
public:
    arrayList(int s) {
        if (s < 0) {
            maxsize = 10;
        }
        else {
            maxsize = s;
        }
        index = 0;
        arr = new int[maxsize];
    }

    bool isEmpty() {
        return index==0;
    }

    bool isFull() {
        return index == maxsize;
    }
    int getSize() {
        return index;
    }
    void print() {
        for (size_t i = 0; i < index; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void inserAt(int pos, int element) {
        if (isFull()){
            cout << "Array is Full\n";
        }
        else {
            for (size_t i = index; i>pos ; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = element;
            index++;
        }
    
    }

    void InsertAtEnd(int element) {
        if (isFull()) {
            cout << "Array is Full\n";
        }
        else {
            arr[index] = element;
            index++;
        }
    }

    void eraseAt(int pos) {
        if (isEmpty()) {
            cout << "Array is Empty Already\n";
        }
        else {

            for (size_t i = pos; i < index; i++)
            {
                arr[i] = arr[i + 1];
            }
            
            index--;
        }
    }
    int search(int element)
    {
        for (size_t i = 0; i < index; i++)
        {
            if (arr[i] == element) {
                return i;
            }
            return -1;
        }
    }

    void insertNoDuplicate(int element)
    {
        if (search(element) == -1)
            InsertAtEnd(element);
        else
        {
            cout << "The Element is there...!" << endl;
        }
    }

    void updateAt(int pos, int element)
    {
        if (pos < 0 || pos >= index)
            cout << "Out Of Range" << endl;
        else
            arr[pos] = element;
    }

    int getElement(int pos) {
        if (pos < 0 || pos >= index)
            cout << "Out Of Range...!" << endl;
        else
            return arr[pos];
    }

    //Desconstructor:
        //sommething you want happend when 
        //the program stop execution
    ~arrayList()
    {
        delete[]arr;
    }
    void clear()
    {
        index = 0;
    }

};  
    

int main()
{
    arrayList al(6);
    for (int i = 0; i < 3; i++) {
        int elem;
        cout << "Insert Element : "; cin >> elem;
        al.InsertAtEnd(elem);
    }
    int element, pos;
    cout << "insert element at position : "; cin >> pos >> element;
    al.inserAt(pos, element);
    al.print();
}
