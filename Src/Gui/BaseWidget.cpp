#include "BaseWidget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>


BaseWidget::BaseWidget(QWidget *parent)
    :QWidget (parent)
{

}

BaseWidget::~BaseWidget()
{

}

QPushButton *BaseWidget::InitButton(QString name, int width, int height, QString style)
{
    QPushButton* btn = new QPushButton();
    btn->setText(name);
    if(width != 0)
        btn->setFixedWidth(width);
    if(height)
        btn->setFixedHeight(height);
    btn->setStyleSheet(style);

    return btn;
}

QPushButton *BaseWidget::InitButton(QString name, int width, int height, QString icon, int iconWidth, int iconHeight, QString style)
{
    QPushButton* btn = new QPushButton();
    btn->setText(name);
    if(width != 0)
        btn->setFixedWidth(width);
    if(height)
        btn->setFixedHeight(height);
    btn->setIcon(QIcon(icon));
    btn->setIconSize(QSize(iconWidth,iconHeight));
    btn->setStyleSheet(style);

    return btn;
}

QLabel *BaseWidget::InitLabel(QString name, int width, int height, LabelPos pos, QString style)
{
    QLabel* lbl = new QLabel();
    lbl->setText(name);
    if(width != 0)
        lbl->setFixedWidth(width);
    else if(height != 0)
        lbl->setFixedHeight(height);
    if(pos == POSLEFT)
        lbl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    else if(pos == POSCENTER)
        lbl->setAlignment(Qt::AlignCenter);
    else if(pos == POSRIGHT)
        lbl->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    lbl->setStyleSheet(style);

    return lbl;
}

QHBoxLayout *BaseWidget::InitHLayout(int spcaeing, int left, int top, int right, int bottom)
{
    QHBoxLayout* mLayout = new QHBoxLayout();
    mLayout->setSpacing(spcaeing);
    mLayout->setContentsMargins(left,top,right,bottom);

    return mLayout;

}

QVBoxLayout *BaseWidget::InitVLayout(int spaceing, int left, int top, int right, int bottom)
{
    QVBoxLayout* mLayout = new QVBoxLayout();
    mLayout->setSpacing(spaceing);
    mLayout->setContentsMargins(left,top,right,bottom);

    return mLayout;
}
