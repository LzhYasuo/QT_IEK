#ifndef _CONTROL_DASH_BOARD_H_
#define _CONTROL_DASH_BOARD_H_

#include <QWidget>

class ControlDashBoard : public QWidget
{
    Q_OBJECT
public:
    ControlDashBoard(QWidget* parent = nullptr);
    ~ControlDashBoard();
protected:
    void paintEvent(QPaintEvent *event);
private:
    void DrawBackGround(QPainter*);

};

#endif //_CONTROL_DASH_BOARD_H_
