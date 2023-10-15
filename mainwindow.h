#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbviewer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    DBViewer* form1;
    DBViewer* form2;
    DBViewer* form3;
    Ui::MainWindow *ui;
public slots:
    void show1();
    void show2();
    void show3();
};
#endif // MAINWINDOW_H
