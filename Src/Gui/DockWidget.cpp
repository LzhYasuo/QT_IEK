#include "DockWidget.h"
#include <QDebug>
#include <QHBoxLayout>

DockWidgetTitle::DockWidgetTitle(QLabel *lbl,QWidget *parent)
    :QWidget (parent)
{
    QHBoxLayout* mLayout = new QHBoxLayout();
    mLayout->setSpacing(0);
    mLayout->setContentsMargins(0,0,0,0);
    mLayout->addWidget(lbl);
    this->setLayout(mLayout);
}

DockWidgetTitle::DockWidgetTitle(QString text, QWidget *parent)
{
    QHBoxLayout* mLayout = new QHBoxLayout();
    mLayout->setSpacing(0);
    mLayout->setContentsMargins(0,0,0,0);

    QLabel* lbl = new QLabel();
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setStyleSheet("background-color:rgb(41,43,77);"
                       "font : ""楷体"" 15pt;"
                       "color:rgb(240,240,240);");
    lbl->setText(text);
    lbl->setFixedHeight(30);
    mLayout->addWidget(lbl);
    this->setLayout(mLayout);
}

DockWidgetTitle::~DockWidgetTitle()
{

}

void DockWidgetTitle::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
}

void DockWidgetTitle::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
}

void DockWidgetTitle::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
}

DockWidget::DockWidget(QString text, QWidget *parent)
    :QDockWidget (parent)
{
    DockWidgetTitle* mTitle = new DockWidgetTitle(text);
    this->setTitleBarWidget(mTitle);

    DockWidgetList::Get()->Push(this);
}

DockWidget::DockWidget(QLabel *lbl, QWidget *parent)
    :QDockWidget (parent)
{
    DockWidgetTitle* mTitle = new DockWidgetTitle(lbl);
    this->setTitleBarWidget(mTitle);

    DockWidgetList::Get()->Push(this);
}

DockWidget::~DockWidget()
{

}

void DockWidget::SetDockWidget(QWidget *widget)
{
    this->setWidget(widget);
}

DockWidgetList *DockWidgetList::Get()
{
    static DockWidgetList cx;
    return &cx;
}

void DockWidgetList::Push(DockWidget *wid)
{
    _list.push_back(wid);
}

void DockWidgetList::DeleteAll()
{
    for(auto & i : _list)
    {
        i->deleteLater();
        i = nullptr;
    }
}

void DockWidgetList::HideAll()
{
    for(auto & i : _list)
    {
        i->hide();
    }
}

void DockWidgetList::HideIndex(int index)
{
    if(index > _list.size() - 1)
    {
        return;
    }
    _list.at(index)->hide();
}

void DockWidgetList::ShowAll()
{
    for(auto &i : _list)
    {
        i->show();
    }
}

void DockWidgetList::ShowIndex(int index)
{
    if(index > _list.size() - 1)
    {
        return;
    }
    _list.at(index)->show();
}

DockWidget *DockWidgetList::GetDockWidgetIndex(int index)
{
    DockWidget* dock = new DockWidget("11");
    if(index >= _list.size())
        return dock;
    DockWidget* widget = _list.at(index);
    ShowIndex(index);
    return widget;
}

DockWidgetList::DockWidgetList(QObject *obj)
    :QObject (obj)
{

}

DockWidgetList::~DockWidgetList()
{

}
