#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form1 = new DBViewer(nullptr);
    form2 = new DBViewer(nullptr);
    form3 = new DBViewer(nullptr);

    connect(ui->pushButton1, SIGNAL(clicked()), SLOT(show1()));
    connect(ui->pushButton2, SIGNAL(clicked()), SLOT(show2()));
    connect(ui->pushButton3, SIGNAL(clicked()), SLOT(show3()));
}


void MainWindow::show1()
{
    form1->show();
}

void MainWindow::show2()
{
    form2->show();
}

void MainWindow::show3()
{
    form3->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete form1;
    delete form2;
    delete form3;
}

