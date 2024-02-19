#ifndef MERGE_H
#define MERGE_H
#include "QTextEdit"

float Rand()
{

    //return (float) (rand() % ( 10000 - (-10000) + 1)+(-10000))/100 ;
    return (rand() % 200 - 99 );
}

void print(float* arr, QTextEdit* edit, int n){
    for(int i=0;i<n;i++){
        if(arr[i]!=0)
        edit->setText(edit->toPlainText()+QString::number((arr[i])) + " ");
    }
}

void function(float* arr, int n){
    for(int i = 0; i < n; ++i){
        if(arr[i] < 0){
            arr[i] = sin(arr[i]);
        }
    }
}

int i = 1;
void mergeSort(float* arr, QTextEdit* edit, int n, int leftIndex, int rightIndex){
    if (leftIndex >= rightIndex)
        return;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

    mergeSort(arr, edit, n, leftIndex, middleIndex);
    mergeSort(arr, edit, n, middleIndex + 1, rightIndex);

    int ll = middleIndex - leftIndex + 1;
    int rl = rightIndex - middleIndex;
    double* leftArray = new double[ll];
    double* rightArray = new double[rl];

    for (int i = 0; i < ll; i++)
        leftArray[i] = arr[leftIndex + i];

    for (int i = 0; i < rl; i++)
        rightArray[i] = arr[middleIndex + i + 1];

    for (int i = 0, j = 0, k = leftIndex; k <= rightIndex; k++){
        if ((i < ll) && (j >= rl || leftArray[i] < rightArray[j])){
            arr[k] = leftArray[i];
            i++;
        }
        else{
            arr[k] = rightArray[j];
            j++;
        }
    }


    edit->setText(edit->toPlainText()+"№"+(QString::number(i++))+"\n");
    for(int m = 0; m < n; ++m){
        edit->setText(edit->toPlainText()+QString::number(arr[m])+" ");
    }
    edit->setText(edit->toPlainText()+"\n");
}

#endif // MERGE_H
