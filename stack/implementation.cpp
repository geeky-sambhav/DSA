#include <iostream>
using namespace std;
class stack
{
    public:
    int size;
    int top;
    int *arr;
    int data;
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack overflow";
        }}
        void pop()
        {
            if (top >= 0)
            {
                top--;
            }
            else
            {
                cout << "Stack underflow";
            }
        }
        int peek()
        {
            if (top >= 0 && top < size)
            {
                return arr[top];
            }
            else
            {
                cout << "Stack is empty";
                return -1;
            }
        }
        bool isEmpty()
        {
            if (top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
};
int main()
{
    stack test(5);
    test.push(10);
    test.push(20);
    test.push(30);
    test.push(40);
// cout<<test.peek()<<endl;
test.pop();
test.pop();
test.pop();
test.pop();
cout<<test.peek()<<endl;
cout<<test.isEmpty();

    return 0;
}