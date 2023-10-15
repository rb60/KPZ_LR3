#ifndef ISINGELTONE_H
#define ISINGELTONE_H

class IDocumentSaver
{
public:
    virtual void writeData(char* data) = 0;
    virtual void setPath(char* path) = 0;
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void destroy() = 0;
};

class ILoger
{
public:
    virtual void log(char* text) = 0;
    virtual void setDocumentSaver(IDocumentSaver* saver) = 0;
    virtual void destroy() = 0;
};

class ICharPointer
{
public:
    virtual char* getData() = 0;
    virtual void destroy() = 0;
};

class IDbManager
{
public:
    virtual void executeSQL(char* query) = 0;
    virtual int getFieldsCount() = 0;
    virtual int getRowsCount() = 0;
    virtual ICharPointer* getValue(int row, int column) = 0;
    virtual void setLoger(ILoger* loger) = 0;
    virtual void destroy() = 0;
};




#endif // ISINGELTONE_H
