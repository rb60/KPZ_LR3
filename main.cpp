#include "mainwindow.h"
#include <QApplication>
#include "ISingeltone.h"
#include <QLibrary>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLibrary lib("LR3");
    typedef IDocumentSaver* (*get_Saver_Instatnce)();
    typedef ILoger* (*get_Loger_Instatnce)();
    typedef IDbManager* (*get_DB_Instatnce)();

    get_Saver_Instatnce getSaver = (get_Saver_Instatnce)lib.resolve("getDocumentSaver");
    get_Loger_Instatnce getLoger = (get_Loger_Instatnce)lib.resolve("getLoger");
    get_DB_Instatnce getDB = (get_DB_Instatnce)lib.resolve("getDbManager");

    IDocumentSaver* saver = getSaver();
    saver->setPath("log.txt");

    ILoger* loger = getLoger();
    loger->setDocumentSaver(saver);

    IDbManager* DB = getDB();
    DB->setLoger(loger);


    MainWindow w;
    w.show();

    const int resultCode = app.exec();

    saver->destroy();
    loger->destroy();
    DB->destroy();

    return resultCode;
}
