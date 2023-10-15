#ifndef DBVIEWER_H
#define DBVIEWER_H

#include <QWidget>
#include "ui_dbviwer.h"

class DBViewer : public QWidget
{
    Q_OBJECT
public:
    explicit DBViewer(QWidget *parent = nullptr);
private:
    Ui::Form ui;

signals:

public slots:
    void executeSQL();
};

#endif // DBVIEWER_H
