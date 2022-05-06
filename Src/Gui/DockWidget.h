#ifndef _DOCK_WIDGET_H_
#define _DOCK_WIDGET_H_

#include <QDockWidget>
#include <QLabel>

class DockWidgetTitle : public QWidget
{
    Q_OBJECT
public:
    DockWidgetTitle(QLabel* lbl = nullptr,QWidget* parent = nullptr);
    DockWidgetTitle(QString text = "",QWidget* parent = nullptr);
    ~DockWidgetTitle();

protected:
    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
private:
};

class DockWidget : public QDockWidget
{
    Q_OBJECT
public:
    DockWidget(QString text = "",QWidget* parent = nullptr);
    DockWidget(QLabel* lbl = nullptr,QWidget* parent = nullptr);
    ~DockWidget();

    void SetDockWidget(QWidget* widget);
//    void Remove();
};

class DockWidgetList : public QObject
{
    Q_OBJECT
public:
    static DockWidgetList* Get();

    void Push(DockWidget*);

    void DeleteAll();
    void HideAll();
    void HideIndex(int index);

    void ShowAll();
    void ShowIndex(int index);

    DockWidget* GetDockWidgetIndex(int);
private:
    QList<DockWidget*> _list;
private:
    DockWidgetList(QObject* obj = nullptr);
    ~DockWidgetList();
};



#endif //_DOCK_WIDGET_H_
