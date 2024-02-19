#include "mainwindow.h"
#include "Quick.h"
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

float* arr;

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();


    int n = ui->spinBox->value();
    arr = new float[n];
    for(int i = 0; i < n; ++i){
        arr[i] = Rand();
    }
    print(arr, ui->textEdit, n);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    int n = ui->spinBox->value();
    //arr = deleteMode(arr, n);

    quickSort(arr, ui->textEdit_2, 0, n-1, n);

    print(arr, ui->textEdit_3, n);
}

