#ifndef STAK_H
#define STAK_H
#include <QTableWidget>
#include <QLabel>

#define SIZE 10

class Stak
{
    int *arr;
    int top;
    int capacity;

public:
    Stak(int size = SIZE);
    ~Stak();

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};

Stak::Stak(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stak::~Stak() {
    delete[] arr;
}

void Stak::push(int x)
{
    if (isFull())
    {
        exit(EXIT_FAILURE);
    }

    arr[++top] = x;
}

int Stak::pop()
{
    if (isEmpty())
    {
        return 0;
        //exit(EXIT_FAILURE);
    }

    return arr[top--];
}

int Stak::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

int Stak::size() {
    return top + 1;
}

bool Stak::isEmpty() {
    return top == -1;
}

bool Stak::isFull() {
    return top == capacity - 1;
}


#endif // STAK_H
