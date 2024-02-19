#ifndef BUBBLE_H
#define BUBBLE_H
#include "QTextEdit"
#include "string"
#define len 20
#define N 400000

class Bubble
{
private:
    int *array;

    std::string name;
    float price;

    Bubble* arr;
public:
    Bubble();
    Bubble(std::string n, float m);

    void getItems();
    Bubble* deleteItems(Bubble* arr);
    void printItems(Bubble obj, QTextEdit* edit);

    void print(int* arr, QTextEdit* edit);
    int* generate();
    void bubbleSort(int* arr,int n,QTextEdit* edit);
    void bubbleSort(Bubble* arr,int n);
};

#endif // BUBBLE_H
