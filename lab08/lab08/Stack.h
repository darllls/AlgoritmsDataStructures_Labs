#ifndef STACK_H
#define STACK_H
#include <cassert> // для assert
#include <iostream>
#include <QTableWidget>
#include <QLabel>
#include <iomanip> // для setw

template <typename T>
class Stack
{
private:
    T *stack;                      // указатель на стек
    const int size;                   // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека

public:
    Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
    Stack(const Stack<T> &);          // конструктор копирования
    ~Stack();                         // деструктор

    inline void push(const T & );     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека и вернуть его
    inline void printStack(QLabel *label);         // вывод стека на экран
    inline void setStack(QTableWidget *table);
    inline const T &Peek(int ) const; // n-й элемент от вершины стека
    inline int getStackSize() const;  // получить размер стека
    inline T *getPtr() const;         // получить указатель на стек
    inline int getTop() const;        // получить номер текущего элемента в стеке
};


// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) // инициализация константы
{
    stack = new T[size]; // выделить память под стек
    top = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
    size(otherStack.getStackSize()) // инициализация константы
{
    stack = new T[size]; // выделить память под новый стек
    top = otherStack.getTop();

    for(int i = 0; i < top; i++)
        stack[i] = otherStack.getPtr()[i];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete [] stack; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
    // проверяем размер стека
    assert(top < size); // номер текущего элемента должен быть меньше размера стека

    stack[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
    // проверяем размер стека
    assert(top > 0); // номер текущего элемента должен быть больше 0
    stack = new T[size];
    stack[--top]; // удаляем элемент из стека
}

// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
  //
  assert(nom <= top);

  return stack[top - nom]; // вернуть n-й элемент стека
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack(QLabel *label)
{
    for (int i = top - 1; i >= 0; i--)
        label->setText(stack[i]);
}

template <typename T>
inline void Stack<T>::setStack(QTableWidget *table)
{
    for(int i = 0; i < table->columnCount(); i++)
        stack->push(table->item(0, i)->text().toInt());
}
// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::getPtr() const
{
    return stack;
}

// получить номер текущего элемента в стеке
template <typename T>
inline int Stack<T>::getTop() const
{
    return top;
}
#endif // STACK_H
