#include "mainwindow.h"
#include "bubble.h"
#include "ui_mainwindow.h"

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

Bubble a;
int* arr = new int[N];

Bubble b("Egg", 3.75);
Bubble c("Apple", 4.25);
Bubble d("Pear", 5.12);
Bubble e("Milk", 4.87);
Bubble f("Bread", 2.75);
Bubble g("Water", 3.25);
Bubble h("Meat", 6.78);
Bubble i("Chicken", 4.92);
Bubble j("Rice", 1.93);

Bubble* array = new Bubble[10]{b, c, d, e, f, g, h, i, j};

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_3->setText("");
    arr = a.generate();
    a.print(arr, ui->textEdit);

}


void MainWindow::on_pushButton_2_clicked()
{

    a.bubbleSort(arr, N, ui->textEdit_2);
    a.print(arr, ui->textEdit_3);
}


void MainWindow::on_pushButton_3_clicked()
{
    for(int i = 0; i < 9; ++i){
        array->printItems(array[i], ui->textEdit_4);
    }

}


void MainWindow::on_pushButton_4_clicked()
{
    array = array->deleteItems(array);
    for(int i = 0; i < 9; ++i){
        array->printItems(array[i], ui->textEdit_5);
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    array->bubbleSort(array, 9);
    for(int i = 0; i < 9; ++i){
        array->printItems(array[i], ui->textEdit_6);
    }
}

