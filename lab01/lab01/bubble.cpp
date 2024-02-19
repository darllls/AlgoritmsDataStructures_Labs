#include "bubble.h"
#include "QTextEdit"
Bubble::Bubble()
{
    array = new int[N];
    for(int i = 0; i < N; ++i){
        array[i] = rand() % 100;
    }

}

Bubble::Bubble(std::string n, float m){
    name = n;
    price = m;
}

void Bubble::print(int* arr, QTextEdit* edit){
    for(int i=0;i<N;i++){
        edit->setText(edit->toPlainText()+QString::number(arr[i])+" ");
    }
}

int* Bubble::generate(){
    int* arr = new int[N];
    for(int i = 0; i < N; ++i){
        arr[i] = rand() % 100;
    }
    return arr;
}

void Bubble::bubbleSort(int *arr, int n, QTextEdit* edit){
     bool f;
     for(int i = 0; i < n-1; ++i){
        f = false;
        for(int j = 0; j < n-1-i; ++j){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                f = true;
            }
        }
        if(!f){
            break;
        }
        edit->setText(edit->toPlainText()+"№"+(QString::number(i+1))+"\n");
        for(int m = 0; m < n; ++m){
            edit->setText(edit->toPlainText()+QString::number(arr[m])+" ");
        }
        edit->setText(edit->toPlainText()+"\n");
     }
}

void Bubble::bubbleSort(Bubble *arr, int n){
     bool f;
     for(int i = 0; i<n-1; ++i){
        f = false;
        for(int j=0;j<n-1-i; ++j){
            if(arr[j].name > arr[j+1].name){
                Bubble temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                f = true;
            }
        }
        if(!f){
            break;
        }
     }
}

void Bubble::printItems(Bubble obj, QTextEdit* edit){
    if(obj.price!=0)
        edit->setText(edit->toPlainText()+QString::fromStdString(obj.name)+" "+QString::number(obj.price)+"\n");
}

Bubble *Bubble::deleteItems(Bubble *arr){
    float sum = 0;
    float avg = 0;
    Bubble* newArr = new Bubble[9];
    for(int i = 0; i < 9; ++i){
        sum += arr[i].price;
    }
    avg = sum/9;

    for(int i = 0, j = 0; i < 9; ++i){
        if(arr[i].price > avg){
            ++j;
                newArr[j].name = arr[i].name;
                newArr[j].price = arr[i].price;

            }
        }
    return newArr;
}
