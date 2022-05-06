#include "MainWindow.h"
#include <QHBoxLayout>
#include "ModuleWidget.h"
#include <QMenu>
#include <QContextMenuEvent>

#include "DockWidget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    QWidget* mWidget = new QWidget();
//    QHBoxLayout* mLayout = new QHBoxLayout();
//    mLayout->setSpacing(0);
//    mLayout->setContentsMargins(0,0,0,0);


//    mWidget->setLayout(mLayout);

//    this->setCentralWidget(mWidget);

    this->setObjectName("MainWindow");
    this->setStyleSheet("#MainWindow{background-color:rgb(12,15,46);}");
    InitWidget();
    InitMenu();
}

MainWindow::~MainWindow()
{

}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    _menu->exec(QCursor::pos());
    event->accept();
}

void MainWindow::InitWidget()
{
    ModuleWidget* productionSumWidget = new ModuleWidget(PRODUCTIONSUM);
    ModuleWidget* planForTheMonthWidget = new ModuleWidget(PLANFORTHEMONTH);
    ModuleWidget* deviceMonitorRingWidget = new ModuleWidget(DEVICEMONITORING);
    ModuleWidget* MdloProgressWidget = new ModuleWidget(MOLDPROGRESS);
    ModuleWidget* LoadDistributionWidget = new ModuleWidget(LOADDISTRIBUTION);
    ModuleWidget* PassedTheInSpectionWidget = new ModuleWidget(PASSEDTHEINSPECTION);
    ModuleWidget* QualityManagementWidget = new ModuleWidget(QUALITYMANAGEMENT);
    ModuleWidget* MaterialManagementWidget = new ModuleWidget(MATERIALMANAGEMENT);
    ModuleWidget* VideoSurveillance = new ModuleWidget(VIDEOSURVEILLANCE);

    DockWidget* dockWidget1 = new DockWidget("随便吧");
    dockWidget1->SetDockWidget(productionSumWidget);
    dockWidget1->setObjectName("dockWidget1");

    DockWidget* dockWidget2 = new DockWidget("随便了");
    dockWidget2->SetDockWidget(planForTheMonthWidget);
    dockWidget2->setObjectName("dockWidget2");

    DockWidget* dockWidget3 = new DockWidget("随便吧");
    dockWidget3->SetDockWidget(deviceMonitorRingWidget);
    dockWidget3->setObjectName("dockWidget3");

    DockWidget* dockWidget4 = new DockWidget("随便了");
    dockWidget4->SetDockWidget(MdloProgressWidget);
    dockWidget4->setObjectName("dockWidget4");

    DockWidget* dockWidget5 = new DockWidget("随便吧");
    dockWidget5->SetDockWidget(LoadDistributionWidget);
    dockWidget5->setObjectName("dockWidget5");

    DockWidget* dockWidget6 = new DockWidget("随便了");
    dockWidget6->SetDockWidget(PassedTheInSpectionWidget);
    dockWidget6->setObjectName("dockWidget6");

    DockWidget* dockWidget7 = new DockWidget("随便吧");
    dockWidget7->SetDockWidget(QualityManagementWidget);
    dockWidget7->setObjectName("dockWidget7");

    DockWidget* dockWidget8 = new DockWidget("随便了");
    dockWidget8->SetDockWidget(MaterialManagementWidget);
    dockWidget8->setObjectName("dockWidget8");

    DockWidget* dockWidget9 = new DockWidget("随便了");
    dockWidget9->SetDockWidget(VideoSurveillance);
    dockWidget9->setObjectName("dockWidget9");

    this->addDockWidget(Qt::LeftDockWidgetArea,dockWidget1);
    this->splitDockWidget(dockWidget1,dockWidget2,Qt::Horizontal);
    this->splitDockWidget(dockWidget2,dockWidget3,Qt::Horizontal);
    this->splitDockWidget(dockWidget1,dockWidget4,Qt::Vertical);
    this->splitDockWidget(dockWidget2,dockWidget5,Qt::Vertical);
    this->splitDockWidget(dockWidget3,dockWidget6,Qt::Vertical);

}

