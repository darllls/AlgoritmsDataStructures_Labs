#ifndef SHELL_H
#define SHELL_H
#include "qtextedit.h"
#include <cstdlib>

float Rand()
{
    return (float) (rand() % ( 10000 - (-10000) + 1)+(-10000))/100 ;
}

void print(float** arr, QTextEdit* edit, int n){
    for(int i=0;i<n;i++){
        for(int j = 0; j < n; ++j){
        edit->setText(edit->toPlainText()+QString::number((arr[i][j])) + "  ");
        }
        edit->setText(edit->toPlainText()+ "\n");
    }
}

void shellSort(float** arr,QTextEdit* edit, int n){
    float* temp = 0;
    int l = 0;
    for (int h = n/2; h > 0; h/=2){
        for(int i = h; i < n; i += h){
            for(int j = i-h; j>=0 && arr[j][0]>arr[j+h][0]; j-=h){
                temp = arr[j];
                arr[j] = arr[j+h];
                arr[j + h] = temp;
                }

             edit->setText(edit->toPlainText()+"№"+(QString::number(l+++1))+"\n");
             for(int m=0;m<n;m++){
                for(int k = 0; k < n; ++k){
                    edit->setText(edit->toPlainText()+QString::number((arr[m][k])) + "  ");
                    }
                    edit->setText(edit->toPlainText()+ "\n");
                }
              edit->setText(edit->toPlainText()+"\n");
              }

    }

}


#endif // SHELL_H
