#include "ControlRoundProBar.h"
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QDebug>
#include <QPropertyAnimation>

ContorlRoundProBar::ContorlRoundProBar(QWidget* parent)
    :QWidget(parent)
{
    QTimer* mTimer = new QTimer(this);
    mTimer->setInterval(2000);
    this->connect(mTimer,&QTimer::timeout,this,[=](){
        int Angle = qrand() % 100;
        proportion = (double)Angle / 100.0;
        ChangeValue();
    });
    mTimer->start();
}

void ContorlRoundProBar::ChangeValue()
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "oldproprortion");
    pAnimation->setDuration(1000);
    pAnimation->setStartValue(oldproprortion);
    pAnimation->setEndValue(proportion);
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
//    qDebug() << oldproprortion;
    str = QString::number(proportion * 100) + "%";

    update();
}

void ContorlRoundProBar::SetOldproprortion(double d)
{
    oldproprortion = d;
    repaint();
}

double ContorlRoundProBar::GetOldproprortion()
{
    return oldproprortion;
}

ContorlRoundProBar::~ContorlRoundProBar()
{

}

void ContorlRoundProBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    DrawOotRound(&painter);
    DrawInRound(&painter);
    DrawOutRound1(&painter);
    DrawText(&painter);
}

void ContorlRoundProBar::DrawOotRound(QPainter* painter)
{
    painter->save();
    QPen pen;
    pen.setWidth(18);
    pen.setColor(QColor(233,248,248));
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);
    painter->drawEllipse(QRect(28,28,this->width() - 56,this->height() - 56));

    painter->restore();
}

void ContorlRoundProBar::DrawInRound(QPainter* painter)
{
    painter->save();
    QPen pen;
    pen.setWidth(18);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setColor(QColor(49, 177, 190));
    painter->setPen(pen);

    QRectF rectangle(28,28,this->width() - 56,this->height() - 56);
    //从90度开始，逆时针旋转
    int startAngle = 90 * 16;
    int spanAngle = oldproprortion * 360 * 16 * -1;
    painter->drawArc(rectangle,startAngle,spanAngle);

    painter->restore();
}

void ContorlRoundProBar::DrawOutRound1(QPainter* painter)
{
    //当bar宽度小于3时，便不再绘制装饰圆点
    painter->setPen(QColor(255,255,255));
    painter->setBrush(QColor(255,255,255));
    //区域为圆点绘制正方形区域
    painter->drawEllipse((28 + (this->width() - 56)) / 2 + 6,28 - 3,6,6);
}

void ContorlRoundProBar::DrawText(QPainter* painter)
{
    painter->save();
    //设置画笔
    painter->setPen(QPen(QColor(220,220,220),12));
    //设置字体
    painter->setFont(QFont("黑体",30));
    //画文字
    QPointF point(this->width() / 2 - 30, this->height() / 2 + 15);
    painter->drawText(point,str);
    painter->restore();
}
