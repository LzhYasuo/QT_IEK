#ifndef _TYPE_WINDOW_H_
#define _TYPE_WINDOW_H_

#include <QWidget>
#include "BaseWidget.h"

enum TypeWindowModel
{
    CHARTLINE,
    CHARTCURVE,
    CHARTBAR,
    CHARTBAR1,
    CHARTBAR2,
    CHARTBAR3,
    CHARTBAR4,
    CHARTBAR5
};

class TypeWindow : public BaseWidget
{
    Q_OBJECT
public:
    TypeWindow(QWidget* parent = nullptr);
    ~TypeWindow();

    QPushButton* GetLeftButton(QString name);

private:
    void Init();
    QWidget* InitWidget(TypeWindowModel);
};

#endif //_TYPE_WINDOW_H_
