#ifndef SELECTION_H
#define SELECTION_H
#include "QTextEdit"
#include <cstdlib>

float Rand()
{
    return (float) (rand() % ( 10000 - (-10000) + 1)+(-10000))/100 ;
}

void print(float* arr, QTextEdit* edit, int n){
    for(int i=0;i<n;i++){
        edit->setText(edit->toPlainText()+QString::number((arr[i])) + " ");
    }
}

void function(float* arr, int n){
    for(int i = 0; i < n; ++i){
        if(i%2 == 0){
            arr[i] = sqrt(fabs(arr[i]-10));
        }
    }
}

bool compare(float a, float b){
    return a<b;
}

void selectionSort(float* arr, QTextEdit* edit, int n){
    for(int i = 0; i < n; ++i)
    {
        int swap_index = i;
        for(int j = i+1; j < n; ++j)
        {
            if(!compare(arr[swap_index], arr[j]))
            {
                swap_index = j;
            }
        }
        if(i != swap_index)
        {
            float tmp = arr[i];
            arr[i] = arr[swap_index];
            arr[swap_index] = tmp;
        }

        edit->setText(edit->toPlainText()+"№"+(QString::number(i+1))+"\n");
        for(int m = 0; m < n; ++m){
            edit->setText(edit->toPlainText()+QString::number(arr[m])+" ");
        }
        edit->setText(edit->toPlainText()+"\n");
    }
}
#endif // SELECTION_H

