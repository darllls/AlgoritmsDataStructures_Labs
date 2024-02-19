#ifndef COUNT_H
#define COUNT_H
#include <cmath>
#include "QTextEdit"

float Rand()
{
    //return (float) (rand() % ( 10000 - (-10000) + 1)+(-10000))/100 ;
    return rand() % 1000;
}

void print(int* arr, QTextEdit* edit, int n){
    for(int i=0;i<n;i++){
        //for(int j = 0; j < n; ++j){
        edit->setText(edit->toPlainText()+QString::number((arr[i])) + "  ");
        //}
        //edit->setText(edit->toPlainText()+ "\n");
    }
}

void function(float** arr, int n){
    float* min = new float [n];
    float temp;
    for(int i = 0; i < n; ++i){
        temp = 101;
        for(int j = 0; j < n; ++j){
            if(arr[i][j] < temp)
                temp = arr[i][j];
        }
        min[i] = temp;
     }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(arr[i][j] == min[i])
                arr[i][j] = log(fabs(arr[i][j]));
        }
     }
    delete[] min;
}


int i = 0;
void countingSort(int* arr, QTextEdit* edit, int n){

    int arr1[n+1];

    int x = arr[0];

    for (int i = 1; i < n; i++) {
      if (arr[i] > x)
        x = arr[i];
    }

    int count_arr[x+1];

    for (int i = 0; i <= x; ++i) {
      count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      count_arr[arr[i]]++;
    }

    for (int i = 1; i <= x; i++) {
      count_arr[i] += count_arr[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
      arr1[count_arr[arr[i]] - 1] = arr[i];
      count_arr[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
      arr[i] = arr1[i];
      edit->setText(edit->toPlainText()+"№"+(QString::number(i+1))+"\n");
      for(int m = 0; m < n; ++m){
          edit->setText(edit->toPlainText()+QString::number(arr[m])+" ");
      }
      edit->setText(edit->toPlainText()+"\n");
    }
}
#endif // COUNT_H

