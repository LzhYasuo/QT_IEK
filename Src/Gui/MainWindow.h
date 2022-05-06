#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QMenu;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void contextMenuEvent(QContextMenuEvent *event);

    void InitWidget();
    void InitMenu();

private:
    void SaveLayout();
    void LoadLayout();

private:
    QMenu* _menu;
};

#endif // MAINWINDOW_H
