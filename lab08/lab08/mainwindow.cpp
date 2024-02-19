#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stackList.h"

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


int size1 = 0;
StackList<int> SL;
int min1, max1;

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    size1 = ui->lineEdit_2->text().toInt();
    ui->tableWidget->setColumnCount(ui->lineEdit_2->text().toInt());
}


void MainWindow::on_pushButton_clicked()
{
    for(int i = 0; i < size1; i++){
        SL.push(ui->tableWidget->item(0, i)->text().toInt());
    }
    SL.print(ui->label_8);
}

//кількість елементів
void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setNum(SL.count());
}

//мінімальний та максимальний
void MainWindow::on_pushButton_3_clicked()
{
    StackList<int> S = SL;
    int n = 0;
    min1 = SL.top(), max1 = SL.top();
    while(!S.isEmpty()){
        n = S.pop();
        if(n < min1)
            min1 = n;
        if(n > max1)
            max1 = n;
    }
    ui->label_2->setText(QString::number(min1)+" та "+QString::number(max1));
}

//перед мінімальним та після максимального
void MainWindow::on_pushButton_5_clicked()
{
    StackList<int> S = SL;
    //min1 = 1;
    int bMin = 0, aMax = 0, n = 0;
    while(!S.isEmpty()){
        n = S.pop();
        if(n == min1)
            break;
        bMin = n;
    }
    S = SL;

    while(!S.isEmpty()){
        n = S.pop();
        if(n == max1){
            aMax = S.pop();
            break;}
    }

    ui->label_4->setText(QString::number(bMin) + " та "+QString::number(aMax));
}

//знайти позицію
void MainWindow::on_pushButton_6_clicked()
{
    StackList<int> S = SL;
    int pos = 0, num = ui->lineEdit->text().toInt(), n = 0;
    /*int pos = ui->lineEdit->text().toInt();
    int n = 0;
    for(int i = 0; i < pos; i++)
        n = S.pop();
     ui->label_6->setText(QString::number(n));*/
    while(!S.isEmpty()){
        n = S.pop();
        pos++;
        if(n == num)
            break;
    }
    ui->label_6->setText(QString::number(pos));
}

// 3 з початку та 2 з кінця
void MainWindow::on_pushButton_4_clicked()
{
    StackList<int> S = SL;
    int pos3 = 0, pos2 = 0;
    for(int i = 0; i < 3; i++)
        pos3 = S.pop();
    S = SL;
    for(int i = 0; i < SL.count()-1; i++)
        pos2 = S.pop();
    ui->label_3->setText(QString::number(pos3) + " та "+QString::number(pos2));
}

//об'єднати
void MainWindow::on_pushButton_7_clicked()
{
    StackList<int> S;
    StackList<int> S1 = SL;
    for(int i = 0; i < size1; i++){
        S.push(ui->tableWidget->item(0, i)->text().toInt());
    }
    for(int i = 0; i < SL.count(); i++)
        S.push(S1.pop());
    S.print(ui->label_11);
}

