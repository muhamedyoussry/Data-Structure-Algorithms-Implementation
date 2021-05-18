<h1 align = "center"> Stack </h2>

A stack is an ordered collection of items where the addition of new items and the removal of existing items always takes place at the same end using LIFO principle.

*LIFO: last in first out

<p align="center"> 
    <img src="https://cdn.programiz.com/sites/tutorial2program/files/stack.png">
</p>

--- 

<h2 align = "center"> Stack Operations </h2> 

- **Push**: Add an element to the top of a stack
- **Pop**: Remove an element from the top of a stack
- **Pop(&variable)**: Save the top element in a variable then remove the element from the top of a stack 
- **IsEmpty**: Check if the stack is empty
- **IsFull**: Check if the stack is full
- **Print**: Print all the elements of the stack
- **Peek**: Get the value of the top element without removing it

--- 

<h2 align = "center"> Stack Implementation in c++ </h2>

<a name="ArrayImplementation">

* Stack using Array Implementation ( [Stack](Stack.cpp) )

</a>

```c++
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

    bool IsFull()
    {
        return top + 1 >= MAX_SIZE;
    }
    
    void Push(T element) // adding an element to the top of a stack
    {
        if (IsFull()) // check if the stack is full
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
```
--- 

* Stack using Linked List (Pointer) Implementation ( [Linked Stack](LinkedStack.cpp) )

```c++
#include <iostream>
#include <string>

using namespace std;

template <class T> // generic data type

class linkedStack
{
private:
    struct node
    {
        T item;
        node *next;
    };

    node *top, *curr;

public:
    linkedStack()
    {
        top = NULL;
    }

    void Push(T element)
    {
        node *elementPtr = new node; // new node mean that you save place in memory for data value of type node
        if (elementPtr == NULL)      // to check right memory allocation
        {
            cout << "Linked stack push cannot allocate memory for new node" << endl;
        }
        elementPtr->item = element; // insert the new element value inside the node item
        elementPtr->next = top;     // make the next node points to the top
        top = elementPtr;           // change my stack top with the new position
    }

    bool IsEmpty()
    {
        return top == NULL;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Linked stack is empty on pop" << endl;
        }
        else
        {
            node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void Pop(T &stackTop)
    {
        if (IsEmpty())
        {
            cout << "Linked stack is empty on pop" << endl;
        }
        else
        {
            stackTop = top->item;
            node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void Peek(T &stackTop)
    {
        if (IsEmpty())
        {
            cout << "Linked stack is empty on pop" << endl;
        }
        else
        {
            stackTop = top->item;
            cout << stackTop << endl;
        }
    }

    void Print()
    {
        curr = top;
        while (curr != NULL)
        {
            cout << curr->item << " ";
            curr = curr->next;
        }
    }
};

int main()
{
    linkedStack<int> s;
    int x = 0;

    cout << s.IsEmpty() << endl;

    s.Push(10); // 10
    s.Push(20); // 20 10
    s.Push(30); //30 20 10
    s.Print();  // 30 20 10
    s.Pop();    // 20 10
    s.Print();  // 20 10
    cout << endl;
    s.Peek(x); // 20
}
```