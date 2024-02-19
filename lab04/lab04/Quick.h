#ifndef QUICK_H
#define QUICK_H
#include "QTextEdit"
#include <cmath>

float Rand()
{
    return (float) (rand() % ( 10000 - (-10000) + 1)+(-10000))/100 ;
}

void print(float* arr, QTextEdit* edit, int n){
    for(int i=0;i<n;i++){
        if(arr[i]!=0)
        edit->setText(edit->toPlainText()+QString::number((arr[i])) + " ");
    }
}

float* deleteMode(float* arr, int n){
    float mode = arr[0], cmax = 0, rmax = 0;
    for (int i = 0; i < n; i++) {
        if (cmax > rmax) {
            rmax = cmax;
            mode = arr[i - 1];
         }
         cmax = 0;
         for (int j = i; j < n; j++)
            if (arr[j] == arr[i])
                cmax++;
        }
    float* newArr = new float[n];

    for(int i = 0, j = 0; i < n; ++i){
        if(arr[i] != mode){
            ++j;
            newArr[j] = arr[i];
            }
        else{++j; newArr[j] = 0;}
    }

    return newArr;
}

/*float* function(float* arr, int n){


    float mode = arr[0], cmax = 0, rmax = 0;
        for (int i = 0; i < n; i++) {
            if (cmax > rmax) {
                rmax = cmax;
                mode = arr[i - 1];
            }
            cmax = 0;
            for (int j = i; j < n; j++)
               if (arr[j] == arr[i])
                  cmax++;
        }
    int m = n - rmax;
    float* newArr = new float[m];

    for(int i = 0, j = 0; i < m; ++i){
        if(arr[i] != mode){
            ++j;
                newArr[j] = arr[i];
            }
        }

    return newArr;
}*/


int getPivot(float* arr, int start, int end){
    int pivot = arr[end];
    float temp = 0;
    int pIndex = start;

    for (int i = start; i < end; i++){
        if (arr[i] <= pivot){
            temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;

            pIndex++;
        }

    }

    temp = arr[pIndex];
    arr[pIndex] = arr[end];
    arr[end] = temp;

    return pIndex;
}

int i1 = 0;

void quickSort(float* arr, QTextEdit* edit, int start, int end, int n){
    if (start >= end){
        return;
    }

    edit->setText(edit->toPlainText()+"№"+(QString::number(i1+1))+"\n");
    i1++;
    for(int m = 0; m < n; ++m){
        if(arr[m]!=0){
        edit->setText(edit->toPlainText()+QString::number(arr[m])+" ");}
    }
    edit->setText(edit->toPlainText()+"\n");

    int pivot = getPivot(arr, start, end);

    quickSort(arr, edit, start, pivot - 1, n);

    quickSort(arr, edit, pivot + 1, end, n);

}


#endif // QUICK_H
