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