#include "ControlDashBoard.h"
#include <QPainter>

ControlDashBoard::ControlDashBoard(QWidget *parent)
    :QWidget (parent)
{

}

ControlDashBoard::~ControlDashBoard()
{

}

void ControlDashBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    DrawBackGround(&painter);
}

void ControlDashBoard::DrawBackGround(QPainter* painter)
{
    painter->save();




    painter->restore();
}
