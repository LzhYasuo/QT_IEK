#ifndef _PUB_FUNCTION_H_
#define _PUB_FUNCTION_H_

#include <QObject>

class Pub_Function : public QObject
{
    Q_OBJECT
private:
    Pub_Function(QObject* parent = nullptr);
    ~Pub_Function();

public:
    static Pub_Function* Get()
    {
        static Pub_Function cx;
        return &cx;
    }
    void LoadLayout();
    //读取布局
    void SaveLayout();
    //保存布局
};

#endif //_PUB_FUNCTION_H_