void MainWindow::InitMenu()
{
    _menu = new QMenu();
    QAction* actionStyle = new QAction("样式");
    QAction* actionSaveLayout = new QAction("保存布局");
    QAction* actionLoadLayout = new QAction("使用布局");

    QMenu* StyleMenu = new QMenu();
    QAction* actionStyle1 = new QAction("样式1");
    QAction* actionStyle2 = new QAction("样式2");
    QAction* actionStyle3 = new QAction("样式3");
    QAction* actionStyle4 = new QAction("样式4");
    QAction* actionStyle5 = new QAction("样式5");
    QAction* actionStyle6 = new QAction("样式6");
    QAction* actionStyle7 = new QAction("样式7");
    StyleMenu->addAction(actionStyle1);
    StyleMenu->addAction(actionStyle2);
    StyleMenu->addAction(actionStyle3);
    StyleMenu->addAction(actionStyle4);
    StyleMenu->addAction(actionStyle5);
    StyleMenu->addAction(actionStyle6);
    StyleMenu->addAction(actionStyle7);
    actionStyle->setMenu(StyleMenu);

    _menu->addAction(actionStyle);
    _menu->addAction(actionSaveLayout);
    _menu->addAction(actionLoadLayout);

    this->connect(actionStyle1,&QAction::triggered,this,[=](){
        DockWidgetList::Get()->HideAll();
        this->addDockWidget(Qt::LeftDockWidgetArea,DockWidgetList::Get()->GetDockWidgetIndex(0));
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(1),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(1),DockWidgetList::Get()->GetDockWidgetIndex(2),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(3),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(1),DockWidgetList::Get()->GetDockWidgetIndex(4),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(2),DockWidgetList::Get()->GetDockWidgetIndex(5),Qt::Vertical);
    });
    this->connect(actionStyle2,&QAction::triggered,this,[=](){
        DockWidgetList::Get()->HideAll();
        this->addDockWidget(Qt::LeftDockWidgetArea,DockWidgetList::Get()->GetDockWidgetIndex(1));
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(1),DockWidgetList::Get()->GetDockWidgetIndex(5),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(5),DockWidgetList::Get()->GetDockWidgetIndex(6),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(1),DockWidgetList::Get()->GetDockWidgetIndex(7),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(5),DockWidgetList::Get()->GetDockWidgetIndex(4),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(6),DockWidgetList::Get()->GetDockWidgetIndex(8),Qt::Vertical);
    });
    this->connect(actionStyle3,&QAction::triggered,this,[=](){
        DockWidgetList::Get()->HideAll();
        this->addDockWidget(Qt::LeftDockWidgetArea,DockWidgetList::Get()->GetDockWidgetIndex(0));
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(2),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(2),DockWidgetList::Get()->GetDockWidgetIndex(5),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(3),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(2),DockWidgetList::Get()->GetDockWidgetIndex(6),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(5),DockWidgetList::Get()->GetDockWidgetIndex(7),Qt::Vertical);
    });
    this->connect(actionStyle4,&QAction::triggered,this,[=](){
        DockWidgetList::Get()->HideAll();
        this->addDockWidget(Qt::LeftDockWidgetArea,DockWidgetList::Get()->GetDockWidgetIndex(0));
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(2),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(2),DockWidgetList::Get()->GetDockWidgetIndex(4),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(3),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(2),DockWidgetList::Get()->GetDockWidgetIndex(5),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(4),DockWidgetList::Get()->GetDockWidgetIndex(7),Qt::Vertical);
    });
    this->connect(actionStyle5,&QAction::triggered,this,[=](){
        DockWidgetList::Get()->HideAll();
        this->addDockWidget(Qt::LeftDockWidgetArea,DockWidgetList::Get()->GetDockWidgetIndex(0));
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(2),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(2),DockWidgetList::Get()->GetDockWidgetIndex(3),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(4),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(2),DockWidgetList::Get()->GetDockWidgetIndex(5),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(3),DockWidgetList::Get()->GetDockWidgetIndex(6),Qt::Vertical);
    });
    this->connect(actionStyle6,&QAction::triggered,this,[=](){
        DockWidgetList::Get()->HideAll();
        this->addDockWidget(Qt::LeftDockWidgetArea,DockWidgetList::Get()->GetDockWidgetIndex(0));
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(1),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(1),DockWidgetList::Get()->GetDockWidgetIndex(2),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(3),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(1),DockWidgetList::Get()->GetDockWidgetIndex(4),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(2),DockWidgetList::Get()->GetDockWidgetIndex(5),Qt::Vertical);
    });
    this->connect(actionStyle7,&QAction::triggered,this,[=](){
        DockWidgetList::Get()->HideAll();
        this->addDockWidget(Qt::LeftDockWidgetArea,DockWidgetList::Get()->GetDockWidgetIndex(0));
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(3),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(3),DockWidgetList::Get()->GetDockWidgetIndex(4),Qt::Horizontal);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(0),DockWidgetList::Get()->GetDockWidgetIndex(5),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(3),DockWidgetList::Get()->GetDockWidgetIndex(6),Qt::Vertical);
        this->splitDockWidget(DockWidgetList::Get()->GetDockWidgetIndex(4),DockWidgetList::Get()->GetDockWidgetIndex(7),Qt::Vertical);
    });
    this->connect(actionSaveLayout,&QAction::triggered,this,[=](){
        SaveLayout();
    });
    this->connect(actionLoadLayout,&QAction::triggered,this,[=](){
        LoadLayout();
    });
}


void MainWindow::SaveLayout()
{
    const QString fileName = QDir::currentPath() + "/Layout.txt";
    qDebug() << fileName;
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        QString msg = tr("Failed to open %1\n%2")
                        .arg(fileName)
                        .arg(file.errorString());
        QMessageBox::warning(nullptr, tr("Error"), msg);
        return;
    }


    QByteArray geo_data = saveGeometry();
    QByteArray layout_data = saveState();


    bool ok = file.putChar((uchar)geo_data.size());
    if (ok)
        ok = file.write(geo_data) == geo_data.size();
    if (ok)
        ok = file.write(layout_data) == layout_data.size();


    if (!ok) {
        QString msg = tr("Error writing to %1\n%2")
                        .arg(fileName)
                        .arg(file.errorString());
        QMessageBox::warning(this, tr("Error"), msg);
        return;
    }
}

void MainWindow::LoadLayout()
{
//    QString fileName
//        = QFileDialog::getOpenFileName(this, tr("Load layout"));
    const QString fileName = QDir::currentPath() + "/Layout.txt";
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
        QString msg = tr("Failed to open %1\n%2")
                        .arg(fileName)
                        .arg(file.errorString());
        QMessageBox::warning(this, tr("Error"), msg);
        return;
    }


    uchar geo_size;
    QByteArray geo_data;
    QByteArray layout_data;


    bool ok = file.getChar((char*)&geo_size);
    if (ok) {
        geo_data = file.read(geo_size);
        ok = geo_data.size() == geo_size;
    }
    if (ok) {
        layout_data = file.readAll();
        ok = layout_data.size() > 0;
    }


    if (ok)
        ok = restoreGeometry(geo_data);
    if (ok)
        ok = restoreState(layout_data);


    if (!ok) {
        QString msg = tr("Error reading %1")
                        .arg(fileName);
        QMessageBox::warning(this, tr("Error"), msg);
        return;
    }
}
