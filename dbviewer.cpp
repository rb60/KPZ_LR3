#include "dbviewer.h"
#include "ISingeltone.h"
#include <QLibrary>


DBViewer::DBViewer(QWidget *parent)
    : QWidget{parent}
{
    ui.setupUi(this);

    connect(ui.pushButton, SIGNAL(clicked()), SLOT(executeSQL()));
}


void DBViewer::executeSQL()
{
    QLibrary lib("LR3");
    typedef IDbManager* (*get_DB_Instatnce)();
    get_DB_Instatnce getDB = (get_DB_Instatnce)lib.resolve("getDbManager");

    if(getDB)
    {
        IDbManager* DB = getDB();
        DB->executeSQL(ui.lineEdit->text().toLocal8Bit().data());
        ui.tableWidget->setColumnCount(DB->getFieldsCount());
        ui.tableWidget->setRowCount(DB->getRowsCount());
        for(int i = 0; i < DB->getRowsCount(); i++)
        {
            for (int j = 0; j < DB->getFieldsCount(); ++j)
            {
                ICharPointer* value = DB->getValue(i,j);
                ui.tableWidget->setItem(i,j, new QTableWidgetItem(value->getData()));
                value->destroy();
            }
        }
    }
}
