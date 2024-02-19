#ifndef SORTING_H
#define SORTING_H
#include <cmath>
#include <chrono>
#define maxTime 300000
using namespace std::chrono;


void testArr(int* arr, int* arr1, int n){
    for (int i = 0; i < n; i++)
        arr[i] = arr1[i];
}

void zeroArr(int* arr, int n){
    for(int i = 0; i < n; i++)
        arr[i] = 0;
}

void bubbleSort(int *arr, int n){
    auto start_time = high_resolution_clock::now();
    bool f;
    for(int i = 0; i < n-1; ++i){
       auto stop_time = high_resolution_clock::now();
       auto duration = duration_cast<milliseconds>(stop_time - start_time);
            if (duration.count() >= maxTime)
                return;
       f = false;
       for(int j = 0; j < n-1-i; ++j){
           if(arr[j]>arr[j+1]){
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
               f = true;
           }
       }
       if(!f)
           break;
       }
}


bool compare(int a, int b){
    return a<b;
}
void selectionSort(int* arr, int n){
    auto start_time = high_resolution_clock::now();
    for(int i = 0; i < n; ++i)
    {
        auto stop_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop_time - start_time);
             if (duration.count() >= maxTime)
                 return;
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
            int tmp = arr[i];
            arr[i] = arr[swap_index];
            arr[swap_index] = tmp;
        }
    }
}

void shellSort(int* arr, int n){
    auto start_time = high_resolution_clock::now();
    int temp = 0;
    for (int h = n/2; h > 0; h/=2){
        for(int i = h; i < n; i += h){
            auto stop_time = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop_time - start_time);
                 if (duration.count() >= maxTime)
                     return;
            for(int j = i-h; j>=0 && arr[j]>arr[j+h]; j-=h){
                temp = arr[j];
                arr[j] = arr[j+h];
                arr[j + h] = temp;
                }
    }
    }
}

int getPivot(int* arr, int start, int end){
    int pivot = arr[end];
    int temp = 0;
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

void quickSort(int* arr, int start, int end, int n){
    if (start >= end){
        return;
    }

    int pivot = getPivot(arr, start, end);

    quickSort(arr, start, pivot - 1, n);

    quickSort(arr, pivot + 1, end, n);

}

void mergeSort(int* arr, int n, int leftIndex, int rightIndex){
    if (leftIndex >= rightIndex)
        return;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

    mergeSort(arr, n, leftIndex, middleIndex);
    mergeSort(arr, n, middleIndex + 1, rightIndex);

    int ll = middleIndex - leftIndex + 1;
    int rl = rightIndex - middleIndex;
    int* leftArray = new int[ll];
    int* rightArray = new int[rl];

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
}

/*void countingSort(int* arr, int n){

    int arr1[n+1];
    for (int i = 1; i < n+1; i++) {
        arr1[i] = 0;
    }

    int x = arr[0];

    for (int i = 1; i < n; i++) {
      if (arr[i] > x)
        x = arr[i];
    }

    int count_arr[x+1];
    for (int i = 1; i < x+1; i++) {
        count_arr[i] = 0;
    }

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
    }

}*/
void countingSort(int* arr, int n){

    int arr2[n+1];
    for (int i = 0; i < n; i++) {
      arr2[i] = 0;
    }

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
      arr2[count_arr[arr[i]] - 1] = arr[i];
      count_arr[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
      arr[i] = arr2[i];
    }
}
#endif // SORTING_H
