#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorting.h"
#include <string>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int count = 1024;
    for(int i = 0; i<7; i++){
        int* arr = new int[count];
        for (int it = 0; it < count; it++)
            arr[it] = rand() % 1000;

        int* arr1 = new int[count];

        testArr(arr1, arr, count);
        auto start_time = high_resolution_clock::now();
        bubbleSort(arr1, count);
        auto stop_time = high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = stop_time - start_time;
        QString s = QStringLiteral("%1").arg(double(duration.count()));;
        if (duration.count() >= maxTime)
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem("inf"));
        else
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(s));
        zeroArr(arr1, count);

        testArr(arr1, arr, count);
        start_time = high_resolution_clock::now();
        selectionSort(arr1, count);
        stop_time = high_resolution_clock::now();
        duration = stop_time - start_time;
        s = QStringLiteral("%1").arg(double(duration.count()));;
        if (duration.count() >= maxTime)
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem("inf"));
        else
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(s));
        zeroArr(arr1, count);

        testArr(arr1, arr, count);
        start_time = high_resolution_clock::now();
        shellSort(arr1, count);
        stop_time = high_resolution_clock::now();
        duration = stop_time - start_time;
        s = QStringLiteral("%1").arg(double(duration.count()));;

        if (duration.count() >= maxTime)
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem("inf"));
        else
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(s));
        zeroArr(arr1, count);

        testArr(arr1, arr, count);
        start_time = high_resolution_clock::now();
        mergeSort(arr1, count, 0, count-1);
        stop_time = high_resolution_clock::now();
        duration = stop_time - start_time;
        s = QStringLiteral("%1").arg(double(duration.count()));;

        if (duration.count() >= maxTime)
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("inf"));
        else
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(s));
        zeroArr(arr1, count);

        testArr(arr1, arr, count);
        start_time = high_resolution_clock::now();
        quickSort(arr1, 0, count - 1, count);
        stop_time = high_resolution_clock::now();
        duration = stop_time - start_time;
        s = QStringLiteral("%1").arg(double(duration.count()));;
        if (duration.count() >= maxTime)
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem("inf"));
        else
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(s));
        zeroArr(arr1, count);

        testArr(arr1, arr, count);
        start_time = high_resolution_clock::now();
        countingSort(arr1, count);
        stop_time = high_resolution_clock::now();
        duration = stop_time - start_time;
        s = QStringLiteral("%1").arg(double(duration.count()));;
        if (duration.count() >= 120000)
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem("inf"));
        else
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem(s));
        zeroArr(arr1, count);

        count *= 4;
    }
}
