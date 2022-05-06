#ifndef _BASE_WIDGET_H_
#define _BASE_WIDGET_H_

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class QLabel;


class BaseWidget : public QWidget
{
    Q_OBJECT
protected:
    enum LabelPos
    {
        POSLEFT,
        POSCENTER,
        POSRIGHT,
    };
public:
    BaseWidget(QWidget* parent = nullptr);
    ~BaseWidget();

protected:
    //名字 长 宽 样式表
    QPushButton* InitButton(QString name,int width,int height,QString style = "");
    //名字 长 宽 图标 图标大小 样式表
    QPushButton* InitButton(QString name,int width,int height,QString icon,int iconWidth,int iconHeight,QString style = "");
    //名字 长 宽 位置 (1左 2中 3右) 样式表
    QLabel* InitLabel(QString name,int width,int height,LabelPos pos,QString style = "");
    //间隔 左 上 右 下
    QHBoxLayout* InitHLayout(int spcaeing = 0,int left = 0,int top = 0,int right = 0,int bottom = 0);
    //间隔 左 上 右 下
    QVBoxLayout* InitVLayout(int spaceing = 0,int left = 0,int top = 0,int right = 0,int bottom = 0);

};


#endif //_BASE_WIDGET_H_
