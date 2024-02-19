#ifndef STACKLIST_H
#define STACKLIST_H
#include "qlabel.h"
#include <QMessageBox>
#include <iostream>
using namespace std;

template <typename T>
struct NodeStack
{
  T item;
  NodeStack<T>* next;
};


template <typename T>
class StackList
{
private:
  NodeStack<T>* pTop;

public:
  StackList() { pTop = nullptr; }

  StackList(const StackList& SL)
  {
    NodeStack<T>* p;
    NodeStack<T>* p2;
    NodeStack<T>* p3;


    pTop = nullptr;
    p3 = nullptr;

    p = SL.pTop;
    while (p != nullptr)
    {
      p2 = new NodeStack<T>;
      p2->item = p->item;
      p2->next = nullptr;

      if (pTop == nullptr)
      {
        pTop = p2;
        p3 = p2;
      }
      else
      {
        p3->next = p2;
        p3 = p3->next;
      }

      p = p->next;
    }
  }

  void push(T item)
  {
    NodeStack<T>* p;

    p = new NodeStack<T>;
    p->item = item;
    p->next = pTop;

    pTop = p;
  }

  int count()
  {
    if (pTop == nullptr)
      return 0;
    else
    {
      NodeStack<T>* p = pTop;
      int count = 0;

      while (p != nullptr)
      {
        count++;
        p = p->next;

      }
      return count;
    }
  }

  bool isEmpty(){
      if(pTop == nullptr)
          return 1;
      else return 0;
  }

  void empty()
  {
    NodeStack<T>* p;
    NodeStack<T>* p2;

    p = pTop;

    while (p != nullptr)
    {
      p2 = p;
      p = p->next;
      delete p2;
    }
    pTop = nullptr;
  }

  StackList<T>& operator=(const StackList<T>& LS)
  {
    if (pTop != nullptr) empty();

    NodeStack<T>* p;
    NodeStack<T>* p2;
    NodeStack<T>* p3;

    pTop = nullptr;
    p3 = nullptr;

    p = LS.pTop;
    while (p != nullptr)
    {
      p2 = new NodeStack<T>;
      p2->item = p->item;
      p2->next = nullptr;

      if (pTop == nullptr)
      {
        pTop = p2;
        p3 = p2;
      }
      else
      {
        p3->next = p2;
        p3 = p3->next;
      }
      p = p->next;
    }
    return *this;
  }


  void print(QLabel* label)
  {
    label->clear();
    if (pTop == nullptr)
      label->setText("Stack is empty!");
    else
    {
      NodeStack<T>* p;
      p = pTop;
      while (p != nullptr)
      {

        label->setText(label->text()+"<-"+QString::number(p->item));
        p = p->next;
      }
      cout << endl;
    }
  }

  ~StackList()
  {
    empty();
  }

  T pop()
  {
    if (pTop == nullptr)
      return 0;

    NodeStack<T>* p2;
    T item;
    item = pTop->item;

    p2 = pTop;
    pTop = pTop->next;

    delete p2;

    return item;
  }

  T top()
  {
      if (pTop == nullptr)
        return 0;
      return pTop->item;
  }
};

#endif // STACKLIST_H
