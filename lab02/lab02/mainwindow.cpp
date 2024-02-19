#include "mainwindow.h"
#include "Selection.h"
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
    function(arr, n);

    selectionSort(arr, ui->textEdit_2, n);

    print(arr, ui->textEdit_3, n);
}

