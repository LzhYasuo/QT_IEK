#ifndef _SMALL_WINDOW_H_
#define _SMALL_WINDOW_H_


#include "BaseWidget.h"

class SmallWindow : public BaseWidget
{
    Q_OBJECT
public:
    SmallWindow(QWidget* parent = nullptr);
    ~SmallWindow();

private:
    QWidget* Init();
    QWidget* InitWindowModel(int index);


protected:
    QPushButton* GetLeftButton(QString);
    QLabel* GetLabel(QString name);
};

#endif //_SMALL_WINDOW_H_
