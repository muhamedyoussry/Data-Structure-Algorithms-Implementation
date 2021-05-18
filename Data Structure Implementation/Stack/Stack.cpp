#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;
template <class T> // A template is a simple and yet very powerful tool in C++.
// The simple idea is to pass data type as a parameter so that we don’t need
// to write the same code for different data types. And our new type called T

class stack
{
private:
    int top;
    T item[MAX_SIZE];

public:
    stack()
    {
        top = -1; // make initial value to the top
    }

    bool IsEmpty() // check if the stack is empty
    {
        return top < 0;
    }

    bool IsFull() // check if the stack is full
    {
        return top + 1 >= MAX_SIZE;
    }

    void Push(T element) // adding an element to the top of a stack
    {
        if (IsFull())
        {
            cout << "Stack full on push" << endl;
        }
        else
        {
            top++;
            item[top] = element;
        }
    }

    void Pop() // delete the last element of the stack
    {
        if (IsEmpty())
        {
            cout << "Stack Empty on pop" << endl;
        }
        else
        {
            top--;
        }
    }

    void Pop(T &element) // delete the last element of the stack with saving the deleted element in a variable
    {
        if (IsEmpty())
        {
            cout << "Stack Empty on pop" << endl;
        }
        else
        {
            element = item[top]; // call by reference
            top--;
        }
    }

    void Peek(T &stackTop) // delete the last element of the stack with saving the deleted element in a variable
    {
        if (IsEmpty())
        {
            cout << "Stack Empty on pop" << endl;
        }
        else
        {
            stackTop = item[top]; // call by reference
            cout << stackTop << endl;
        }
    }
    void Print() // print all the element of the stack
    {
        cout << "[";
        for (int i = top; i >= 0; i--)
        {
            cout << item[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    stack<int> s;
    s.Push(5);                // 5
    s.Push(10);               // 10 5
    s.Push(20);               // 20 10 5
    s.Pop();                  // 10 5
    s.Push(40);               // 40 10 5
    s.Print();                // 40 10 5
    int y = 0;                // to make call be refernece
    s.Peek(y);                // 40
    bool empty = s.IsEmpty(); // faslse
    cout << empty << endl;    // 0
}