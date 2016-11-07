#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    firstNum.clear();
    secondNum.clear();
    opsflag = 0;

    flag = false;
    buttonGroup = new QButtonGroup();
    buttonGroup->addButton(ui->n0, 0);
    buttonGroup->addButton(ui->n1, 1);
    buttonGroup->addButton(ui->n2, 2);
    buttonGroup->addButton(ui->n3, 3);
    buttonGroup->addButton(ui->n4, 4);
    buttonGroup->addButton(ui->n5, 5);
    buttonGroup->addButton(ui->n6, 6);
    buttonGroup->addButton(ui->n7, 7);
    buttonGroup->addButton(ui->n8, 8);
    buttonGroup->addButton(ui->n9, 9);

    buttonGroup->addButton(ui->clear, 10);
    buttonGroup->addButton(ui->add, 11);
    buttonGroup->addButton(ui->sub, 12);
    buttonGroup->addButton(ui->div, 13);
    buttonGroup->addButton(ui->multiply, 14);
    buttonGroup->addButton(ui->equal, 15);

    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(buttonGroup_handler(int)));
}


void MainWindow::getdata(int num)
{

    if (flag == false)
    {
        ui->lineEdit->setText(firstNum.append(QString::number(num)));
    }
    else
    {

        ui->lineEdit->setText(secondNum.append(QString::number(num)));
    }
}



void MainWindow::buttonGroup_handler(int num)
{
    int result;
    switch (num) {

        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            getdata(num);
            break;
        case 10:
            firstNum.clear();
            secondNum.clear();
            flag = false;
            opsflag = 0;
            result = 0;
            ui->lineEdit->clear();
            break;
        case 11:
            flag = true;
            opsflag = 1;
            break;
        case 12:
            flag = true;
            opsflag = 2;
            break;
        case 13:
            flag = true;
            opsflag = 3;
            break;
        case 14:
            flag = true;
            opsflag = 4;
            break;
        case 15:
            switch (opsflag)
            {

                case 1:
                    result = firstNum.toInt() + secondNum.toInt();
                    ui->lineEdit->setText(QString::number(result));
                    break;
                case 2:
                    result = firstNum.toInt() - secondNum.toInt();
                    ui->lineEdit->setText(QString::number(result));
                    break;
                case 3:
                    result = firstNum.toInt() / secondNum.toInt();
                    ui->lineEdit->setText(QString::number(result));
                    break;
                case 4:
                    result = firstNum.toInt() * secondNum.toInt();
                    ui->lineEdit->setText(QString::number(result));
                    break;
            }

        default:
            break;
    }
}


MainWindow::~MainWindow()
{
    delete buttonGroup;
    delete ui;
}

